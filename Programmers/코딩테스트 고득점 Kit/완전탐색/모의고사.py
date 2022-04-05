def solution(answers):
    modea = [1,2,3,4,5]
    modeb = [2,1,2,3,2,4,2,5]
    modec = [3,3,1,1,2,2,4,4,5,5]
    score = [0,0,0]
    
    for i in range(len(answers)):
        if answers[i] == modea[i%5]:
            score[0] += 1
    for i in range(len(answers)):
        if answers[i] == modeb[i%8]:
            score[1] += 1
    for i in range(len(answers)):
        if answers[i] == modec[i%10]:
            score[2] += 1
    
    m = max(score)
    answer = []
    if score[0] == m: answer.append(1)
    if score[1] == m: answer.append(2)
    if score[2] == m: answer.append(3)
    return answer
