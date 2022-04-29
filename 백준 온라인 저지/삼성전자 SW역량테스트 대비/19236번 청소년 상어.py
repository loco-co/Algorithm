import sys
import copy
board = [[] for i in range(4)]
for i in range(4):
    temp = list(map(int, sys.stdin.readline().split()))
    fish_row = []
    for j in range(4):
        fish_row.append([temp[j*2], temp[j*2+1] - 1])
    board[i] = fish_row
dx = [-1, -1, 0, 1, 1, 1, 0, -1]  # 북부터 시작
dy = [0, -1, -1, -1, 0, 1, 1, 1]
max_fish = 0

def dfs(sx, sy, score, board):
    global max_fish
    score += board[sx][sy][0]
    board[sx][sy][0] = 0
    max_fish = max(score, max_fish)

    for n in range(1, 17):
        x, y = -2, -2
        for i in range(4):
            for j in range(4):
                if board[i][j][0] == n:
                    x, y = i, j
                    break
        if x == -2 and y == -2:
            continue
        d = board[x][y][1]

        for k in range(8):
            nd = (d + k) % 8
            nx = x + dx[nd]
            ny = y + dy[nd]
            if 0 <= nx < 4 and 0 <= ny < 4 and not (nx == sx and ny == sy):
                board[x][y][1] = nd
                board[x][y], board[nx][ny] = board[nx][ny], board[x][y]
                break

    sd = board[sx][sy][1]
    for i in range(1, 4):
        nx = sx + dx[sd]*i
        ny = sy + dy[sd]*i
        if 0 <= nx < 4 and 0 <= ny < 4 and board[nx][ny][0] > 0:
            dfs(nx, ny, score, copy.deepcopy(board))

dfs(0, 0, 0, board)
print(max_fish)
