import sys, bisect
# 용액
# 합에 사용되는 용액은 단 두 종류만을 선택
# so, 각 값의 역에 대한 유사값을 탐색 후, 최소 조합을 선택
# C++ 의 경우 upper_bound, lower_bound 함수로 구현했겠으나
# Python 은 해당 기능을 제공하지 않으므로, 이분 탐색 기반의 bisect 라는 라이브러리 사용

s = int(input()) # 배열 크기
arr = list(map(int,sys.stdin.readline().split(' '))) # 값 배열 입력

ans = [] if arr[0] < 0 else [arr[0],arr[1]] # 초기 값이 양수로 시작하면, 가장 작은 두 수의 조합
sum = 1000000000 # 초기 합
for i,v in enumerate(arr):
    if v > 0: # 음수 값들만 탐색 기준으로 잡음
        break

    pos = bisect.bisect_right(arr, -v) # 정렬된 배열 내에서 값 '-v' 가 삽입될 위치 정보를 얻어옴
    if pos - i == 1: # 이미 사용한 용액을 또 쓰는 경우는 예외처리
        continue

    # 더 작은 조합을 선택
    if sum > abs(v+arr[pos-1]):
        ans = [v, arr[pos-1]]
        sum = abs(v+arr[pos-1])
    if pos < s and sum > abs(v+arr[pos]): # 배열 인덱스 범위 확인도 함께 진행
        ans = [v, arr[pos]]
        sum = abs(v+arr[pos])

print(ans[0], ans[1]) # 출력