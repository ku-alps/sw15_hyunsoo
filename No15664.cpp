#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// N과 M (10)
// 기본적으로 완전 탐색을 기반으로 하되, 비내림차순 (오름차순) 이라는 제약조건이 추가로 붙음
// 예외처리가 까다롭기에, 기존과 달리 규칙성을 찾는 방식이 아닌
// hash map 을 사용한 중복 체크를 사용

int N, M;
int stack[8]; // 인덱스 저장용
unordered_map<long long int, int> exist; // 중복 판단용 hash map
vector<int> v; // 데이터가 들어간 벡터

void S(int idx, int depth) {
	if (depth == M) { // 깊이에 도달한 경우
		long long int check = 0;

		// 쌓인 스택 정보를 기반으로 일종의 순열 key룰 샹송
		// 10000 이하의 값 * 8 개 = 총 40자리 필요
		// so, 64bit 를 쓰는 long long int 형식을 사용
		for (int k = 0; k < depth; k++) {
			check = (check << 5) + v[stack[k]];
		}
		if (exist.end() != exist.find(check)) return;
		// 해당 키가 hash_map에 존재하면 종료

		exist[check] = 1; // map 내에 키 정보를 등록
		for (int k = 0; k < depth; k++) {
			printf("%d ", v[stack[k]]); // 순열 출력
		}
		printf("\n");
		return;
	}
	for (int k = idx; k < v.size(); k++) { // 깊이에 도달하지 못했으면 재귀호출
		stack[depth] = k;
		S(k + 1, depth + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // 데이터 벡터에 추가
		int d;
		cin >> d;
		v.push_back(d);
	}
	sort(v.begin(), v.end()); // 크기 순의 순열이므로 정렬

	for (int k = 0; k < v.size(); k++) { // 순열 탐색 시작
		stack[0] = k;
		S(k + 1, 1);
	}
}