import sys
n = int(sys.stdin.readline())
answer = 0
row = [-1] * n

def promising(depth):
    for i in range(depth):
        if row[depth] == row[i] or abs(row[depth] - row[i]) == abs(depth - i):
            return False  # 같은 열이거나 같은 대각선이면
    else: return True

def dfs(depth):
    global answer
    if depth == n:
        answer += 1
        return
    for i in range(n):
        row[depth] = i
        if promising(depth):
            dfs(depth+1)
        row[depth] = -1

dfs(0)
print(answer)
