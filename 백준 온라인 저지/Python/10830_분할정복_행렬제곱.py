import sys
read = sys.stdin.readline  # 놓쳤던 부분1, ()를 치면 여기서 입력을 받아버림

def div(lst, k):
    if k == 1:
        return lst
    c = len(lst)
    result = [[0 for col in range(c)] for row in range(c)]
    result2 = [[0 for col in range(c)] for row in range(c)]
    temp = div(lst, k//2)  # 놓쳤던 부분2, 파이썬에서는 //연산이 정수몫을 구함, /연산시 실수
    if (k % 2) == 0:
        for i in range(c):
            for j in range(c):
                for k in range(c):  # 행렬의 곱셈연산
                    result[i][j] += temp[i][k] * temp[k][j] % 1000  # 오버플로우 발생막기
        return result
    else:  # k가 홀수일때
        for i in range(c):  # 예를들어, k가 5일때 A2을 두개곱하고 A를 한번 더곱함
            for j in range(c):
                for k in range(c):  # 곱셈횟수가 2로 나눠진 배열을 두 번 곱하고
                    result[i][j] += temp[i][k] * temp[k][j] % 1000
        for i in range(c):
            for j in range(c):
                for k in range(c):  # 추가로 A를 한 번 더 곱해주면 정답
                    result2[i][j] += result[i][k] * lst[k][j] % 1000
        return result2

s = read().split()
n = int(s[0])
b = int(s[1])
A = [[0 for col in range(n)] for row in range(n)]

for i in range(n):
    t = read().split()
    for j in range(n):
        A[i][j] = int(t[j])

ans = div(A, b)
for i in range(n):
    for j in range(n):  # accumulate 된 값을 마지막에 한번더 나눠줌
        print(ans[i][j] % 1000, end=" ")
    print()
