def solution(participant, completion):
    participant.sort()
    completion.sort()
    n = len(completion)
    i = 0
    for p in participant:
        if p != completion[i] or i > n:
            answer = p
            break
        i += 1
    return answer
