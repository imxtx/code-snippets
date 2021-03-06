## 运行说明

**环境要求：**

- 需要使用Python3.6以上
- 需要安装numpy用于支持矩阵运算：`pip install numpy`

**程序运行流程：**

- 进入文件 `lu.py` 所在文件夹
- 执行命令 `python lu.py`
- 结果会显示在命令行中，也可重定向输出 `python lu.py > output.txt`

其中 `input.txt` 为输入的矩阵（支持非方阵的LU分解），多个矩阵使用空行隔开，如输入两个矩阵：

```
1 2
3 4

1 2 3
2 3 4
5 6 7
```

## 示列

输入存储在 `input.txt`中（可以随意修改）：

```
1 2 3
2 3 4
4 5 6

1 2
3 4

1 1 1 
0 0 1
0 0 1

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 2 4 17
3 6 -12 3
2 3 -3 2
0 2 -2 6

1 2 3
1 2 2
```

输出：

```
------------------------------------------------------------
matrix 1:
    1.0000    2.0000    3.0000
    2.0000    3.0000    4.0000
    4.0000    5.0000    6.0000
P:
    0.0000    0.0000    1.0000
    1.0000    0.0000    0.0000
    0.0000    1.0000    0.0000
L:
    1.0000    0.0000    0.0000
    0.2500    1.0000    0.0000
    0.5000    0.6667    1.0000
U:
    4.0000    5.0000    6.0000
    0.0000    0.7500    1.5000
    0.0000    0.0000    0.0000
PA=
    4.0000    5.0000    6.0000
    1.0000    2.0000    3.0000
    2.0000    3.0000    4.0000
LU=
    4.0000    5.0000    6.0000
    1.0000    2.0000    3.0000
    2.0000    3.0000    4.0000

No Inverse!
------------------------------------------------------------
------------------------------------------------------------
matrix 2:
    1.0000    2.0000
    3.0000    4.0000
P:
    0.0000    1.0000
    1.0000    0.0000
L:
    1.0000    0.0000
    0.3333    1.0000
U:
    3.0000    4.0000
    0.0000    0.6667
PA=
    3.0000    4.0000
    1.0000    2.0000
LU=
    3.0000    4.0000
    1.0000    2.0000

Inverse:
   -2.0000    1.0000
    1.5000   -0.5000
------------------------------------------------------------
------------------------------------------------------------
matrix 3:
    1.0000    1.0000    1.0000
    0.0000    0.0000    1.0000
    0.0000    0.0000    1.0000
P:
    1.0000    0.0000    0.0000
    0.0000    1.0000    0.0000
    0.0000    0.0000    1.0000
L:
    1.0000    0.0000    0.0000
    0.0000    1.0000    0.0000
    0.0000    0.0000    1.0000
U:
    1.0000    1.0000    1.0000
    0.0000    0.0000    1.0000
    0.0000    0.0000    1.0000
PA=
    1.0000    1.0000    1.0000
    0.0000    0.0000    1.0000
    0.0000    0.0000    1.0000
LU=
    1.0000    1.0000    1.0000
    0.0000    0.0000    1.0000
    0.0000    0.0000    1.0000

No Inverse!
------------------------------------------------------------
------------------------------------------------------------
matrix 4:
    1.0000    2.0000    3.0000    4.0000
    5.0000    6.0000    7.0000    8.0000
    9.0000   10.0000   11.0000   12.0000
   13.0000   14.0000   15.0000   16.0000
P:
    0.0000    0.0000    0.0000    1.0000
    1.0000    0.0000    0.0000    0.0000
    0.0000    1.0000    0.0000    0.0000
    0.0000    0.0000    1.0000    0.0000
L:
    1.0000    0.0000    0.0000    0.0000
    0.0769    1.0000    0.0000    0.0000
    0.3846    0.6667    1.0000    0.0000
    0.6923    0.3333   -2.1250    1.0000
U:
   13.0000   14.0000   15.0000   16.0000
    0.0000    0.9231    1.8462    2.7692
    0.0000    0.0000    0.0000    0.0000
    0.0000    0.0000    0.0000   -0.0000
PA=
   13.0000   14.0000   15.0000   16.0000
    1.0000    2.0000    3.0000    4.0000
    5.0000    6.0000    7.0000    8.0000
    9.0000   10.0000   11.0000   12.0000
LU=
   13.0000   14.0000   15.0000   16.0000
    1.0000    2.0000    3.0000    4.0000
    5.0000    6.0000    7.0000    8.0000
    9.0000   10.0000   11.0000   12.0000

No Inverse!
------------------------------------------------------------
------------------------------------------------------------
matrix 5:
    1.0000    2.0000    4.0000   17.0000
    3.0000    6.0000  -12.0000    3.0000
    2.0000    3.0000   -3.0000    2.0000
    0.0000    2.0000   -2.0000    6.0000
P:
    0.0000    1.0000    0.0000    0.0000
    0.0000    0.0000    0.0000    1.0000
    1.0000    0.0000    0.0000    0.0000
    0.0000    0.0000    1.0000    0.0000
L:
    1.0000    0.0000    0.0000    0.0000
    0.0000    1.0000    0.0000    0.0000
    0.3333    0.0000    1.0000    0.0000
    0.6667   -0.5000    0.5000    1.0000
U:
    3.0000    6.0000  -12.0000    3.0000
    0.0000    2.0000   -2.0000    6.0000
    0.0000    0.0000    8.0000   16.0000
    0.0000    0.0000    0.0000   -5.0000
PA=
    3.0000    6.0000  -12.0000    3.0000
    0.0000    2.0000   -2.0000    6.0000
    1.0000    2.0000    4.0000   17.0000
    2.0000    3.0000   -3.0000    2.0000
LU=
    3.0000    6.0000  -12.0000    3.0000
    0.0000    2.0000   -2.0000    6.0000
    1.0000    2.0000    4.0000   17.0000
    2.0000    3.0000   -3.0000    2.0000

Inverse:
    0.3500    0.3500   -0.2000   -1.1000
   -0.3750   -0.5417    1.0000    1.0000
   -0.0750   -0.2417    0.4000    0.2000
    0.1000    0.1000   -0.2000   -0.1000
------------------------------------------------------------
------------------------------------------------------------
matrix 6:
    1.0000    2.0000    3.0000
    1.0000    2.0000    2.0000
P:
    1.0000    0.0000
    0.0000    1.0000
L:
    1.0000    0.0000
    1.0000    1.0000
U:
    1.0000    2.0000    3.0000
    0.0000    0.0000   -1.0000
PA=
    1.0000    2.0000    3.0000
    1.0000    2.0000    2.0000
LU=
    1.0000    2.0000    3.0000
    1.0000    2.0000    2.0000

No Inverse!
------------------------------------------------------------
```

## 原理简单说明

### 矩阵的规模

程序支持任意规模的 $PA=LU$ 分解，假设输入矩阵的规模为 $M \times N$，通过向下消元过程可以知道，当

- $ M \le N$ 时，$P$ 的规模为 $M \times M$，$L$ 的规模为 $M \times M$，$U$ 的规模为 $M \times N$；
- $ M \gt N$ 时，$P$ 的规模为 $M \times M$，$L$ 的规模为 $M \times N$，$U$ 的规模为 $N \times N$；

### 求逆

若矩阵可逆，程序会利用 LU 分解的结果进行求逆，具体查看源码。
