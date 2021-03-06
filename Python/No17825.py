import heapq
# 주사위 윷놀이
# 완전 탐색이지만, 어떠한 수식으로 규칙화하기 굉장히 힘듦
# so, 각 위치별 이동해야 하는 좌표를 모두 기록해 둔 후,
# 반복문으로 처리

# 다만, 변수명 설정에서 중복이 발생해서 찾는데 헤멤

rule = ( # 해당 칸의 점수, 넘어갈 위치 규칙 2개 (시작점인 경우, 중간에 거치는 경우)
    [0,1,1], # 0 (출발점)
    [2,2,2], [4,3,3], [6,4,4], [8,5,5], [10,22,6], # 1~5
    [12,7,7], [14,8,8], [16,9,9], [18,10,10], [20,25,11], # 6~10
    [22,12,12], [24,13,13], [26,14,14], [28,15,15], [30,27,16], # 11~15
    [32,17,17], [34,18,18], [36,19,19], [38,20,20], [40,21,21], # 16~20
    [0,21,21], # 21 (도착점)
    [13,23,23], [16,24,24], [19,30,30], # 22~24
    [22,26,26], [24,30,30], # 25~26
    [28,28,28], [27,29,29], [26,30,30], # 27~29
    [25,31,31], [30,32,32], [35,20,20], # 30~32
)

dices = list(map(int, input().split()))
pq = [[0,0,0,0,0]] # 점수, 네 말의 위치 
for dice in dices: # 주사위 값
    sub_pq = []
    while pq:
        s, a, b, c, d = heapq.heappop(pq)
        players = [a,b,c,d] # 말의 위치들

        for idx, pos in enumerate(players):
            pos = rule[pos][1] # 첫 움직임은 예외처리
            for k in range(1,dice):
                pos = rule[pos][2] # 남은 주사위 이동

            if pos != 21 and pos in players: # 도착점이 아닌데, 중복이 생긴다면
                continue # 무시

            # 새로운 데이터 생성 후, 우선순위 큐에 삽입
            nset = players[:]
            nset[idx] = pos # 위치 변경한 새로운 집합
            nset.insert(0,s-rule[pos][0]) # 우선순위 큐의 오름차순을 위해, 값을 음수로 합산
            heapq.heappush(sub_pq, nset)
    pq = sub_pq # 서브 큐로 내용물 치환
print(-heapq.heappop(pq)[0]) # 양수로 출력