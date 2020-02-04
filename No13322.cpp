#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
// 접두사 배열

// 구현해야하는 정석 알고리즘 절차
// 1. 0~k 까지의 부분 문자열을 모두 추출
// 2. 벡터에 끝 인덱스 값과 함께 쌍으로 저장
// 3. 벡터를 부분 문자열의 사전 순으로 정렬
// 4. 인덱스 값을 순차적으로 출력

// but, 접미사와 다르게 '접두사'의 경우, 앞쪽부터 문자열을 자르므로
// 획득하는 부분문자열은 항상 사전 순 ( 일종의 규칙 )
// so, 별다른 연산 없이 단순히 0 ~ 문자열 길이 까지 출력하는 것으로 충분

int main() {
	string str;
	cin >> str; // 문자열 입력

	for (int k = 0; k < str.length(); k++)
		printf("%d\n", k);
}