# Numerical-algebra
Numerical algebra assignment, just for reference, do not copy blindly.
## Happy_matrix_1
### main feature
- Reuse of code. Generating 5 executives with 3 files. Theoretically, it can be done within one file, checkout [dev](https://github.com/Wongboo/numerical-algebra/tree/dev)! By doing so, you can change 2_1 and 3_1 or 2_2 and 3_2 at once
- Approriate use of template and concept, so that you can change size and type of matrix by only editing T and size in one line
### main fallback
- Does not guarantee exception-safe, I sacrifice it for size of executive. If you want to, add suitable exception such as *underflow error* to the code.
-  In the auxiliary function, you have to manually rather than automatically type the name of function, wish someone can solve it in the issue. The possible solution is the macro *\_\_PRETTY_FUNCTION\_\_* / *\_\_func\_\_* or the previous experimental class *std::source_location*.Anyway, I solve it by using macro *#*, but it will create a function-like macro, which isn't limited in a namespace and is prone 
## License  
The project is licensed under [GNU General Public License v3.0](LICENSE)
## Sponsor
Do not press *Sponsor* button, it is invalid!
