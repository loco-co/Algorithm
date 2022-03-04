def solution(array, commands):
    answer = []
    for i,j,k in commands:
        _array = array[i-1:j]
        _array.sort()
        answer.append(_array[k-1])
    return answer
