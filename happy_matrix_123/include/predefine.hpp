//
// Created by 包信和 on 2020/10/2.
//

#ifndef HAPPY_MATRIX_PREDEFINE_HPP
#define HAPPY_MATRIX_PREDEFINE_HPP

#include <vector>
#include <execution>
#include <omp.h>

#ifndef _WIN32
#define __forceinline inline __attribute__((always_inline))
#endif

namespace boost {
    template<typename T>
    class rational;
}

namespace happy_matrix {
    //floating_number can only judge native floating number in C++
    template<typename T>
    concept real_float_number = std::numeric_limits<T>::is_specialized &&
                                !std::numeric_limits<T>::is_integer;

    template<typename T>
    concept rational_number = std::is_same_v<T, boost::rational<typename T::int_type>>;

    template<typename T>
    concept real_divide_number = real_float_number<T> || rational_number<T>;

    using std::vector;

    template<typename T> requires real_divide_number<T>
    using matrix = vector<vector<T>>;

    template<typename T>
    vector<T> operator*(const matrix<T> &left, const vector<T> &right) {
        vector<T> out(left.size());
#ifdef __clang__
//#pragma omp parallel for shared(left, right, out) default(none) num_threads(omp_get_num_procs() / 2)
        for (int i = 0; i < left.size(); i++){
            T s(0);
#pragma clang loop vectorize(enable)
            for (size_t j = 0; j < right.size(); j++)
                s += left[i][j] * right[j];
            out[i] = s;
#else
//#pragma omp parallel for shared(left, right, out, std::execution::unseq) default(none) num_threads(omp_get_num_procs() / 2)
        for (int i = 0; i < left.size(); i++){
            out[i] = std::transform_reduce(std::execution::unseq, right.begin(),
                                           right.end(), left[i].begin(), T(0));
#endif
        }
        return out;
    }

    template<typename T>
    matrix<T> operator!(const matrix<T> &to_transpose) {
        matrix<T> transposed(to_transpose[0].size(), vector<T>(to_transpose.size()));
        for (size_t i = 0; i < to_transpose[0].size(); ++i)
            for (size_t j = 0; j < to_transpose.size(); ++j)
                transposed[i][j] = to_transpose[j][i];
        return transposed;
    }
}
#endif //HAPPY_MATRIX_PREDEFINE_HPP
