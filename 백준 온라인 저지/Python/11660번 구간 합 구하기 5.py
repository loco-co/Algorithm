import sys
n, m = map(int, sys.stdin.readline().split())
board = []
for i in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))

sum = [[0 for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        sum[i][j] = sum[i][j-1] + board[i][j]

for i in range(m):
    answer = 0
    x1, x2, y1, y2 = map(int, sys.stdin.readline().split())
    for x in range(x1-1, y1):
        if x2 == 1: answer += sum[x][y2-1]
        else: answer += sum[x][y2-1] - sum[x][x2-2]
    print(answer)
