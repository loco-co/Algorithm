import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    s, e = map(int, sys.stdin.readline().split())
    graph[s].append(e)
    graph[e].append(s)  # 양방향 그래프 입력받기
visit = [False] * (n+1)
for i in range(n+1):
    graph[i].sort()

def dfs(graph, v):
    visit[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visit[i]:
            dfs(graph, i)

def bfs(graph, v):
    queue = deque([v])
    visit = [False] * (n+1)
    visit[v] = True
    print(v, end=' ')
    while queue:
        edge = queue.popleft()
        for i in graph[edge]:
            if not visit[i]:
                visit[i] = True
                print(i, end=' ')
                queue.append(i)

dfs(graph, v)
print()
bfs(graph, v)
