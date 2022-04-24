import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())
graph = []
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
max_ = 0

def virus():
    global max_
    copy = [[0 for j in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(m):
            copy[i][j] = graph[i][j]

    start = []
    for i in range(n):
        for j in range(m):
            if copy[i][j] == 2:
                start.append([i, j])
    queue = deque(start)
    while queue:
        [i, j] = queue.popleft()
        for k in range(4):
            nx = i + dx[k]
            ny = j + dy[k]
            if nx >= 0 and ny >= 0 and nx < n and ny < m:
                if copy[nx][ny] == 0:
                    copy[nx][ny] = 2
                    queue.append([nx, ny])
    result = 0
    for i in range(n):
        for j in range(m):
            if copy[i][j] == 0:
                result += 1
    max_ = max(result, max_)

def wall(cnt):
    if cnt == 3:
        virus()
        return
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                wall(cnt+1)
                graph[i][j] = 0
wall(0)
print(max_)
