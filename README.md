# Numerical-algebra
Numerical algebra assignment, just for reference, do not copy blindly.
## Happy_matrix_1
### main feature
- Reuse of code. Compile 5 excecutive with 3 files. Theoretically, it can be done within one file, checkout [dev](https://github.com/Wongboo/numerical-algebra/tree/dev)!
- Approriate use of template and concept, so that you can change size and type of matrix by only editing T and size
### main issue  
- In the auxiliary function, you have to manually rather than automatically type the name of function, wish someone can solve it in the issue. The possible solution is the macro **\_\_PRETTY_FUNCTION\_\_** / **\_\_func\_\_** or the previous experimental class **std::source_location**.Anyway, I solve it by using macro **#**, but it will create a conflict with the optional feature below.
- (*optional*)You can uncomment the note in the [auxiliary.hpp](happy_matrix_1/include/auxiliary.hpp), and optionally subsitute **std::initializer_list** with other container or pointer, so that you can write a single line of function **happy_matrix::auxiliay** instead of several, which has a conflict with macro **#**
## License  
The project is licensed under [GPL-3.0](LICENSE)
## Sponsor
Do not press *Sponsor* button, it is invalid!