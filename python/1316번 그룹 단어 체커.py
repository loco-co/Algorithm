import sys
n = int(sys.stdin.readline())
answer = 0

for i in range(n):
    s = sys.stdin.readline()
    visit = []
    for i in range(len(s)-1):
        if s[i] in visit and s[i] != s[i-1]: break
        if s[i] != s[i+1]:
            visit.append(s[i])
        if i == len(s)-2: answer += 1

print(answer)
