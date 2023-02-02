#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

# include <cstdint>

namespace ft
{
    // enable_if
    template <bool cond, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> 
    {
	    typedef T type;
    };

    // remove_cv (constant and volatile)
    template <typename T>
    struct remove_cv { typedef T type; };

    template <typename T>
    struct remove_cv<const T> { typedef T type; };

    template <typename T>
    struct remove_cv<volatile T> { typedef T type; };

    template <typename T>
    struct remove_cv<const volatile T> { typedef T type; };

    // integral constant
    template <typename T, T v>
    struct integral_constant 
    {
        static const value_type         value = v;
        typedef T                       value_type;
        typedef integral_constant<T, v> type;

        operator value_type(void) const { return value; }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    // is_integral_base
    template <bool is_integral, typename T>
    struct is_integral_base 
    {
	    typedef T type;
	    const static bool value = is_integral;
    };

    template <typename T>
    struct is_integral : public is_integral_base<typename remove_cv<T>::type> {};

    template <typename>
    struct is_integral : public is_integral_base<false, void> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, bool> {};
    
    template <>
    struct is_integral<bool> : public is_integral_base<true, char16_t> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, char32_t> {};
    
    template <>
    struct is_integral<bool> : public is_integral_base<true, wchar_t> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, signed char> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, short int> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, int> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, long int> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, long long int> {};

    template <>
    struct is_integral<bool> : public is_integral_base<true, unsigned char> {};

} // namespace ft

#endif