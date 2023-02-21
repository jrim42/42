#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include <cstdint>
# include <stdexcept>

namespace ft 
{
	// equal: 두 범위의 요소가 동일한지 검사하는 함수
		// [first1, last1] 범위의 요소를 first2부터 시작하는 범위의 요소와 비교하고
		// 두 범위의 모든 요소가 일치하면 true를 반환한다.
	template <class iIter1, class iIter2>
	bool	equal(iIter1 first1, iIter1 last1, iIter2 first2) 
	{
		while (first1 != last1) 
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class iIter1, class iIter2, class BinaryPredicate>
	bool	equal(iIter1 first1, iIter1 last1, iIter2 first2, BinaryPredicate pred) 
	{
		while (first1 != last1) 
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// lexicographical_compare: 사전식 순서로 비교해주는 함수
		// [first1, last1]이 [first2, last2]보다 사전순으로 작을 경우 true를 반환한다.
	template <class iIter1, class iIter2>
	bool	lexicographical_compare(iIter1 first1, iIter1 last1, iIter2 first2, iIter2 last2) 
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
		return (first2 != last2);
	}

	template <class iIter1, class iIter2, class Compare>
	bool	lexicographical_compare(iIter1 first1, iIter1 last1, iIter2 first2, iIter2 last2, Compare comp) 
	{
		while (first1 != last1) 
		{
			if (first2 == last2 || comp(*first1, *first2))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}  // namespace ft

#endif