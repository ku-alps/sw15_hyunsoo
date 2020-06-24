import heapq
# 빈도 정렬
# 파이썬의 문자열 처리를 활용한 출력
# 값의 범주가 너무 크므로, 메모리 초과
# so, 모든 공간을 할당하지 않고 등장한 값에 대해서만 할당을 시도

N, C = map(int, input().split())
datas = list(map(int,input().split()))

cnt = [] # 비교 배열
for i, data in enumerate(datas):
    flag = True # 기본은 새로 추가하는 형태
    for c in cnt:
        if c[0] == data: # 기존 값이 이미 있었다면
            c[1] += 1
            flag = False # 새로 추가하지 않고 값만 증가
            break
    if flag:
        cnt.append([data, 1, i])
cnt.sort(key=lambda a: (-a[1], a[2])) # 등장 수는 내림차순, 등장 순서는 오름차순
for a in cnt:
    if a[1] != 0:
        print(f"{a[0]} "*(a[1]),end="") # 등장한 수 만큼 반복출력