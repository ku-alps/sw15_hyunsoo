import bisect
# 카누 선수
# 완전 탐색, DP 로는 좀 난해한 문제

# 그룹은 4개로 고정되어 있으며, 각각은 최대 1000 명의 인원을 수용 가능
# so, 두 그룹으로 짝지어 값을 가능한 합 조합을 모두 생성한 후,
# 이분 탐색으로 빠르게 처리

for _ in range(int(input())): # 테스트 케이스
    K, N = map(int, input().split())
    datas = [ list(map(int, input().split())) for _ in range(4) ] # 입력 데이터
    
    # 두 그룹을 묶어서 쌍으로 만듦
    first, second = [ [] for _ in range(2) ]
    for one in datas[0]:
        for two in datas[1]:
            first.append(one + two)
    for three in datas[2]:
        for four in datas[3]:
            second.append(three + four)
    first.sort()
    second.sort()

    ans = -40000000 # 값 범주로 인한 오류를 없애기 위해 큰 음수 값을 기본으로 채용
    for value in first:
        idx = bisect.bisect_left(second, K - value) # 가장 유사하게 만드는 값을 찾음
        if idx != 0: # 맨 앞이면 뒷 값만 사용
            sum = value + second[idx-1]
            if abs(K - ans) > abs(K - sum): # 차이 값이 작은 놈을 선택
                ans = sum
            elif abs(K - ans) == abs(K - sum): # 같으면 두 값중 작은 놈 픽
                ans = min(ans, sum)
        if idx != second.__len__(): # 끝 자리면 앞 값만 사용
            sum = value + second[idx]
            if abs(K - ans) > abs(K - sum): # 차이 값이 작은 놈을 선택
                ans = sum
            elif abs(K - ans) == abs(K - sum): # 같으면 두 값중 작은 놈 픽
                ans = min(ans, sum)
    print(ans)