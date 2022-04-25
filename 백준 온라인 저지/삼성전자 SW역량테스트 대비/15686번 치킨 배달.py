import sys
from itertools import combinations
n, m = map(int, sys.stdin.readline().split())
city = []
chicks = []
house = []
for i in range(n):
    city.append(list(map(int, sys.stdin.readline().split())))
for i in range(n):
    for j in range(n):
        if city[i][j] == 2:
            chicks.append([i, j])
        if city[i][j] == 1:
            house.append([i, j])

answer = 10000000
c = combinations(chicks, m)
for pair in c:
    sum_ = 0
    for [i, j] in house:
        min_d = 100000
        for [k, l] in pair:
            min_d = min(abs(k - i) + abs(l - j), min_d)
        sum_ += min_d
    answer = min(answer, sum_)

print(answer)
