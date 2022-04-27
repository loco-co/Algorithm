import sys
n, m, x, y, k = map(int, sys.stdin.readline().split())
board = []
for i in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))
cmd = list(map(int, sys.stdin.readline().split()))
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]
stone = [0, 0, 0, 0, 0, 0, 0]

for c in cmd:
    nx = x + dx[c]
    ny = y + dy[c]
    if 0 <= nx < n and 0 <= ny < m:
        if c == 1:
            stone[1], stone[3], stone[4], stone[6] = stone[4], stone[1], stone[6], stone[3]
        elif c == 2:
            stone[1], stone[3], stone[4], stone[6] = stone[3], stone[6], stone[1], stone[4]
        elif c == 3:
            stone[1], stone[2], stone[5], stone[6] = stone[5], stone[1], stone[6], stone[2]
        elif c == 4:
            stone[1], stone[2], stone[5], stone[6] = stone[2], stone[6], stone[1], stone[5]
        if board[nx][ny] == 0:
            board[nx][ny] = stone[6]
        else:
            stone[6] = board[nx][ny]
            board[nx][ny] = 0
        x, y = nx, ny
        print(stone[1])
