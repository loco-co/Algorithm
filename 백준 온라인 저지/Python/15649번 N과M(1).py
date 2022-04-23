import sys
n, m = map(int, sys.stdin.readline().split())

def dfs(k, a, cnt, visit):
    if cnt == a:
        for v in visit:
            print(v, end=' ')
        print()
        return
    for i in range(1, k+1):
        if i not in visit:
            visit.append(i)
            dfs(k, a, cnt+1, visit)
            visit.remove(i)

dfs(n, m, 0, [])
