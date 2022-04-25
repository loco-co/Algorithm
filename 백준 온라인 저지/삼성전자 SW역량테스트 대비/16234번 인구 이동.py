import sys
from collections import deque
n, l, r = map(int, sys.stdin.readline().split())
land = []
for i in range(n):
    land.append(list(map(int, sys.stdin.readline().split())))
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
days = 0

def bfs(i, j):
    queue = deque()
    queue.append([i, j])
    union = [[i, j]]
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                diff = abs(land[x][y] - land[nx][ny])
                if l <= diff <= r:
                    visited[nx][ny] = True
                    queue.append([nx, ny])
                    union.append([nx, ny])
    return union

while True:
    isTrue = False
    visited = [[False for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                visited[i][j] = True
                union = bfs(i, j)
                if len(union) > 1:
                    isTrue = True
                    result = sum(land[k][l] for k, l in union) // len(union)
                    for [x, y] in union:
                        land[x][y] = result
    if not isTrue:
        break
    days += 1
print(days)
#  dfs로도 구현하기
