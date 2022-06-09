import sys
n, m = map(int, sys.stdin.readline().split())
fact = [1] * (n+1)
for i in range(1, n+1):
    fact[i] = fact[i-1] * i
print(fact[n] // (fact[n-m] * fact[m]))
