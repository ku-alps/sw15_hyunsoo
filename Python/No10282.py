import heapq
# 해킹
# 우선순위 큐를 사용한 BFS 탐색

for _ in range(int(input())): # 반복
    N, D, C = map(int, input().split()) # 노드 수, 링크 수, 감염시작지

    # 연결 엣지 정보, 방문 정보
    link, visit = [[ [] for _ in range(N+1) ] for _ in range(2)]
    for _ in range(D):
        A, B, S = map(int, input().split())
        link[B].append([A, S]) # B 가 감염되면 S 초 후, A 도 감염

    ans = [0, 0]
    pq = [[0, C]] # 시간, 현재 컴퓨터 번호
    while pq:
        time, idx = heapq.heappop(pq)
        if visit[idx]:
            continue # 빈 배열이 아니라면 이전에 왔었음
        visit[idx].append(0)
        ans = [ ans[0]+1, time ] # 오름차순이므로, 가장 마지막에 등장한 시간이 필요한 최소시간
        for B, S in link[idx]:
            heapq.heappush(pq, [time+S, B])
    print(ans[0],ans[1])