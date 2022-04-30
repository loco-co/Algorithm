import sys
n, am, k = map(int, sys.stdin.readline().split())
fire = []
MAP = [[[] for j in range(n)] for i in range(n)]
for i in range(am):
    r, c, m, s, d = list(map(int, sys.stdin.readline().split()))
    fire.append([r-1, c-1, m, s, d])
# x, y, 질량, 속력, 방향 순
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

for i in range(k):
    for j in range(len(fire)):  # 이동
        x, y, m, s, d = fire.pop(0)
        nx = (x + dx[d] * s) % n
        ny = (y + dy[d] * s) % n
        MAP[nx][ny].append([m, s, d])

    for a in range(n):
        for b in range(n):
            if len(MAP[a][b]) > 1:
                M, S, odd, even, len_m = 0, 0, 0, 0, len(MAP[a][b])
                while MAP[a][b]:
                    m, s, d = MAP[a][b].pop(0)
                    M += m
                    S += s
                    if (d % 2) == 0:
                        even += 1
                    else:
                        odd += 1
                nm = M // 5
                ns = S // len_m
                if nm == 0:
                    MAP[a][b] = []
                    continue
                if odd == 0 or even == 0:
                    for c in range(4):
                        fire.append([a, b, nm, ns, c*2])
                else:
                    for c in range(4):
                        fire.append([a, b, nm, ns, c*2+1])
            if len(MAP[a][b]) == 1:
                fire.append([a, b] + MAP[a][b].pop())

answer = 0
for a, b, m, s, d in fire:
    answer += m
print(answer)
