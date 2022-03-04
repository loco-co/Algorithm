def solution(participant, completion):
    total = 0
    dic = {}
    for p in participant:
        dic[hash(p)] = p
        total += int(hash(p))
    for c in completion:
        total -= int(hash(c))
    answer = dic[total]
    return answer
