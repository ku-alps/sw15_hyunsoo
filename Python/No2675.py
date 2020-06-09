# 문자열 반복
# 파이썬의 문자열 처리 기능을 활용

for _ in range(int(input())): # 입력값 만큼 반복
    loop, string = input().split() # 각 문자 반복 횟수, 문자열
    for ch in string:
        print(ch*int(loop),end='') # 각 문자를 일정 횟수 반복, 줄바꿈 없음
    print() # 각 출력은 줄바꿈으로 구분