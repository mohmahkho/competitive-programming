#ifndef _MK_TENSOR_
#define _MK_TENSOR_

#include <vector>

#ifndef _MK_TENSOR_
#define _MK_TENSOR_

#include <vector>

namespace mk {
    template<typename T>
    struct tensor : public std::vector<std::vector<std::vector<T>>>
    {
        tensor(unsigned int dim0, unsigned int dim1, unsigned int dim2)
        : std::vector<std::vector<std::vector<T>>>(dim0,
                       std::vector<std::vector<T>>(dim1,
                                    std::vector<T>(dim2)))
        {
        }

        tensor(unsigned int dim_size)
        : std::vector<std::vector<std::vector<T>>>(dim_size,
                       std::vector<std::vector<T>>(dim_size,
                                    std::vector<T>(dim_size)))
        {
        }
        
        void resize(unsigned int dim0, unsigned int dim1, unsigned int dim2) {
            std::vector<std::vector<std::vector<T>>>::resize(dim0);
            for(std::vector<std::vector<T>>& mat_vector : *this) {
                mat_vector.resize(dim1);
                for(std::vector<T>& row_vector : mat_vector) {
                    row_vector.resize(dim2);
                }
            }
        }

        typename std::vector<std::vector<std::vector<T>>>::size_type
        dim0_size() {
            return (*this).size();
        }
        typename std::vector<std::vector<T>>::size_type
        dim1_size() {
            return (*this).at(0).size();
        }
        typename std::vector<T>::size_type
        dim2_size() {
            return (*this).at(0).at(0).size();
        }

    };
}

#endif