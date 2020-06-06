import collections
# 스타트링크
# Queue 객체는 다중스레드 용으로, 백준에서 사용 불가
# collections 내부에 있는 queue 를 사용

F, S, G, U, D = map(int, input().split()) # 입력
floor = [-1] * (F+1) # F 층 짜리 건물정보 (0층 제외)

# collections 내부에 있는 자료구조 deque()
q = collections.deque()
q.append([S, 0]) # append 는 입력값을 하나의 뭉텅이로 삽입
while q:
    pos, val = q.popleft()
    if floor[pos] != -1:
        continue
    floor[pos] = val # 현재 위치에 도달하는데 걸린 횟수

    # 엘리베이터 상하 이동
    if pos + U <= F:
        q.append([pos+U, val+1]) 
    if pos - D > 0:
        q.append([pos-D, val+1]) 

print(floor[G] if floor[G] != -1 else "use the stairs")