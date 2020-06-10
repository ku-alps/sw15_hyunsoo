# 실패율
# 2019 KAKAO BLIND RECRUITMENT
# 단순 연산 및 정렬 문제

def solution(N, stages):
    answer = []
    stages = list(reversed(sorted(stages))) # 정렬 후, 뒤집기

    for level in range(1,N+1): # stage 1~N 까지 확인
        cnt = 0 # 해당 스테이지에서 멈춤 유저 수
        user = len(stages) # 남아 있는 모든 유저
        while stages and stages[-1]==level:
            # 아직 사용자가 남아있고, 해당 단계에 막혀있다면
            cnt += 1
            stages.pop()
        answer.append([cnt/user if user != 0 else 0 , level]) # 쌍으로 삽입
    # 앞쪽 값 (실패울) 기준으로 정렬
    # 이때, 입력 배열의 순서는 level 에 따른 오름차순이고,
    # sort 함수는 해당 순서를 해치지 않는 선에서 정렬하므로 level 은 오름차순을 유지
    answer = sorted(answer,key=lambda a: (a[0]), reverse=True)
    answer = list(map(lambda a: a[1], answer)) # 모든 쌍에 대해 점수값은 버리고 level 값만 획득

    return answer