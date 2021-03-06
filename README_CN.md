# 数值代数

数值代数作业，仅供参考，不要盲目抄袭。

## 快乐矩阵1

### 主要特征

- 代码的重用。生成5名高管和3个文件。理论上，它可以在一个文件，看看[dev](https://github.com/Wongboo/numeric-algebration/tree/dev)内完成! 通过这样做，您可以同时更改2_1和3_1或2_2和3_2

- 适当使用模板和概念，这样你就可以通过在一行编辑T和大小来改变矩阵的大小和类型

### 主回退

- 不能保证例外安全，我牺牲它的大小行政。如果您愿意，请在代码中添加适当的异常，如*下溢错误*。

- 在辅助函数中，您需要手动输入函数名，而不是自动键入函数名，希望有人能解决这个问题。可能的解决方案是宏*\_\_PRETTY_FUNCTION\_\_* / *\_\_func\_\_* 或上一个实验类*std::source_location*。总之，我使用macro*#*来解决它，但它将创建一个类似宏的函数，它不受名称空间的限制，但易受损

## 快乐矩阵2

### 主要特征

- 精确计算5-20阶矩阵的无穷条件数

## 许可证

该项目是根据[GNU通用公共许可证v3.0](LICENSE)授权的
