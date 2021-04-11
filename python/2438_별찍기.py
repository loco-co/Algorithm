import sys

n = int(sys.stdin.readline())
for i in range(1, n+1):
    for j in range(0, i):
        print("*", end='')
    print("")
