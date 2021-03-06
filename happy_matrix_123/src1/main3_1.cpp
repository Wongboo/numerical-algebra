//
// Created by 包信和 on 2020/10/2.
//

#include <random>

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
    using T = double;
    constexpr size_t size = 100;
    matrix<T> to_decompose(size, vector<T>(size));
    vector<T> to_solve(size);
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (size_t i = 0; i < size; ++i){
        if (i != 0)
            to_decompose[i][i - 1] = to_decompose[i - 1][i]= 1;
        to_decompose[i][i] = 10;
    }

    for (size_t i = 0; i < size; ++i) {
        // Use dis to transform the random unsigned int generated by gen into a
        // T in [-1, 1). Each call to dis(gen) generates a new random T
        to_solve[i] = dis(gen);
    }

#ifdef USE_GAUSS
    auxiliary_comp(Gauss_solve_normal, to_decompose, to_solve);
    auxiliary_comp(Gauss_solve_column, to_decompose, to_solve);
#endif
    auxiliary_comp(LLT_solve, to_decompose, to_solve);
    auxiliary_comp(LDLT_solve, to_decompose, to_solve);
#ifdef USE_QR
    auxiliary_comp(QR_solve, to_decompose, to_solve);
#endif
    return 0;
}