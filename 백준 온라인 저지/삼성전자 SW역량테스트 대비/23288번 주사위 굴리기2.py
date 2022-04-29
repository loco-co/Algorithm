import sys
from collections import deque
n, m, k = map(int, sys.stdin.readline().split())
board = []
for i in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))
dx = [0, 1, 0, -1]  # 동, 남, 서, 북 순서
dy = [1, 0, -1, 0]
dice = [0, 1, 2, 3, 4, 5, 6]
x, y, d, result = 0, 0, 0, 0

def score(i, j):
    visited = [[False for p in range(m)] for l in range(n)]
    queue = deque()
    queue.append([i, j])
    visited[i][j] = True
    cnt = 1
    num = board[i][j]
    while queue:
        [a, b] = queue.popleft()
        for i in range(4):
            na = a + dx[i]
            nb = b + dy[i]
            if 0 <= na < n and 0 <= nb < m and not visited[na][nb]:
                visited[na][nb] = True
                if board[na][nb] == num:
                    queue.append([na, nb])
                    cnt += 1
    return cnt * num

for i in range(k):
    nx = x + dx[d]
    ny = y + dy[d]
    if nx < 0 or nx >= n or ny < 0 or ny >= m:
        d = (d + 2) % 4
    nx = x + dx[d]
    ny = y + dy[d]
    result += score(nx, ny)
    if d == 0:
        dice[1], dice[3], dice[6], dice[4] = dice[4], dice[1], dice[3], dice[6]
    elif d == 2:
        dice[1], dice[3], dice[6], dice[4] = dice[3], dice[6], dice[4], dice[1]
    elif d == 1:
        dice[1], dice[5], dice[6], dice[2] = dice[2], dice[1], dice[5], dice[6]
    elif d == 3:
        dice[1], dice[5], dice[6], dice[2] = dice[5], dice[6], dice[2], dice[1]

    if dice[6] > board[nx][ny]:
        d = (d + 1) % 4
    elif dice[6] < board[nx][ny]:
        d = (d + 3) % 4
    else:
        pass
    x, y = nx, ny

print(result)
