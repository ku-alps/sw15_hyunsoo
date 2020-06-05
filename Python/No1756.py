import sys, bisect
# 피자 굽기
# 결국 특정 위치에 도달하는 피자의 크기는,
# 그 이전의 모든 구멍보다 크기가 작아야한다는 조건이 붙음
# so, 해당 정보만을 갖도록 수정 후, 이분탐색으로 위치를 찾아감

# 초기에는 list.pop(idx) 함수를 사용했으나,
# O(n) 의 시간을 소모하므로 시간초과

D, N = list(map(int, sys.stdin.readline().split(' ')))
arr = list(map(int, sys.stdin.readline().split(' '))) # 화덕의 각 너비 입력
pizza = list(map(int,sys.stdin.readline().split(' '))) # 완성 피자 크기 순서를 뒤집음

# 현재 위치까지 들어올 수 있는 최대 피자 크기
for k in range(1, len(arr)): 
    arr[k] = min(arr[k-1], arr[k])
arr.reverse() # 순서 뒤집기

# 모든 피자에 대해 자신이 들어갈 수 있는 높이를 획득
low = -1 # 초기 범위 시작은 -1로 세팅
for p in pizza: 
    low = bisect.bisect_left(arr, p, lo=low + 1) # 현재 피자가 놓인 위치 옆부터 공간 탐색

ans = len(arr) - min(low,len(arr)) # 남은 배열의 크기 = 정답
print(ans)