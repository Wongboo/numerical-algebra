#include <auxiliary.hpp>
#include <Gauss_elimination.hpp>

using namespace happy_matrix;
int main() {
    matrix<long double> to_decompose(84, vector<long double>(84));
    vector<long double> to_solve(84);

    for (size_t i = 0; i < 84; i++){
        if (i != 0)
            to_decompose[i][i - 1] = 8;
        to_decompose[i][i] = 6;
        if (i != 83)
            to_decompose[i][i + 1] = 1;
    }

    to_solve[0] = 7;
    to_solve[83] = 14;
    for (int i = 1; i < 83; ++i)
        to_solve[i] = 15;

    //matrix<long double> to_decompose(2, vector<long double>(2));
    //vector<long double> to_solve(2);

    //to_decompose[1][1] = 3;
    auxiliary(Gauss_solve_normal, "Gauss_solve_normal", to_decompose, to_solve);
    auxiliary(Gauss_solve_column, "Gauss_solve_column", to_decompose, to_solve);

    return 0;
}
