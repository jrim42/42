#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

# include <cstdint>
# include <stdexcept>

namespace ft 
{
    // equal
    template <class iIter1, class iIter2>
    bool equal
        (iIter1 first1, iIter1 last1, iIter2 first2) 
    {
        for ( ; first1 != last1 ; first1++, first2++) 
        {
            if (!(*first1 == *first2))
                return false;
        }
        return true;
    }

    template <class iIter1, class iIter2, class BinaryPredicate>
    bool equal
        (iIter1 first1, iIter1 last1, iIter2 first2, BinaryPredicate prd) 
    {
        for ( ; first1 != last1 ; first1++, first2++) 
        {
            if (!prd(*first1, *first2)) 
                return false;
        }
        return true;
    }

    // lexicographical_compare
    template <class iIter1, class iIter2>
    bool lexicographical_compare
        (iIter1 first1, iIter1 last1,
         iIter2 first2, iIter2 last2) 
    {
        for ( ; first2 != last2 ; first1++, first2++) 
        {
            if (first1 == last1 || *first1 < *first2)
                return true;
            if (*first1 > *first2)
                return false;
        }
        return false;
    }

    template <class iIter1, class iIter2, class Compare>
    bool lexicographical_compare
        (iIter1 first1, iIter1 last1,
         iIter2 first2, iIter2 last2, Compare comp) 
    {
        for ( ; first2 != last2 ; first1++, first2++) 
        {
            if (first1 == last1 || comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return false;
    }
}  // namespace ft

#endif