//
// Created by 包信和 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_GAUSS_ELIMINATION_HPP
#define HAPPY_MATRIX_GAUSS_ELIMINATION_HPP

#include <cmath>
#include <algorithm>
#include <triangle_solve.hpp>

namespace happy_matrix{
    template<typename T>
    void Gauss_elimination_normal(matrix<T>& to_decompose){
        //if (to_decompose.size() != to_decompose[0].size())
            //throw std::invalid_argument("Size of matrix not fit!");

        const auto size = to_decompose.size();
        for (size_t i = 0; i < size - 1; ++i) {
            //don't manually throw error 1/0 will throw error
            for (size_t j = i + 1; j < size; ++j)
                to_decompose[j][i] /= to_decompose[i][i];
            for (size_t j = i + 1; j < size; ++j)
                for (size_t k = i + 1; k < size; ++k)
                    to_decompose[j][k] -= to_decompose[j][i] * to_decompose[i][k];
        }
    }

    template<typename T>
    vector<T> Gauss_elimination_column(matrix<T>& to_decompose){
        //if (to_decompose.size() != to_decompose[0].size())
            //throw std::invalid_argument("Size of matrix not fit!");

        const auto size = to_decompose.size();
        vector<T> p(size - 1);
        for (size_t i = 0; i < size - 1; ++i) {
            //don't manually throw error 1/0 will throw error
            T max = abs(to_decompose[i][i]);
            size_t index = i;
            for (size_t j = i + 1; j < size; ++j) {
                if (abs(to_decompose[j][i]) > max){
                    max = abs(to_decompose[j][i]);
                    index = j;
                }
            }
            if (index != i)
                std::swap(to_decompose[index], to_decompose[i]);
            p[i] = index;

            for (size_t j = i + 1; j < size; ++j)
                to_decompose[j][i] /= to_decompose[i][i];
            for (size_t j = i + 1; j < size; ++j)
                for (size_t k = i + 1; k < size; ++k)
                    to_decompose[j][k] -= to_decompose[j][i] * to_decompose[i][k];
        }
        return p;
    }

    template<typename T>
    __forceinline void Gauss_solve_normal(matrix<T>& to_decompose, vector<T>& to_solve){
        Gauss_elimination_normal(to_decompose);
        triangle_solve_lower<T, true>(to_decompose, to_solve);
        triangle_solve_upper(to_decompose, to_solve);
    }

    template<typename T>
    __forceinline void Gauss_solve_column(matrix<T>& to_decompose, vector<T>& to_solve){
        auto p = Gauss_elimination_column(to_decompose);
        for (size_t i = 0; i < p.size(); ++i)
            if (p[i] != i)
                std::swap(to_solve[i], to_solve[p[i]]);
        triangle_solve_lower<T, true>(to_decompose, to_solve);
        triangle_solve_upper(to_decompose, to_solve);
    }
}

#endif //HAPPY_MATRIX_GAUSS_ELIMINATION_HPP
