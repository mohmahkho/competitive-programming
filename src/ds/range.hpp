#ifndef _MK_RANGE_
#define _MK_RANGE_

#include <vector> // std::vector
#include <memory> // std::allocator
#include <initializer_list> // std::initializer_list

namespace mk { namespace ds {
    template < class T, class Alloc = std::allocator<T> >
    class range : public std::vector<T, Alloc>
    {
        typedef std::vector<T, Alloc> base;
        typedef int range_type;
        typedef typename base::size_type size_type;
        
        range_type _first; // last = first + size() // [first, last)
    public:
        range()
        : base(), _first(0)
        {
        }
        
        range(range_type first, range_type last)
        : base(last - first), _first(first)
        {
        }

        range(size_type n)
        : base(n), _first(0)
        {
        }

        range(std::initializer_list<T> il, range_type first = 0)
        : base(il), _first(first)
        {
        }

        T& operator[] (range_type i) {
            return base::operator[](i - _first);
        }

        T& at (range_type i) {
            return base::at(i - _first);
        }

        void rearrange(range_type first, range_type last) {
            this->_first = first;
            base::resize(last - first);
        }

        void set_first(range_type first) {
            this->_first = first;
        }

        range_type first() {return _first;}
        range_type last()  {return _first + (range_type)base::size();}
    };
} }

#endif
