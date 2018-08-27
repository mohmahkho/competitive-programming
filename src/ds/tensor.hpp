#ifndef _MK_DS_TENSOR_
#define _MK_DS_TENSOR_

#include <vector> // std::vector
#include <memory> // std::allocator

namespace mk { namespace ds {
    template< class T, class Alloc = std::allocator<T> >
    class tensor
    : public std::vector<std::vector<std::vector<T, Alloc>, Alloc>, Alloc>
    {
        typedef std::vector<T, Alloc> vec1d;
        typedef std::vector<vec1d, Alloc> vec2d;
        typedef std::vector<vec2d, Alloc> vec3d;
        typedef typename vec1d::size_type size_type;
    public:
        tensor() = default;

        tensor(size_type layers, size_type rows, size_type cols)
        : vec3d(layers, vec2d(rows, vec1d(cols)))
        {
        }

        tensor(size_type n)
        : vec3d(n, vec2d(n, vec1d(n)))
        {
        }

        void resize(size_type layers, size_type rows, size_type cols) {
            vec3d::resize(layers);
            for(vec2d& layer : *this) {
                layer.resize(rows);
                for(vec1d& row : layer) {
                    row.resize(cols);
                }
            }
        }

        size_type layers() {
            return (*this).size();
        }

        size_type rows() {
            return (*this).at(0).size();
        }

        size_type cols() {
            return (*this).at(0).at(0).size();
        }

    };
} }

#endif
