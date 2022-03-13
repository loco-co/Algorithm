def solution(n, computers):
    answer = 0
    visit = [0] * n
    def dfs(node):
        if visit[node] != 0: return
        else:
            visit[node] = 1
            for j in range(n):
                if computers[node][j] == 1:
                    dfs(j)
        
    for i in range(n):
        if visit[i] == 0:
            dfs(i)
            answer += 1
    return answer
