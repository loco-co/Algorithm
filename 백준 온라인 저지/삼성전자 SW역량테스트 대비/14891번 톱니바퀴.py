import sys
T = []
for i in range(4):
    T.append(sys.stdin.readline().strip())
k = int(sys.stdin.readline())

def turn(n, d):
    if d == 1:
        T[n] = T[n][7] + T[n][0:7]
    if d == -1:
        T[n] = T[n][1:8] + T[n][0]

def dfs(n, d):
    if not visited[n]:
        visited[n] = True
        left = T[n][6]
        right = T[n][2]
        turn(n, d)
        if n-1 >= 0 and left != T[n-1][2]:
            dfs(n-1, -d)
        if n+1 <= 3 and right != T[n+1][6]:
            dfs(n+1, -d)

for i in range(k):
    visited = [False] * 4
    t, direct = map(int, sys.stdin.readline().split())
    dfs(t-1, direct)
sum_ = 0
if T[0][0] == '1':
    sum_ += 1
if T[1][0] == '1':
    sum_ += 2
if T[2][0] == '1':
    sum_ += 4
if T[3][0] == '1':
    sum_ += 8
print(sum_)
