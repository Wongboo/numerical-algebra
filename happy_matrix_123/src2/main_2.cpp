//
// Created by 王波 on 2020/10/23.
//

#include <iostream>
#include <numeric>
#include <random>
#include <Gauss_elimination.hpp>

using namespace happy_matrix;
using namespace std;

int main() {
    using T = double;
    matrix<T> to_decompose, to_decompose_t;
    vector<T> to_solve, optimized, solved, random_vec;
    constexpr auto abs_comp = [](auto a, auto b) { return abs(a) < abs(b); };
    constexpr auto max_diff = [](int i, const vector<T> &to_solve, const vector<T> &random_vec) {
        T real_error = 0.0;
        for (size_t j = 0; j < i; ++j)
            real_error = max(real_error, abs(to_solve[j] - random_vec[j]));
        return real_error;
    };

    to_decompose.reserve(30);
    to_decompose_t.reserve(30);
    to_solve.reserve(30);
    optimized.reserve(30);
    solved.reserve(30);
    random_vec.reserve(30);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (size_t i = 5; i <= 30; ++i) {
        to_decompose.resize(i, vector<T>(i - 1));
        optimized.resize(i);
        random_vec.resize(i);
        for (size_t j = 0; j < i; ++j) {
            for (size_t k = 0; k < i - 1; ++k)
                to_decompose[j][k] = j > k ? -1 : j < k ? 0 : 1;
            to_decompose[j].push_back(1.0);
        }
        to_decompose_t = to_decompose;

        //in the following to_decompose_t represent the original matrix
        for (auto &term : random_vec)
            term = dis(gen);    //generate random_vec
        solved = to_solve = to_decompose * random_vec;
        auto p = Gauss_elimination_column(to_decompose);
        Gauss_solving_column(p, to_decompose, solved);
        cout << 'A' << i << " real error:" << max_diff(i, solved, random_vec) << '\n';
        T ar_b_norm = i * max_diff(i, to_solve, to_decompose_t * solved) /
                      abs(*max_element(to_solve.begin(), to_solve.end(), abs_comp));

        //now, it's not, and do not decompose twice!
        to_decompose_t = !to_decompose;
        to_solve.assign(i, 1.0 / i);

        while (true) {
            solved = to_solve;
            Gauss_solving_column<T, true>(p, to_decompose_t, solved);
            for (size_t j = 0; j < i; ++j)
                optimized[j] = solved[j] > 0 ? 1 : solved[j] < 0 ? -1 : 0;
            Gauss_solving_column(p, to_decompose, optimized);
            auto max = max_element(optimized.begin(), optimized.end(), abs_comp);
            if (abs(*max) <= inner_product(optimized.begin(), optimized.end(), to_solve.begin(), T(0))) {
                auto inverse_norm = accumulate(solved.begin(), solved.end(), T(0),
                                            [](auto sum, auto term) { return sum + abs(term); });
                cout << 'A' << i << " theoretical error:" << inverse_norm * ar_b_norm << '\n';
#ifdef COUT_CONDITION_NUMBER
                cout << "condition number of " << i << " order matrix is " << i * inverse_norm << '\n';
#endif
                cout << '\n';
                break;
            } else {
                to_solve.assign(i, 0.0);
                to_solve[distance(optimized.begin(), max)] = 1.0;
            }
        }
    }
}