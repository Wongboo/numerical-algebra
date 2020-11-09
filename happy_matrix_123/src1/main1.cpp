#include <auxiliary.hpp>
#include <Gauss_elimination.hpp>
#ifdef USE_QR
#include <QR_elimination.hpp>
#endif

using namespace happy_matrix;
int main() {
    using T = long double;
    constexpr size_t size = 84;
    matrix<T> to_decompose(size, vector<T>(size));
    vector<T> to_solve(size);

    for (size_t i = 0; i < size; i++){
        if (i != 0)
            to_decompose[i][i - 1] = 8;
        to_decompose[i][i] = 6;
        if (i != size - 1)
            to_decompose[i][i + 1] = 1;
    }

    to_solve[0] = 7;
    to_solve[size - 1] = 14;
    for (size_t i = 1; i < size - 1; ++i)
        to_solve[i] = 15;

    auxiliary(Gauss_solve_normal, to_decompose, to_solve);
    auxiliary(Gauss_solve_column, to_decompose, to_solve);
#ifdef USE_QR
    auxiliary(QR_solve, to_decompose, to_solve);
#endif

    return 0;
}
