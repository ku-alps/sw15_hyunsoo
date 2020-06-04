import sys, heapq
# 녹색 옷 입은 애가 젤다지?
# 최단 경로를 구하는 문제로 BFS 탐색을 통해 해결
# 다만, 파이썬에 존재하는 'from queue import PriorityQueue' 를 사용했으나
# 백준 상에서는 해당 코드를 사용할 수 없어 'heapq' 로 수정하는 과정을 거침

def Q(s):
    X = [1,0,-1,0]
    Y = [0,-1,0,1] # 좌표 이동 값

    # s*s 짜리 배열 선언
    m = [ [0] * s for _ in range(s)] 
    visit = [ [-1] * s for _ in range(s)] 
    # [[a]*k]*k 로 정의하면, [a]*k 를 동일한 객체로 복사하여 생성

    for i in range(s):
        # 한 줄을 입력받아 공백단위로 나누어 숫자 변경 후, 리스트 형태로 변환
        m[i] = list(map(int, sys.stdin.readline().split(' '))) 

    pq = [] # 우선순위 큐 용 공간
    heapq.heappush(pq, [ m[0][0], 0, 0 ]) # 가장 앞쪽 값을 기준으로 오름차순 정렬
    while pq:
        v, x, y = heapq.heappop(pq) # 값, 좌표

        if visit[x][y] != -1:
            continue # 방문한 곳
        visit[x][y] = v # 방문 표기 (최소값)

        if x == s-1 and y == s-1: # 원하는 위치면 탈출
            break

        for k in range(4): # 네 방향에 대해 시도
            nx = x + X[k]
            ny = y + Y[k]
            if nx in range(s) and ny in range(s): # x,y 가 범위 안에 있다면 삽입
                heapq.heappush(pq, [ v + m[nx][ny], nx, ny ])
    return visit[s-1][s-1]

idx = 1
while True:
    s = int(input())
    if s == 0:
        break
    print(f"Problem {idx}: {Q(s)}") # 형태에 맞춰 출력
    idx += 1 # 인덱스 증가