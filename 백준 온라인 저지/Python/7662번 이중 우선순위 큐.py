import sys
import heapq
input = sys.stdin.readline
t = int(input())
while t:
    t -= 1
    k = int(input())
    min_heap, max_heap = [], []
    visit = [0] * k
    for i in range(k):
        cmd, num = input().split()
        num = int(num)
        if cmd == 'I':
            heapq.heappush(min_heap, (num, i))
            heapq.heappush(max_heap, (-num, i))
            visit[i] = True
        if cmd == 'D':
            if num == -1:
                while min_heap and not visit[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    visit[min_heap[0][1]] = False
                    heapq.heappop(min_heap)
            if num == 1:
                while max_heap and not visit[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    visit[max_heap[0][1]] = False
                    heapq.heappop(max_heap)

    while min_heap and not visit[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not visit[max_heap[0][1]]:
        heapq.heappop(max_heap)
    if not min_heap: print('EMPTY')
    else: print(-max_heap[0][0], min_heap[0][0])
