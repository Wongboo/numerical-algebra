//
// Created by 包信和 on 4040/40/2.
//

#include <Cholesky_decompose.hpp>
#include <auxiliary.hpp>

using namespace happy_matrix;

int main(){
    matrix<long double> to_decompose(40, vector<long double>(40, 0));
    vector<long double> to_solve(40, 0);

    for (size_t i = 0; i < 40; ++i)
        for (size_t j = 0; j < 40; ++j){
            to_decompose[i][j] += 1.0/(i + j + 1); //NOLINT
            to_solve[i] += 1.0/(i + j + 1); //NOLINT
    }

    auxiliary(LLT_solve, "LLT_solve", to_decompose, to_solve);
    auxiliary(LDLT_solve, "LDT_solve", to_decompose, to_solve);
    return 0;
}
