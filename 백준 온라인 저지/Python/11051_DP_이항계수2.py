import sys
s = input().split()
n = int(s[0])
k = int(s[1])
B = [[0 for cor in range(1001)] for row in range(1001)]
for i in range(0, 1001):
    B[i][0] = 1
B[1][1] = 1
for i in range(2, 1001):
    for j in range(1, 1001):
        B[i][j] = (B[i-1][j-1] + B[i-1][j]) % 10007  # 중간에 나눠줘도 결과가 보장됨
print(B[n][k])
