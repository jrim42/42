#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;
		
		protected:
			container_type  c;

		public:
			explicit stack(const container_type& container = container_type()) 
				: c(container) {}
			stack(const stack& ref) 
				: c(ref.c) {}
			~stack(void) {}
			stack& operator=(const stack& ref) 
			{
				if (this != &ref)
					c = ref.c;
				return (*this);
			}

			// operators
			reference		top(void)					{ return c.back(); }
			const_reference	top(void) const				{ return c.back(); }
			bool			empty(void) const			{ return c.empty(); }
			size_type	   	size(void) const			{ return c.size(); }
			void			push(const value_type& val)	{ c.push_back(val);}
			void			pop(void)					{ c.pop_back(); }

			friend bool	operator==(const stack& a, const stack& b)	{ return (a.c == b.c); }
			friend bool	operator!=(const stack& a, const stack& b)	{ return (a.c != b.c); }
			friend bool	operator<(const stack& a, const stack& b)	{ return (a.c < b.c); }
			friend bool	operator>(const stack& a, const stack& b)	{ return (a.c > b.c); }
			friend bool	operator<=(const stack& a, const stack& b)	{ return (a.c <= b.c); }
			friend bool	operator>=(const stack& a, const stack& b)	{ return (a.c >= b.c); }
	}; // end of class stack

	/*
	// boolean operators
	template <class T, class Container>
	inline bool operator==(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return (a.c == b.c); }
	
	template <class T, class Container>
	inline bool operator<(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return (a.c < b.c); }

	template <class T, class Container>
	inline bool operator!=(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return !(a.c == b.c); }

	template <class T, class Container>
	inline bool operator>(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return (b.c < a.c); }
	
	template <class T, class Container>
	inline bool operator>=(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return !(a.c < b.c); }
	
	template <class T, class Container>
	inline bool operator<=(const ft::stack<T, Container>& a, 
						   const ft::stack<T, Container>& b)  
	{ return !(a.c > b.c); }
	*/
}  // end of namespace ft

#endif