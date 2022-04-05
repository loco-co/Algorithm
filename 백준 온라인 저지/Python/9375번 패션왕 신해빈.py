import sys

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    wear = dict()

    for _ in range(n):
        name, type = sys.stdin.readline().split()
        if type in wear.keys():  # 있던 타입이면
            wear[type] += 1  # 그 타입의 숫자를 1 증가
        else:  # 없던 타입이면
            wear[type] = 1  # 새로 타입을 추가

    result = 1
    for key in wear.keys():  # (옷의 수 + 안 입는 경우 1)을 전부 곱함
        result = result * (wear[key] + 1)

    print(result - 1)  # 아무것도 안 입은 경우
