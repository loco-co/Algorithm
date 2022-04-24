import sys
n, m = map(int, sys.stdin.readline().split())
x, y, d = map(int, sys.stdin.readline().split())
graph = []
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))
answer = 0
cnt = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
while True:
    if graph[x][y] == 0:
        graph[x][y] = 2
        answer += 1
    nd = (d + 3) % 4
    if graph[x + dx[nd]][y + dy[nd]] == 0:
        x = x + dx[nd]
        y = y + dy[nd]
        d = (d + 3) % 4
        cnt = 0
    else:
        cnt += 1
        d = (d + 3) % 4
    if cnt == 4:
        bd = (d + 2) % 4
        x = x + dx[bd]
        y = y + dy[bd]
        cnt = 0
        if graph[x][y] == 1:
            print(answer)
            break
#  재귀로 풀어보기
