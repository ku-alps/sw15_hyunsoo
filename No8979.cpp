#include<iostream>
using namespace std;
// 올림픽
// 메달 수에 따른 각 국가의 등수 측정
// 정렬 후 등수를 계산하는 방법을 쓸려고했으나
// 몇가지 예외사항이 너무 크게걸려서
// 최대한 풀이방식을 단순화


class Country { //도시
public:
	int ident; //식별번호
	int gold; //금메달 수
	int silver; //은메달
	int bronze; //동메달
	Country(); //생성자
};

int main() {
	int count; // 참가 국가 수
	int num; //알고싶은 국가 번호
	cin >> count >> num;

	Country** part = new Country*[count]; //참가자 동적할당
	// 굳이 포인터 배열을 할당한 이유는
	// 정렬 과정에서 편의를 위해서
	int pos; //내가 원하는 target이 들어있는 위치정보
	for (int k = 0; k < count; k++) {
		part[k] = new Country();

		if (part[k]->ident == num) //내가 등수를 알아야하는 놈이면
			pos = k;
	}
	
	{
		Country* save = part[pos];
		part[pos] = part[0];
		part[0] = save; // 첫번째 방과 내가 찾은 국가를 서로 교체
	}

	int rank = 1; //일단 1등부터 시작
	for (int k = 1; k < count; k++) {
		if (part[0]->gold < part[k]->gold) {
			//내가 금메달이 더 적으면
			rank++; //랭크 감소
		}
		else if (part[0]->gold == part[k]->gold) {
			//같은 경우, 은메달에 대해서 반복수행
			if (part[0]->silver < part[k]->silver) {
				rank++;
			}
			else if (part[0]->silver == part[k]->silver) {
				//같은 경우, 동메달로 동일
				if (part[0]->bronze < part[k]->bronze) {
					rank++;
				}
					//같은 경우, 이 녀석은 얘랑 같은 동급
					//so, 랭크에 영향 x
			}
		}
	}
	
	cout << rank << endl;

	for (int k = 0; k < count; k++)
		delete part[k];
	delete[] part; //메모리 관리
}

Country::Country() {
	cin >> ident >> gold >> silver >> bronze; //값 입력
}