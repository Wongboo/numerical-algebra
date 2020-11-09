#include <iostream>
#include <iomanip>
#include <numeric>
#include <Gauss_elimination.hpp>
#ifdef USE_BOOST_RATIONAL
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#elif USE_BOOST_QUAD
#include <boost/multiprecision/cpp_bin_float.hpp>
#endif

using namespace happy_matrix;
using namespace std;

int main() {
#ifdef USE_BOOST_RATIONAL
    using T = boost::rational<boost::multiprecision::int128_t>;
#elif USE_BOOST_QUAD
    using T = boost::multiprecision::cpp_bin_float_quad;
#else
    using T = long double;
#endif
    matrix<T> Hilbert(20, vector<T>(20)), to_decompose;
    vector<T> to_solve, optimized, solved;
    T origin_norm = T(1) + T(1) / 2 + T(1) / 3 + T(1) / 4;

    for (size_t i = 0; i < 20; ++i)
        for (size_t j = 0; j <= i; ++j)
            Hilbert[j][i] = Hilbert[i][j] = T(1) / (i + j + 1);

    to_decompose.reserve(20);
    to_solve.reserve(20);
    optimized.reserve(20);
    solved.reserve(20);

    for (size_t i = 5; i <= 20; ++i) {
        //assign it every time, cause to_decompose is already decomposed
        to_decompose.resize(i);
        optimized.resize(i);
        for (size_t j = 0; j < i; ++j)
            to_decompose[j].assign(Hilbert[j].begin(), Hilbert[j].begin() + i);
        to_solve.assign(i, T(1) / i);
        origin_norm += to_decompose.back().front();

        auto p = Gauss_elimination_column(to_decompose);
        //transpose(to_decompose); no need to transpose Hilbert!
        while (true) {
            solved = to_solve;
            Gauss_solving_column(p, to_decompose, solved);
            for (size_t j = 0; j < i; ++j)
                optimized[j] = solved[j] > 0 ? 1 : solved[j] < 0 ? -1 : 0;
            Gauss_solving_column(p, to_decompose, optimized);
            auto max = max_element(optimized.begin(), optimized.end(), [](auto a, auto b) { return abs(a) < abs(b); });
            if (abs(*max) <= inner_product(optimized.begin(), optimized.end(), to_solve.begin(), T(0))) {
                cout << "condition number of " << setw(2) << i << " order Hilbert matrix is "
                     << origin_norm * accumulate(solved.begin(), solved.end(), T(0),
                                                 [](auto sum, auto term) { return sum + abs(term); }) << '\n';
                break;
            } else {
                to_solve.assign(i, T(0));
                //cout << distance(optimized.begin(), max) << '\n';
                to_solve[distance(optimized.begin(), max)] = T(1);
            }
        }
    }
    return 0;
}
