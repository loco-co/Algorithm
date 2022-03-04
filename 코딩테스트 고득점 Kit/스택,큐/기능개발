import math

def solution(progresses, speeds):
    days = []
    for i in range(len(speeds)):
        d = (100 - progresses[i]) / speeds[i]
        d = math.ceil(d)
        days.append(d)
        
    d = days.pop(0)
    temp = 1
    answer = []
    while True:
        if len(days)==0:
            answer.append(temp)
            break
        x = days.pop(0)
        if x <= d:
            temp = temp + 1
        else:
            answer.append(temp)
            d = x
            temp = 1
    return answer
