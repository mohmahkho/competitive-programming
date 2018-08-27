#ifndef _MK_DS_MATRIX_
#define _MK_DS_MATRIX_

#include <vector> // std::vector

namespace mk { namespace ds {
    template<typename T>
    class matrix : public std::vector<std::vector<T>>
    {
        typedef std::vector<T> vec1d;
        typedef std::vector<vec1d> vec2d;
        typedef typename vec1d::size_type size_type;
    public:
        matrix(size_type rows, size_type cols)
        : vec2d(rows, vec1d(cols))
        {
        }

        matrix(size_type n)
        : vec2d(n, vec1d(n))
        {
        }
        
        void resize(size_type rows, size_type cols) {
            vec2d::resize(rows);
            for(vec1d& row : *this) {
                row.resize(cols);
            }
        }

        size_type rows() {
            return (*this).size();
        }
        size_type cols() {
            return (*this).at(0).size();
        }
    };
} }

#endif
