import time
import numpy as np

m = np.full((500, 500), 7)


def multiply_matrices_using_for_loops(m1, m2):
    result = []
    for i in range(len(m1)):
        row = []
        for j in range(len(m2)):
            prod = 0
            for k in range(len(m1[i])):
                prod += m1[i][k] * m2[k][j]
            row.append(prod)
        result.append(row)
    return result


# 2.1)
def forever(matrix1, matrix2):
    t0 = time.time()
    multiply_matrices_using_for_loops(matrix1, matrix2)
    t1 = time.time()
    return t1 - t0


# 2.2)
def mat_fast(matrix1, matrix2):
    t0 = time.time()
    np.dot(matrix1, matrix2)
    t1 = time.time()
    return t1 - t0

t_for = forever(m, m)
t_dot = mat_fast(m, m)

print('2.1)')
print('Rank 500 matrix multiplication time using for loops: {} seconds.'.format(t_for))
print('\n2.2)')
print('Rank 500 matrix multiplication time using numpy.dot: {} seconds.'.format(t_dot))
print('\n2.3)')
print('for loops vs dot product computational difference: {} seconds'.format(t_for - t_dot))
