import sys

n = int(sys.stdin.readline())
T = []
P = []
for i in range(n):
    t, p = map(int, sys.stdin.readline().split())
    T.append(t)
    P.append(p)
DP = [0 for i in range(n+1)]

for i in range(n-1, -1, -1):
    if T[i] + i > n:
        DP[i] = DP[i+1]
    else:
        DP[i] = max(DP[i+1], DP[i + T[i]] + P[i])

print(DP[0])
