# X보다 작은 수
# 어떤 리스트의 원소 중, 조건을 만족하는 값만 추려내는 filter 사용

N, X = map(int, input().split(' '))
func = lambda a : a < X # 필터용 람다식
ans = filter(func, list(map(int, input().split(' ')))) # 배열을 조건에 맞춰 추려냄
for k in ans:
    print(k,end=' ') # 공백을 두고 출력