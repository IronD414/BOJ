"""별 찍기 - 10"""
import math

n = int(input())
storage = []
for i in range(n):
    storage.append([])
    for j in range(n):
        storage[i].append(" ")

def storing(m, cont, y, x):
    if m == 1:
        for y_a in range(3):
            for x_a in range(3):
                cont[y + y_a][x + x_a] = "*"
        cont[y + 1][x + 1] = " "
    else:
        for gy_a in range(3):
            for gx_a in range(3):
                if gy_a != 1 or gx_a != 1:
                    storing(m-1, cont, y + gy_a * 3**(m-1), x + gx_a * 3**(m-1))


storing(round(math.log(n, 3)), storage, 0, 0)

for i in range(n):
    for j in range(n):
        print(storage[i][j], end="")
    print("\n", end="")