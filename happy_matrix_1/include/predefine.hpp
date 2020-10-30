//
// Created by 包信和 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_PREDEFINE_HPP
#define HAPPY_MATRIX_PREDEFINE_HPP

#include <cassert>
#include <vector>
#include <type_traits>

#ifndef _WIN64
#define __forceinline inline __attribute__((always_inline))
#endif

namespace happy_matrix {
    using std::vector;

    //apple clang doesn't support concepts!
    template<typename T> requires(std::is_floating_point_v<T>)
    using matrix = vector<vector<T>>;

    template<typename T>
    vector<T> operator*(const matrix<T>& left, const vector<T>& right){
        vector<T> out(left.size(), 0);
        for(size_t i = 0; i < left.size(); i++)
            for (size_t j = 0; j < right.size(); j++)
                out[i] += left[i][j] * right[j];
        return out;
    }
}
#endif //HAPPY_MATRIX_PREDEFINE_HPP
