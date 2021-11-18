import numpy as np
import math

# 不使用科学计数法显示数字
np.set_printoptions(suppress=True)


def read_input(filename):
    """读取输入文件

    Args:
        filename (string): 输入文件名

    Returns:
        numpy.ndarray: 多个矩阵组成的列表
    """
    matrices = []
    with open(filename, "r") as f:
        lines = f.readlines()
        matrix = []
        for line in lines:
            nums = line.strip().split()  # 分割一行数字
            if len(nums) == 0:  # 分割行，表示读完一个矩阵
                matrices.append(np.array(matrix))  # 添加到矩阵列表中
                matrix = []
                continue
            row = [float(num) for num in nums]  # 转为数字
            matrix.append(row)
        if len(matrix) != 0:
            matrices.append(np.array(matrix))

    return matrices  # 返回numpy矩阵


def lu(Matrix):
    """任意规模矩阵的PA=LU分解

    Args:
        Matrix (numpy.ndarray): 输入矩阵，规模为 MxN

    Returns:
        numpy.ndarray: P, L, U
    """
    # 0. 使用副本操作，避免修改原矩阵
    Mat = Matrix.copy().astype("float64")

    # 1. 判断输入形状，决定P，L，U的规模
    M, N = Mat.shape
    P = np.identity(M)  # P初始化为规模为MxM的单位矩阵
    if M <= N:  # M<=N时，L的规模为MxM，U的规模为MxN
        L = np.zeros((M, M))
        I = np.identity(M)  # 用于将对角线元素置1
    else:  # M>N时，L的规模为MxN，U的规模为NxN
        L = np.zeros((M, N))
        I = np.identity(M)[:, :N]  # 用于将对角线元素置1

    # 2. 使用部分主元法进行LU分解
    for i in range(min(M, N)):

        idx = np.argmax(Mat[i:, i]) + i  # 主元最大的行下标

        if (math.isclose(Mat[idx, i], 0, rel_tol=1e-10)):  # 当前列找不到大于0的主元
            continue

        Mat[[i, idx]] = Mat[[idx, i]]  # 交换行
        L[[i, idx]] = L[[idx, i]]  # L矩阵也需要交换对应的行
        P[[i, idx]] = P[[idx, i]]  # P矩阵也需要交换对应的行

        for j in range(i+1, M):
            multiplier = Mat[j, i] / Mat[i, i]  # 倍乘系数
            Mat[j] -= Mat[i] * multiplier  # 倍加消元
            Mat[j, i] = 0  # 主元以下全为0
            L[j, i] = multiplier  # 更新L矩阵

    U = Mat[:min(M, N)]  # U取化简后Mat的上三角部分
    # U = np.round(Mat[:min(M, N)], 5)  # U取化简后Mat的上三角部分，保留五位小数
    L += I  # L的对角线元素置为1

    return P, L, U


def invL(L):
    """求解L的逆"""
    N = L.shape[0]
    L_inv = np.identity(N)  # 增广矩阵
    # 对每列消元，生成逆矩阵
    for i in range(N):
        for j in range(i+1, N):
            L_inv[j] -= L_inv[i] * L[j, i]  # 向下消元

    return L_inv


def invU(U):
    """求解U的逆"""
    N = U.shape[0]
    U_inv = np.identity(N)  # 增广矩阵
    # 对每列消元，生成逆矩阵
    for i in reversed(range(N)):
        U_inv[i] /= U[i, i]  # 除以对角元素
        for j in range(i):
            U_inv[j] -= U_inv[i] * U[j, i]  # 向上消元

    return U_inv


def invUsePLU(P, L, U):
    """利用LU分解求逆"""
    return invU(U) @ invL(L) @ P


def print_matrix(matrix):
    """打印矩阵"""
    print("\n".join("".join(
        f'{num:10.4f}' for num in row) for row in matrix))


def print_mplu(matrices):
    """打印原始矩阵和PLU矩阵"""
    for idx, m in enumerate(matrices):
        print("-"*60)
        print(f"matrix {idx+1}:")
        print_matrix(m)
        P, L, U = lu(m)
        print("P:")
        print_matrix(P)
        print("L:")
        print_matrix(L)
        print("U:")
        print_matrix(U)
        print("PA=")
        print_matrix(P @ m)
        print("LU=")
        print_matrix(L @ U)
        # 如果矩阵可逆就计算矩阵的逆
        if m.shape[0] == m.shape[1] and np.linalg.matrix_rank(m) == m.shape[0]:
            print("\nInverse:")
            print_matrix(invUsePLU(P, L, U))
        else:
            print("\nNo Inverse!")
        print("-"*60)


if __name__ == "__main__":
    matrices = read_input("input.txt")  # 读取输入
    print_mplu(matrices)  # 进行LU分解并输出结果
