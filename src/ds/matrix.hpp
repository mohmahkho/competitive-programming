#ifndef _MK_MATRIX_
#define _MK_MATRIX_

#include <vector>

namespace mk {
    template<typename T>
    struct matrix : public std::vector<std::vector<T>>
    {
        matrix(unsigned int dim0, unsigned int dim1)
        : std::vector<std::vector<T>>(dim0,
                       std::vector<T>(dim1))
        {
        }

        matrix(unsigned int dim_size)
        : std::vector<std::vector<T>>(dim_size, std::vector<T>(dim_size))
        {
        }
        
        void resize(unsigned int dim0, unsigned int dim1) {
            std::vector<std::vector<T>>::resize(dim0);
            for(std::vector<T>& row_vector : *this) {
                row_vector.resize(dim1);
            }
        }

        typename std::vector<std::vector<T>>::size_type dim0_size() {
            return (*this).size();
        }
        typename std::vector<T>::size_type dim1_size() {
            return (*this).at(0).size();
        }

    };
}

#endif