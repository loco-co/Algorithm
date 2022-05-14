import sys
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
s = sorted(set(a))
dict = {}
for i in range(len(s)):
    dict[s[i]] = i
for i in a:
    print(dict[i], end=' ')
