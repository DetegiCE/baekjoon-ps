import numpy as np

a = [[0.0 for _ in range(10)] for _ in range(10)]
for i in range(10):
    a[0][i] = a[i][0] = a[i][9] = a[9][i] = 1
print(np.array(a))

a = [[0 for _ in range(8)] for _ in range(8)]
for i in range(8):
    for j in range(8):
        if (i+j)%2 == 1:
            a[i][j] = 1
print(np.array(a))
