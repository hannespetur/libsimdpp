/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_TYPES_INT16X16_H
#define LIBSIMDPP_SIMDPP_TYPES_INT16X16_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/setup_arch.h>
#include <simdpp/types/fwd.h>
#include <simdpp/types/any.h>
#include <simdpp/core/cast.h>
#include <simdpp/detail/construct_eval.h>
#include <simdpp/detail/include_stdint.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

#if SIMDPP_USE_AVX2

/// @ingroup simd_vec_int
/// @{

/** Class representing 16x 16-bit signed integer vector
*/
template<>
class int16<16, void> : public any_int16<16, int16<16,void> > {
public:
    static const unsigned type_tag = SIMDPP_TAG_INT;
    typedef int16_t element_type;
    typedef int16<16> base_vector_type;
    typedef void expr_type;

#if SIMDPP_USE_AVX2
    typedef __m256i native_type;
#endif

    SIMDPP_INL int16<16>() {}
    // SIMDPP_INL int16<16>(const int16<16> &) = default;
    // SIMDPP_INL int16<16> &operator=(const int16<16> &) = default;

    template<class E> SIMDPP_INL int16<16>(const int16<16,E>& d) { *this = d.eval(); }
    template<class E> SIMDPP_INL int16<16>(const uint16<16,E>& d) { *this = d.eval(); }
    template<class V> SIMDPP_INL explicit int16<16>(const any_vec<32,V>& d)
    {
        *this = bit_cast<int16<16> >(d.wrapped().eval());
    }
    template<class V> SIMDPP_INL int16<16>& operator=(const any_vec<32,V>& d)
    {
        *this = bit_cast<int16<16> >(d.wrapped().eval()); return *this;
    }

    /// @{
    /// Construct from the underlying vector type
    SIMDPP_INL int16<16>(const native_type& d) : d_(d) {}
    SIMDPP_INL int16<16>& operator=(const native_type& d) { d_ = d; return *this; }
    /// @}

    /// Convert to the underlying vector type
    SIMDPP_INL operator native_type() const { return d_; }

    template<class E> SIMDPP_INL int16<16>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> SIMDPP_INL int16<16>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }

    /// @{
    /// Access base vectors
    SIMDPP_INL const int16<16>& vec(unsigned) const { return *this; }
    SIMDPP_INL int16<16>& vec(unsigned)       { return *this; }
    /// @}

    SIMDPP_INL int16<16> eval() const { return *this; }

private:
    native_type d_;
};

/** Class representing 16x 16-bit unsigned integer vector
*/
template<>
class uint16<16, void> : public any_int16<16, uint16<16,void> > {
public:
    static const unsigned type_tag = SIMDPP_TAG_UINT;
    typedef uint16_t element_type;
    typedef uint16<16,void> base_vector_type;
    typedef void expr_type;

#if SIMDPP_USE_AVX2
    typedef __m256i native_type;
#endif

    SIMDPP_INL uint16<16>() {}
    // SIMDPP_INL uint16<16>(const uint16<16> &) = default;
    // SIMDPP_INL uint16<16> &operator=(const uint16<16> &) = default;

    template<class E> SIMDPP_INL uint16<16>(const uint16<16,E>& d) { *this = d.eval(); }
    template<class E> SIMDPP_INL uint16<16>(const int16<16,E>& d) { *this = d.eval(); }
    template<class V> SIMDPP_INL explicit uint16<16>(const any_vec<32,V>& d)
    {
        *this = bit_cast<uint16<16> >(d.wrapped().eval());
    }
    template<class V> SIMDPP_INL uint16<16>& operator=(const any_vec<32,V>& d)
    {
        *this = bit_cast<uint16<16> >(d.wrapped().eval()); return *this;
    }

    /// @{
    /// Construct from the underlying vector type
    SIMDPP_INL uint16<16>(const native_type& d) : d_(d) {}
    SIMDPP_INL uint16<16>& operator=(const native_type& d) { d_ = d; return *this; }
    /// @}

    /// Convert to the underlying vector type
    SIMDPP_INL operator native_type() const { return d_; }

    template<class E> SIMDPP_INL uint16<16>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> SIMDPP_INL uint16<16>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }

    /// @{
    /// Access base vectors
    SIMDPP_INL const uint16<16>& vec(unsigned) const { return *this; }
    SIMDPP_INL uint16<16>& vec(unsigned)       { return *this; }
    /// @}

    SIMDPP_INL uint16<16> eval() const { return *this; }

private:
    native_type d_;
};

/// Class representing possibly optimized mask data for 8x 16-bit integer
/// vector
template<>
class mask_int16<16, void> : public any_int16<16, mask_int16<16,void> > {
public:
    static const unsigned type_tag = SIMDPP_TAG_MASK_INT;
    typedef mask_int16<16, void> base_vector_type;
    typedef void expr_type;

#if SIMDPP_USE_AVX2
    typedef __m256i native_type;
#endif

    SIMDPP_INL mask_int16<16>() {}
    // SIMDPP_INL mask_int16<16>(const mask_int16<16> &) = default;
    // SIMDPP_INL mask_int16<16> &operator=(const mask_int16<16> &) = default;

    SIMDPP_INL mask_int16<16>(const native_type& d) : d_(d) {}

#if SIMDPP_USE_AVX2
    SIMDPP_INL mask_int16<16>(const uint16<16>& d) : d_(d) {}
#endif

    SIMDPP_INL operator native_type() const { return d_; }

    /// Access the underlying type
    SIMDPP_INL uint16<16> unmask() const
    {
    #if SIMDPP_USE_AVX2
        return uint16<16>(d_);
    #endif
    }

    SIMDPP_INL const mask_int16<16>& vec(unsigned) const { return *this; }
    SIMDPP_INL mask_int16<16>& vec(unsigned)       { return *this; }

    SIMDPP_INL mask_int16<16> eval() const { return *this; }

private:
    native_type d_;
};

/// @} -- end ingroup

#endif // SIMDPP_USE_AVX2

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif
