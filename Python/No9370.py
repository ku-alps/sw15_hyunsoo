import sys, heapq, copy
# 미확인 도착지
# 다익스트라를 응용한 문제 풀이
# 최단거리를 구상하는데 사용된 노드들을 모두 기록하였으나, 메모리 초과
# so, 단순히 조건 엣지를 사용했는지 여부만을 기록하는 방식으로 수정

for _ in range(int(sys.stdin.readline())):
    N, M, T = map(int, sys.stdin.readline().split()) # 교차로, 도로, 목적지 후보
    S, G, H = map(int, sys.stdin.readline().split()) # 출발지, G-H 도로

    link = [list() for _ in range(N+1)] # 경로 세팅
    weight, visit = [[-1 for _ in range(N+1)] for _ in range(2)]
    for _ in range(M):
        A, B, D = map(int, sys.stdin.readline().split())
        link[A].append([B,D])
        link[B].append([A,D]) # A-B 사이에 거리 D 의 경로가 존재

    # 해당 G-H 엣지를 사용했는가?
    func = lambda a: a in [[G,H], [H,G]]

    pq = [[0,0,S]] # 다익스트라 (가중치, 부모, 자식)
    visit[0] = 0 # 예외처리를 위한 기본값
    while pq:
        v, prnt, child = heapq.heappop(pq)
        if weight[child] != -1: # 방문한 곳이면 무시
            if weight[child] == v: # 동일한 비용으로 올 수 있는 경로면 엣지 사용 확인
                visit[child] = 1 if func([prnt, child]) else max(visit[child], visit[prnt])
            continue
        weight[child] = v # 해당 노드까지의 최저 비용
        visit[child] = (1 if func([prnt, child]) else visit[prnt])
        for n, D in link[child]: # 탐색
            heapq.heappush(pq, [v+D, child, n])

    ans = []
    arrivals = list(map(int,[ sys.stdin.readline() for _ in range(T) ]))
    for arrival in arrivals: # 입력받은 모든 후보군을 정렬
        if visit[arrival] == 1:
            heapq.heappush(ans, arrival)
    while ans: # 엣지 사용 조건을 만족한다면 출력
        sys.stdout.write(f"{heapq.heappop(ans)} ")
    sys.stdout.write("\n")