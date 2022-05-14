import sys
n, m = map(int, sys.stdin.readline().split())
dict = {}
for i in range(1, n+1):
    name = sys.stdin.readline().strip()
    dict[i] = name
    dict[name] = i
for i in range(m):
    t = sys.stdin.readline().strip()
    if t.isdigit():
        print(dict[int(t)])
    else:
        print(dict[t])
