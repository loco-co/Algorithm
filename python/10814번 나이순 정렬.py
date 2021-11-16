import sys

n = int(sys.stdin.readline())

member = []

for i in range(n):
    age, name = sys.stdin.readline().strip().split()
    age = int(age)
    member.append((age, name))

members = sorted(member, key=lambda member: member[0])

for i in range(n):
    print(members[i][0], members[i][1])
