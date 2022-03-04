def solution(n, lost, reserve):
    lost.sort()

    _lost = [l for l in lost if l not in reserve]
    _reserve = [r for r in reserve if r not in lost]
    cnt = n - len(_lost)
    
    for l in _lost:
        if l-1 in _reserve:
            _reserve.remove(l-1)
            cnt = cnt + 1
        elif l+1 in _reserve:
            _reserve.remove(l+1)
            cnt = cnt + 1
    return cnt
