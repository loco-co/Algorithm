import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while scoville[0] < K:
        if len(scoville) < 2 or scoville[0] == 0: return -1
        heapq.heappush(scoville, heapq.heappop(scoville) + heapq.heappop(scoville)*2)
        answer += 1
    return answer
