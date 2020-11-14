# Numerical-algebra
Numerical algebra assignment, just for reference, do not copy blindly.  
[Chinese README](README_CN.md)(lots of translation error)
## Happy_matrix_123
### main feature
- Approriate use of template and concept, so that you can change size and type of matrix by only editing T and size in one line
- Precisely calculate the infinity condition number of 5-20 order Hilbert matrix, including a rational version and a floating-point version
- Use OpenMP and compiler's auto-vectorization in Matrix-vector product, OpenMp is commented, uncomment this for large matrix
### main fallback
- Does not guarantee exception-safe, I sacrifice it for size of executive. If you want to, add suitable exception such as *underflow error* to the code.
- Do not use BLAS/LAPACK/GPU, poor benchmark, do not mind this
## License  
The project is licensed under [GNU General Public License v3.0](LICENSE)

