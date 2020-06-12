# 운동
# 플로이드-워셜 알고리즘을 사용 ( 모든 지점에서, 모든 곳까지의 최단거리 )

INF = 400 * 10000 # 400 개의 노드, 각각 최대 1만
V, E = map(int, input().split())
w = [[INF] * (V+1) for _ in range(V+1)] # 최단 경로 값

for k in range(1, V+1): # 자기 자신으로의 경로는 0 (초기화)
    w[k][k] = 0

for _ in range(E): # 입력
    A, B, C = map(int, input().split())
    w[A][B] = C

for a in range(1, V+1): # 플로이드-워셜
    for b in range(1, V+1):
        for c in range(1, V+1):
            w[b][c] = min(w[b][c], w[b][a] + w[a][c])

ans = INF
for a in range(1, V+1): # 정답 도출 (왕복 경로에 대한 최단경로)
    for b in range(1, V+1):
        if a == b:
            continue
        ans = min(ans, w[a][b] + w[b][a])
print(ans if ans != INF else -1)