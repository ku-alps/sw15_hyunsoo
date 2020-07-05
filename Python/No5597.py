# 과제 안 내신 분..?

data = list(map(int, [ input() for _ in range(28) ]))
data.sort()

cnt = 1
for k, d in enumerate(data):
    if k+cnt != d:
        print(k+cnt)
        cnt+=1
if cnt < 3:
    for k in range(cnt,3):
        print(28+cnt)