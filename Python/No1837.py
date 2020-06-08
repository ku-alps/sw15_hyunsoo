import math
# 암호제작
# 소수처리가 필요하므로, 에라토스테네스의 체를 사용

# 입력, P 의 범주가 숫자 타입을 넘어가나, 파이썬이므로 정수형 표현이 가능
P, K = map(int, input().split())

# 에라토스테네스의 체
check = [False, False] + [True for _ in range(2,1000000)] # 소수 체크 배열
primes = [] # 소수 집합
for idx in range(1000000):
    if check[idx]:
        primes.append(idx)
        for i in range(2*idx, 1000000, idx):
                check[i] = False
primes = list(filter(lambda a: a < K, primes)) # 얻은 소수 중, K 보다 작은 값만 추려냄

for prime in primes: # 모든 소수로 비교
    if P % prime == 0:
        print("BAD", prime)
        exit()
print("GOOD")
