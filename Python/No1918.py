# 후위 표기식
# Stack 을 사용하여 우선순위 비교를 통해 출력
# 후위 연산자에 대한 잘못된 이해로 해결에 어려움을 겪음
# ex. "A*B/C" --> "AB*C/" 가 등장하나, "ABC/*" 로 이해함

oper = {'+': 2, '-' : 2, '*' : 3, '/' : 3, '(' : 1, ')' : 4, '$' : 0}
stack = [ '$' ] # 연산자용 스택

datas = input() # 연산식 입력 받음
for ch in datas:
    if ch.isalpha(): # 알파벳이면 출력
        print(ch,end='')
    else:
        if ch == '(': # 괄호 시작
            stack.extend('(') # 강제 삽입
        elif ch == ')': # 괄호 끝
            while stack[-1] != '(': # 괄호 시작지점까지 모두 출력
                    print(stack[-1],end='')
                    stack.pop() # 뒤에 값을 뽑아냄
            stack.pop() # 시작 괄호 제거
        else: # 그 외엔 사칙연산
            f = oper[stack[-1]] # 가장 뒤에 있는 놈의 우선순위를 체크
            b = oper[ch] # 이번에 등장하는 문자열

            # 우선순위 비교에 따라 행동
            if f >= b: # 작거나 같은 경우, '(' 또는 '$' 까지 모두 출력
                while stack[-1] not in ['(', '$'] and f >= b:
                    # 우선순위 체크
                    print(stack[-1],end='')
                    stack.pop() # 뒤에 값을 뽑아냄
                    f = oper[stack[-1]]
            stack.extend(ch) # 값 삽입

while stack[-1] != '$':
    print(stack[-1],end='')
    stack.pop() # 뒤에 값을 뽑아냄