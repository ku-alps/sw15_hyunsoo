#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 후보 추천하기
// 매번 일정한 기준에 따라 정렬 후, 처리하는 방식을 사용
// 정렬하는 데이터의 크기가 굉장히 작기 떄문에 가능한 방식

#define SIZE 100 // 등장 가능한 후보자 번호
#define LOOP 1000 // 최대 반복 횟수

int N, M, candi[SIZE + 1], arr[LOOP]; 
vector<int> idx; // 선택한 arr의 index

int main() {
	cin >> N >> M;
	int data;
	for (int k = 0; k < M; k++) {
		cin >> arr[k]; // k 번째에 등장한 값
		if (!candi[arr[k]]) { // 액자에 없다면
			if (idx.size() >= N) { // 가진 액자 수보다 후보자가 많으면
				sort(idx.begin(), idx.end(), [](int& a, int& b)->bool { // 등장 횟수, idx 값을 우선순위로 정렬
					return candi[arr[a]] == candi[arr[b]] ? a > b : candi[arr[a]] > candi[arr[b]];
					});
				int remove = idx[idx.size() - 1]; // 가장 뒤에서 등장하는 놈을 제거할 것
				idx.pop_back();
				candi[arr[remove]] = 0; // 가장 수가 적고 처음에 등장한 값을 초기화
			}
			idx.push_back(k); // 등장 번호를 넣음
		}
		candi[arr[k]] += 1; // 중복 등장 횟수 증가
	}

	sort(idx.begin(), idx.end(), [](int& a, int& b)->bool {
		return arr[a] < arr[b]; // 번호 크기순으로 나열
		});
	for (int k = 0; k < idx.size(); k++) {
		cout << arr[idx[k]] << " "; // 출력
	}
}