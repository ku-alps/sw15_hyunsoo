import collections
# 거짓말
# 그래프 탐색 문제 ( queue 사용 )
# int 타입의 list 선언이 불가능하므로,
# str 형태로 삽입 후, int 타입으로 변환하여 사용
# append = 형식 그대로 추가 / extend = 분리해서 추가

visit = [ False for _ in range(50) ] # 파티별 거짓말 가능한 여부
join = [ [] for _ in range(51) ] # 손님 k 가 참가한 파티 수

N, M = map(int, input().split())
fact = list(map(int,input().split()))[1:] # 첫 값을 제외한 나머지는 진실을 아는 사람들 번호
party = list(list(map(int, input().split()[1:])) for _ in range(M)) # 참가자 목록

for i,a in enumerate(party):
    for b in a:
        join[b].append(str(i)) # b는 i번째 파티에 참가함

ans = collections.deque() # 큐 생성
for f in fact:
    ans.extend(join[f]) # 진실을 아는 자들이 참여한 파티리스트 전부 삽입
while ans:
    p = int(ans.popleft())
    if visit[p]:
        continue
    visit[p] = True
    for person in party[p]:
        ans.extend(join[person]) # 해당 사람이 참여한 모든 파티번호를 삽입

sum = 0
for k in range(M):
    if not visit[k]: # 큐에 속한적이 없다면 거짓말 가능
        sum += 1
print(sum) # 정답 출력