#include<iostream>
using namespace std;
// 주사위 세개

int check[6]; //6개의 주사위 등장 횟수
int main() {
	for (int k = 0; k < 3; k++) {
		int num;
		cin >> num;
		check[num - 1]++;
	}

	int flag = 0; //선택된 계산방법 결정
	int select; //선택 값
	int count = 0;
	for (int i = 0; count != 3;i++) { //3개짜리를 볼 때 까지
		switch (check[i])
		{
		case 1:
			flag = 1;
			select = i + 1;
			count++;
			break;
		case 2:
			flag = 2;
			select = i + 1;
			count = 3; //어차피 끝. 강제종료
			break;
		case 3:
			flag = 3;
			select = i + 1;
			count = 3; //어차피 끝, 강제종료
			break;
		default:
			break;
		}
	}

	int val = 0;
	switch (flag) {
	case 1:
		val = select * 100;
		break;
	case 2:
		val = 1000 + select * 100;
		break;
	case 3:
		val = 10000 + select * 1000;
		break;
	default:
		break;
	}
	
	cout << val << endl;
}