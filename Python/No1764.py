import bisect
# 듣보잡

N, M = map(int, input().split())
listen = sorted([ input() for _ in range(N) ]) # 듣지 못한 사람
see = sorted([ input() for _ in range(M) ]) # 보지 못한 사람

people = []
for name in listen:
    idx = bisect.bisect_left(see, name) # 이분 탐색
    if idx != len(see): # 범위 초과가 아니고
        if see[idx] == name: # 이름이 있다면
            people.append(name)

print(len(people)) # 듣보잡 수
for person in people:
    print(person) # 각 이름