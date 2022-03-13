def solution(priorities, location):
    answer = 0
    while priorities:
        if priorities[0] >= max(priorities):
            if location == 0: return answer + 1
            answer += 1
            priorities.pop(0)
            location -= 1
        else:
            if location == 0: location = len(priorities)-1
            else: location -= 1
            priorities.append(priorities[0])
            priorities.pop(0)
