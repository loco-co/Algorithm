import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

Fib = [i for i in range(41)]
Fib[0] = 1
for i in range(2, 41):
    Fib[i] = Fib[i-2] + Fib[i-1]

vip = [0]
for i in range(k):
    v = int(sys.stdin.readline())
    vip.append(v)
vip.append(n+1)

answer = 1
for i in range(len(vip)-1):
    if vip[i+1] - vip[i] - 1 > 0:
        answer *= Fib[vip[i+1] - vip[i] - 1]
print(answer)
