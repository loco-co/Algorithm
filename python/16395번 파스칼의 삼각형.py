import sys

n, k = map(int, sys.stdin.readline().split())

Pascal = [[1 for _ in range(i)] for i in range(1, 31)]

for i in range(2, 30):
    for j in range(1, i):
        Pascal[i][j] = Pascal[i-1][j-1] + Pascal[i-1][j]

print(Pascal[n-1][k-1])
