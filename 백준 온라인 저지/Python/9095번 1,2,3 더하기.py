import sys

def dfs(n, sum):  # 재귀로 해결
    if sum == n:  # 목표값이면 가짓수+1
        return 1
    if sum > n:  # 초과하면 리턴
        return 0
    else:  # 1과 2와 3
        return dfs(n, sum+1) + dfs(n, sum+2) + dfs(n, sum+3)

t = int(sys.stdin.readline())

for i in range(t):
    n = int(sys.stdin.readline())
    print(dfs(n, 0))
