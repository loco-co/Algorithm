import sys
from collections import deque
n = int(sys.stdin.readline())
sea = []
for i in range(n):
    sea.append(list(map(int, sys.stdin.readline().split())))
shark = [0, 0]
for i in range(n):
    for j in range(n):
        if sea[i][j] == 9:
            shark[0] = i
            shark[1] = j
            sea[i][j] = 0
size, eat, time = 2, 0, 0
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def bfs(i, j):
    visited = [[False] * n for i in range(n)]
    dist = [[0] * n for i in range(n)]
    fish_list = []
    queue = deque()
    queue.append([i, j])
    visited[i][j] = True
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and 0 <= sea[nx][ny] <= size:
                visited[nx][ny] = True
                queue.append([nx, ny])
                dist[nx][ny] = dist[x][y] + 1
                if 0 < sea[nx][ny] < size:
                    fish_list.append([nx, ny, dist[nx][ny]])
    fish_list.sort(key=lambda x: (x[2], x[0], x[1]))
    return fish_list

while True:
    flist = bfs(shark[0], shark[1])
    if len(flist) == 0:
        break
    x, y, d = flist[0]
    sea[x][y] = 0
    shark[0] = x
    shark[1] = y
    time += d
    eat += 1
    if eat == size:
        size += 1
        eat = 0

print(time)
