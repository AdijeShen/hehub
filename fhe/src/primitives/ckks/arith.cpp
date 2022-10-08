#include "ckks.h"
#include "common/ntt.h"

namespace hehub {

const double EPS = std::pow(2.0, -50);

auto check_scaling_factor = [](const auto& in1, const auto& in2) {
    if (std::abs(in1.scaling_factor - in2.scaling_factor) > EPS) {
        throw std::invalid_argument("The scaling factors mismatch");
    }
};

CkksCt ckks::add(const CkksCt &ct1, const CkksCt &ct2) {
    check_scaling_factor(ct1, ct2);
    CkksCt sum_ct = ::hehub::add(ct1, ct2);
    sum_ct.scaling_factor = ct1.scaling_factor;
    return sum_ct;
}

CkksCt ckks::add_plain(const CkksCt &ct, const CkksPt &pt) {
    check_scaling_factor(ct, pt);
    auto pt_ntt(pt);
    ntt_negacyclic_inplace_lazy(pt_ntt);
    CkksCt sum_ct = ::hehub::add_plain_core(ct, pt_ntt);
    sum_ct.scaling_factor = ct.scaling_factor;
    return sum_ct;
}

CkksCt ckks::sub(const CkksCt &ct1, const CkksCt &ct2) {
    check_scaling_factor(ct1, ct2);
    CkksCt diff_ct = ::hehub::sub(ct1, ct2);
    diff_ct.scaling_factor = ct1.scaling_factor;
    return diff_ct;
}

CkksCt ckks::sub_plain(const CkksCt &ct, const CkksPt &pt) {
    check_scaling_factor(ct, pt);
    auto pt_ntt(pt);
    ntt_negacyclic_inplace_lazy(pt_ntt);
    CkksCt diff_ct = ::hehub::sub_plain_core(ct, pt_ntt);
    diff_ct.scaling_factor = ct.scaling_factor;
    return diff_ct;
}

CkksCt ckks::mult_plain(const CkksCt &ct, const CkksPt &pt) {
    auto pt_ntt(pt);
    ntt_negacyclic_inplace_lazy(pt_ntt);
    CkksCt prod_ct = ::hehub::mult_plain_core(ct, pt_ntt);
    prod_ct.scaling_factor = ct.scaling_factor * pt.scaling_factor;
    return prod_ct;
}

} // namespace hehub