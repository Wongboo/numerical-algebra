//
// Created by 王波 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_AUXILIARY_HPP
#define HAPPY_MATRIX_AUXILIARY_HPP

#include <chrono>
#include <iostream>
#include <initializer_list>
#include <predefine.hpp>

namespace happy_matrix{
    template<typename T>
    using solving = void(matrix<T>&, vector<T>&);

    template<typename T, bool is_compare = false>
    __forceinline void auxiliary(solving<T> solve, const char* out, const matrix<T>& to_decompose_, const vector<T>& to_solve_){
        auto to_decompose = to_decompose_;
        auto to_solve = to_solve_;

        auto start = std::chrono::high_resolution_clock::now();

        solve(to_decompose, to_solve);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << out << " elapsed time: " << elapsed_seconds.count() << "s\n" << out << " solved: ";

        for (const auto& item: to_solve)
            std::cout << item << " ";
        std::cout << '\n';

        if constexpr (is_compare) {
            to_solve = to_decompose_ * to_solve;
            std::cout << out << " before: ";
            for (const auto &item: to_solve_)
                std::cout << item << " ";
            std::cout << '\n';
            std::cout << out << " after: ";
            for (const auto &item: to_solve)
                std::cout << item << " ";
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    /* template<typename T, bool is_compare = false>
    __forceinline void auxiliary(std::initializer_list<solving<T>> solve, std::initializer_list<const char*> out,
                                 matrix<T> to_decompose, vector<T> to_solve){
        for (size_t i = 0; i < solve.size(); ++i)
            auxiliary<T,is_compare>(solve.begin()[i], out.begin()[i], to_decompose, to_solve);
    }*/
}
#endif //HAPPY_MATRIX_AUXILIARY_HPP
