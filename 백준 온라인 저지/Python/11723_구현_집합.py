import sys

Set = [0] * 21
def add(a):
    Set[a] = 1

def remove(a):
    Set[a] = 0

def check(a):
    if Set[a]:
        print(1)
    else:
        print(0)

def toggle(a):
    if Set[a]:
        Set[a] = 0
    else:
        Set[a] = 1

def all_f():
    for i in range(1, 21):
        Set[i] = 1

def empty():
    for i in range(1, 21):
        Set[i] = 0

n = int(input())
for i in range(0, n):
    s = sys.stdin.readline().split()
    if s[0] == "add":
        add(int(s[1]))
    if s[0] == "remove":
        remove(int(s[1]))
    if s[0] == "check":
        check(int(s[1]))
    if s[0] == "toggle":
        toggle(int(s[1]))
    if s[0] == "all":
        all_f()
    if s[0] == "empty":
        empty()
