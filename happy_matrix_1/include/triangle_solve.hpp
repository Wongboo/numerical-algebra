//
// Created by 包信和 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_TRIANGLE_SOLVE_HPP
#define HAPPY_MATRIX_TRIANGLE_SOLVE_HPP

#include <predefine.hpp>
#include <exception>

namespace happy_matrix{
    template<typename T, bool is_identical = false>
    void triangle_solve_upper(const matrix<T> &coefficient, vector<T> &to_solve) {
        //if (coefficient.size() != coefficient[0].size() || coefficient.size() != to_solve.size())
            //throw std::invalid_argument("Size of matrix and vector not fit!");

        const auto size = coefficient.size();
        for (size_t i = size - 1; i > 0; --i) {
            //don't manually throw error 1/0 will throw error
            if constexpr (!is_identical)
                to_solve[i] /= coefficient[i][i];
            for (size_t j = 0; j < i; ++j)
                to_solve[j] -= to_solve[i] * coefficient[j][i];
        }
        if constexpr (!is_identical)
            to_solve[0] /= coefficient[0][0];
    }

    template<typename T, bool is_identical = false>
    void triangle_solve_lower(const matrix<T> &coefficient, vector<T> &to_solve) {
        //if (coefficient.size() != coefficient[0].size() || coefficient.size() != to_solve.size())
            //throw std::invalid_argument("Size of matrix and vector not fit!");

        const auto size = coefficient.size();
        for (size_t i = 0; i < size - 1; ++i) {
            //don't manually throw error 1/0 will throw error
            if constexpr (!is_identical)
                to_solve[i] /= coefficient[i][i];
            for (size_t j = i + 1; j < size; ++j)
                to_solve[j] -= to_solve[i] * coefficient[j][i];
        }
        if constexpr (!is_identical)
            to_solve[size - 1] /= coefficient[size - 1][size - 1];
    }
}

#endif //HAPPY_MATRIX_TRIANGLE_SOLVE_HPP
