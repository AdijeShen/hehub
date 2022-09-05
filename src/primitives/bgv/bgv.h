/**
 * @file bgv.h
 * @brief TODO
 *
 */

#pragma once
#include "primitives/rlwe.h"

namespace hehub {

struct bgv {
    /**
     * @brief TODO
     *
     * @param modulus
     * @param data
     * @param slot_count
     * @return RlwePt
     */
    static RlwePt simd_encode(const std::vector<u64> &data, const u64 modulus,
                              size_t slot_count = 0);

    /**
     * @brief TODO
     *
     * @param pt
     * @param data_size
     * @return std::vector<u64>
     */
    static std::vector<u64> simd_decode(RlwePt pt, size_t data_size = 0);

    /**
     * @brief TODO Get the rlwe sample lift noise object
     *
     * @param sk
     * @param poly_dim
     * @param lifting_factor
     * @return RlweCt
     */
    static RlweCt get_rlwe_sample_lift_noise(const RlweSk &sk,
                                             const PolyDimensions &poly_dim,
                                             const u64 lifting_factor);

    /**
     * @brief TODO
     *
     * @param pt
     * @param rlwe_sk
     * @param ct_moduli
     * @return RlweCt
     */
    static RlweCt encrypt(const RlwePt &pt, const RlweSk &rlwe_sk,
                          std::vector<u64> ct_moduli = std::vector<u64>{});

    /**
     * @brief TODO
     *
     * @param ct
     * @param rlwe_sk
     * @param pt_modulus
     * @return RlwePt
     */
    static RlwePt decrypt(const RlweCt &ct, const RlweSk &rlwe_sk,
                          u64 pt_modulus);
};

} // namespace hehub