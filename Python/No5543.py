import sys
# 상근날드
# 다수의 줄을 원하는 횟수만큼 입력받는 연습

burgers = list(map(int, [ sys.stdin.readline() for _ in range(3) ])) # 버거 3줄 입력, 정수 변환
drinks = list(map(int, [ sys.stdin.readline() for _ in range(2) ])) # 음료 2줄 입력, 정수 변환
print(min(burgers) + min(drinks) - 50) # 각각 최소값의 음식을 고른 후, 세트할인