# 크로아티아 알파벳
# 파이썬의 문자열 처리

cro = ["c=","c-","dz=","d-","lj","nj","s=","z="] # 크로아티아 알파벳 종류
datas = input() # 입력

idx = 0 # 현재 읽고 있는 문자 인덱스
ans = 0 # 알파벳 수
while idx < len(datas):
    ans += 1 # 기본적으로 알파벳 하나로 취급
    part1, part2 = datas[idx:idx+2], datas[idx:idx+3] # 부분 문자열
    if part1 in cro or part2 in cro: # 크로아티아 알파벳의 일종이면
        idx += 2 if part1 in cro else 3 # 한번에 읽음 처리
        continue
    idx += 1 # 그 외엔 1칸 씩
print(ans)