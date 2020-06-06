import sys
# 행성 탐사
# 사각형의 너비 구하는 공식을 누적합과 좌표로 표현하여 연산

M, N = map(int, sys.stdin.readline().split())
K = int(sys.stdin.readline())
geo = [ sys.stdin.readline() for _ in range(M) ] # 지도 입력

# 누적합 생성 함수
def mklist():
    global M, N, geo
    J, O, I = [[ ([0]*(N+1)) for _ in range(M+1) ] for _ in range(3)] # 빈 배열 생성 후, 배분
    for x, line in enumerate(geo):
        for y, box in enumerate(line):
            if box == '\n': # readline 은 내부에 엔터까지 포함하여 저장
                continue

            # 람다식을 만들어서 정글, 바다, 얼음의 누적 합 정보 생성
            func = lambda a : 1 if a == box else 0
            J[x+1][y+1] = J[x+1][y] + J[x][y+1] - J[x][y] + func('J')
            O[x+1][y+1] = O[x+1][y] + O[x][y+1] - O[x][y] + func('O')
            I[x+1][y+1] = I[x+1][y] + I[x][y+1] - I[x][y] + func('I')
    return [ J, O, I ] # 세 쌍을 묶어서 반환

J, O, I = mklist() # 누적합 리스트 저장
for _ in range(K):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

    # 범위 내의 값을 구하는 공식
    calc = lambda arr : arr[x2][y2] - (arr[x2][y1-1] + arr[x1-1][y2]) + arr[x1-1][y1-1]
    sys.stdout.write(f"{calc(J)} {calc(O)} {calc(I)}\n")