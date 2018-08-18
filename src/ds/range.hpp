#include <vector> // std::vector
#include <memory> // std::allocator
#include <initializer_list> // std::initializer_list

namespace mk { namespace ds {
    template < class T, class Alloc = std::allocator<T> >
    class range : public std::vector<T, Alloc>
    {
        typedef int range_type;
        typedef typename std::vector<T>::size_type size_type;
        range_type _first; // last = first + size() // [first, last)
    public:
        range()
        : std::vector<T>(), _first(0)
        {
        }
        
        range(range_type first, range_type last)
        : std::vector<T>(last - first), _first(first)
        {
        }

        range(size_type n)
        : std::vector<T>(n), _first(0)
        {
        }

        range(std::initializer_list<T> il, range_type first = 0)
        : std::vector<T>(il), _first(first)
        {
        }

        T& operator[] (range_type i) {
            return std::vector<T>::operator[](i - _first);
        }

        T& at (range_type i) {
            return std::vector<T>::at(i - _first);
        }

        void rearrange(range_type first, range_type last) {
            this->_first = first;
            std::vector<T>::resize(last - first);
        }

        void set_first(range_type first) {
            this->_first = first;
        }

        range_type first() {return _first;}
        range_type last()  {return _first + (range_type)std::vector<T>::size();}
    };
} }
