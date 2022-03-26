import sys

n = int(sys.stdin.readline())
wordlist = []

for i in range(n):
    a = sys.stdin.readline().strip()
    wordlist.append(a)

wordlist.sort()  # 하위 조건 정렬
wordlist.sort(key=len)  # 상위 조건 정렬
wordlist.append('0')

for i in range(n):
    if wordlist[i] != wordlist[i+1]:
        print(wordlist[i])
