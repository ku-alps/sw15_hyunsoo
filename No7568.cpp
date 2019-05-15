// 덩치
// 정렬기준을 확립해서 문제를 풀려고했는데
// 그런거 없이 단순 비교, 계산으로 해결이 가능
// but, 다른 방식이 있을 것 같은 느낌

#include<iostream>
using namespace std;

class Size {
public:
	int weight, height; //키, 몸무게
	Size();
	Size(int i_w, int i_h);
};

Size* list[50]; //최대 50명
int order[50]; //순서 기록용

int main() {
	int people;
	cin >> people; //사람 수

	for (int k = 0; k < people; k++) {
		int i_w, i_h;
		cin >> i_w >> i_h;
		list[k] = new Size(i_w, i_h); //모든 정보를 객체로 만들어 배열에 저장
	}

	for (int i = 0; i < people; i++) {
		order[i]++; //일단 모두 1값으로 세팅 (1부터 시작)
		for (int k = 0; k < people; k++) { //정렬을 시도할 예정
			if (list[i]->weight < list[k]->weight) {
				// 뒤에 나온 놈의 무게가 앞쪽보다 무거우면
				if (list[i]->height < list[k]->height) { //몸무게도 확인
					order[i]++; // 나보다 덩치큰애가 하나 더있음
				}
			}
		} //정렬 끝
	}
	
	for (int k = 0; k < people; k++) {
		cout << order[k] << endl; //등수 출력
	}
}

Size::Size() {}
Size::Size(int i_w, int i_h) {
	weight = i_w;
	height = i_h;
}