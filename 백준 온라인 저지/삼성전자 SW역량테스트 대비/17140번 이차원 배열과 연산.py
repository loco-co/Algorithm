from collections import Counter
import sys
r, c, k = map(int, sys.stdin.readline().split())
A = []
cnt = 0
for i in range(3):
    A.append(list(map(int, sys.stdin.readline().split())))

def rop():
    max_len = 0
    for i in range(len(A)):
        temp = Counter(A[i])
        del temp[0]  # 0은 무시
        temp = list(temp.items())  # temp는 튜플들의 리스트 형태
        temp.sort(key=lambda x: (x[1], x[0]))
        A[i] = []  # 비우기
        for first, second in temp:
            A[i].append(first)
            A[i].append(second)
        max_len = max(max_len, len(temp) * 2)

    for i in range(len(A)):  # max까지 채우고 100이상은 커팅하기
        for j in range(max_len - len(A[i])):
            A[i].append(0)
        A[i] = A[i][:100]

for i in range(101):
    try:
        if A[r-1][c-1] == k:
            print(cnt)
            break
    except: pass
    if len(A) >= len(A[0]):
        rop()
    else:
        A = list(zip(*A))  # Transpose
        rop()
        A = list(zip(*A))  # 원래대로
    cnt += 1

if cnt > 100:
    print(-1)
