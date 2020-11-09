//
// Created by 包信和 on 2020/10/2.
//

#include <Cholesky_decompose.hpp>
#ifdef USE_GAUSS
#include <Gauss_elimination.hpp>
#endif
#ifdef USE_QR
#include <QR_elimination.hpp>
#endif
#include <auxiliary.hpp>

using namespace happy_matrix;

int main(){
    using T = long double;
    constexpr size_t size = 40;
    matrix<T> to_decompose(size, vector<T>(size));
    vector<T> to_solve(size);

    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j){
            to_decompose[i][j] += 1.0/(i + j + 1); //NOLINT
            to_solve[i] += 1.0/(i + j + 1); //NOLINT
        }

#ifdef USE_GAUSS
    auxiliary(Gauss_solve_normal, to_decompose, to_solve);
    auxiliary(Gauss_solve_column, to_decompose, to_solve);
#endif
    auxiliary(LLT_solve, to_decompose, to_solve);
    auxiliary(LDLT_solve, to_decompose, to_solve);
#ifdef USE_QR
    auxiliary(QR_solve, to_decompose, to_solve);
#endif
    return 0;
}
