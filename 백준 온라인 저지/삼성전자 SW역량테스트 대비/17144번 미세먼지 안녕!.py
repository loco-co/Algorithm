import sys
r, c, t = map(int, sys.stdin.readline().split())
room = []
air = []
for i in range(r):
    room.append(list(map(int, sys.stdin.readline().split())))
for i in range(r):
    for j in range(c):
        if room[i][j] == -1:
            air.append([i, j])
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def dust():
    origin = []
    for i in range(r):
        for j in range(c):
            if room[i][j] > 0:
                origin.append([i, j])
    new_room = [[0] * c for i in range(r)]
    for i in range(r):
        for j in range(c):
            new_room[i][j] = room[i][j]
    for x, y in origin:
        dusts = room[x][y] // 5
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if room[nx][ny] != -1:
                    if new_room[x][y] < 0:
                        print("에러")
                    new_room[nx][ny] += dusts
                    new_room[x][y] -= dusts
    return new_room

def clockwork():
    new_room = [[0] * c for i in range(r)]
    for i in range(r):
        for j in range(c):
            new_room[i][j] = room[i][j]
    d = 3
    x, y = air[1]
    while True:
        nx = x + dx[d]
        ny = y + dy[d]
        if 0 <= nx < r and 0 <= ny < c:
            if room[nx][ny] == -1:
                break
            if room[x][y] == -1:
                new_room[nx][ny] = 0
                x = nx
                y = ny
            else:
                new_room[nx][ny] = room[x][y]
                x = nx
                y = ny
        else:
            d = (d + 3) % 4
    return new_room

def clockreverse():
    new_room = [[0] * c for i in range(r)]
    for i in range(r):
        for j in range(c):
            new_room[i][j] = room[i][j]
    d = 3
    x, y = air[0]
    while True:
        nx = x + dx[d]
        ny = y + dy[d]
        if 0 <= nx < r and 0 <= ny < c:
            if room[nx][ny] == -1:
                break
            if room[x][y] == -1:
                new_room[nx][ny] = 0
                x = nx
                y = ny
            else:
                new_room[nx][ny] = room[x][y]
                x = nx
                y = ny
        else:
            d = (d + 1) % 4
    return new_room

while True:
    t -= 1
    room = dust()
    room = clockwork()
    room = clockreverse()
    if t == 0:
        print(sum(room[i][j] for j in range(c) for i in range(r)) + 2)
        break
