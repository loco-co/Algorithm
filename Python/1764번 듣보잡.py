import sys

n, m = map(int, sys.stdin.readline().split())
a = set()
b = set()

for _ in range(n):
    a.add(sys.stdin.readline().strip())

for _ in range(m):
    b.add(sys.stdin.readline().strip())

a = a.intersection(b)
a = sorted(a)

print(len(a))
for i in a:
    print(i)
