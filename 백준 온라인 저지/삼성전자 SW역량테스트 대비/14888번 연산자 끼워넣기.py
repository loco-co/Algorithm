import sys
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
op = list(map(int, sys.stdin.readline().split()))

max_ = -1000000000
min_ = 1000000000

def dfs(result, cnt, add, minus, mul, div):
    global max_
    global min_
    if cnt == n:
        max_ = max(result, max_)
        min_ = min(result, min_)
        return
    if add:
        dfs(result+A[cnt], cnt+1, add-1, minus, mul, div)
    if minus:
        dfs(result-A[cnt], cnt+1, add, minus-1, mul, div)
    if mul:
        dfs(result*A[cnt], cnt+1, add, minus, mul-1, div)
    if div:
        dfs(result//A[cnt] if result > 0 else -(-result//A[cnt]), cnt+1, add, minus, mul, div-1)

dfs(A[0], 1, op[0], op[1], op[2], op[3])
print(max_)
print(min_)
