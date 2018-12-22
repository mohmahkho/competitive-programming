#ifndef MK_RANGE_VECTOR
#define MK_RANGE_VECTOR

#include <vector> // std::vector
#include <memory> // std::allocator
#include <initializer_list> // std::initializer_list

namespace mk {
    template < class T, class Alloc = std::allocator<T> >
    class RangeVector : public std::vector<T, Alloc>
    {
        using base       = std::vector<T, Alloc>;
        using range_type = int;
        using size_type  = typename base::size_type;
        using value_type = typename base::value_type;
        using reference  = value_type&;
        
        range_type _first; // last = first + size() // [first, last)
    public:
        RangeVector()
        : base(), _first(0)
        {
        }

        RangeVector(range_type first, range_type last)
        : base(last - first), _first(first)
        {
        }

        RangeVector(range_type first, range_type last, const value_type& value)
        : base(last - first, value), _first(first)
        {
        }

        RangeVector(size_type n)
        : base(n), _first(0)
        {
        }

        RangeVector(std::initializer_list<T> il, range_type first = 0)
        : base(il), _first(first)
        {
        }

        reference operator[] (range_type i) {
            return base::operator[](i - _first);
        }

        reference at (range_type i) {
            return base::at(i - _first);
        }

        void rearrange(range_type first, range_type last) {
            this->_first = first;
            base::resize(last - first);
        }

        void set_first(range_type first) {
            this->_first = first;
        }

        range_type first() {
            return _first;
        }

        range_type last() {
            return _first + (range_type)base::size();
        }
    };
}

#endif
