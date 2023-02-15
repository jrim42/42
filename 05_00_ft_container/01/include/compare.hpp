#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# define T_RED "\033[0;31m"
# define T_GRN "\033[0;32m"
# define T_YLW "\033[0;33m"
# define T_BLU "\033[0;36m"
# define T_GRY "\033[90m"
# define T_DFT "\033[0;37m"

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
        while (first1 != last1) 
        {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
	    return (first2!=last2);
    }

    template <class iIter1, class iIter2, class Compare>
    bool lexicographical_compare
        (iIter1 first1, iIter1 last1,
         iIter2 first2, iIter2 last2, Compare comp) 
    {
        while (first1 != last1 && !comp(first1, first2)) 
        {
			if (first2 == last2)
				return false;
			++first1;
			++first2;
		}
		return first2!=last2 ? false : first1 == last1 || comp(first1, first2);
    }
}  // namespace ft

#endif