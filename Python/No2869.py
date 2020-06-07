# 달팽이는 올라가고 싶다
# 정수 나눗셈 (//) 보다 실수 나눗셈 (/) 이 더 느림
# so, 초반엔 값에 대한 math.ceil() 로 처리하려했으나, 조건문으로 그냥 해결

A, B, V = map(int, input().split()) # 입력
per_day = A-B # 하룻밤이 지날 때 올라가는 높이
days = 1 + ((V-A) // per_day) + (1 if (V-A) % per_day != 0 else 0)
print(days)