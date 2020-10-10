//
// Created by 包信和 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_CHOLESKY_DECOMPOSE_HPP
#define HAPPY_MATRIX_CHOLESKY_DECOMPOSE_HPP

#include <cmath>

#include <triangle_solve.hpp>

namespace happy_matrix{
    template<typename T>
    void LLT_decompose(matrix<T>& to_decompose){
        const auto size = to_decompose.size();
        for (int i = 0; i < size; ++i) {
            to_decompose[i][i] = sqrt(to_decompose[i][i]);
            for (int j = i + 1; j < size; ++j)
                to_decompose[j][i] /= to_decompose[i][i];
            for (int j = i + 1; j < size; ++j)
                for (int k = j; k < size; ++k)
                    to_decompose[k][j] -= to_decompose[k][i] * to_decompose[j][i];
        }
        for (int i = 1; i < size; ++i)
            for (int j = 0; j < i; ++j)
                to_decompose[j][i] = to_decompose[i][j];
    }

    template<typename T>
    void LDLT_decompose(matrix<T>& to_decompose){
        const auto size = to_decompose.size();
        vector<T> v(size - 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j)
                v[j] = to_decompose[i][j] * to_decompose[j][j];
            for (int j = 0; j < i; ++j)
                to_decompose[i][i] -= to_decompose[i][j] * v[j];
            for (int j = i + 1; j < size; ++j){
                for (int k = 0; k < i; ++k)
                    to_decompose[j][i] -= to_decompose[j][k] * v[k];
                to_decompose[j][i] /= to_decompose[i][i];
                }
        }
        for (int i = 1; i < size; ++i)
            for (int j = 0; j < i; ++j)
                to_decompose[j][i] = to_decompose[i][j];
    }

    template<typename T>
    __forceinline void LLT_solve(matrix<T>& to_decompose, vector<T>& to_solve) {
        LLT_decompose(to_decompose);
        triangle_solve_lower(to_decompose, to_solve);
        triangle_solve_upper(to_decompose, to_solve);
    }

    template<typename T>
    __forceinline void LDLT_solve(matrix<T>& to_decompose, vector<T>& to_solve) {
        LDLT_decompose(to_decompose);
        triangle_solve_lower<T,true>(to_decompose, to_solve);
        for (size_t i = 0; i < to_solve.size(); i++)
            to_solve[i] /= to_decompose[i][i];
        triangle_solve_upper<T,true>(to_decompose, to_solve);
    }
}

#endif

