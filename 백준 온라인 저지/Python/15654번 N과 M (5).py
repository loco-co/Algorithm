import sys
n, m = map(int, sys.stdin.readline().split())
array = sorted(list(map(int, sys.stdin.readline().split())))
answer = []
visit = [0] * n
def dfs(x):
    if x == m:
        for j in answer:
            print(j, end=' ')
        print()
    for i in range(n):
        if not visit[i]:
            visit[i] = True
            answer.append(array[i])
            dfs(x+1)
            answer.pop(len(answer)-1)
            visit[i] = False
dfs(0)
