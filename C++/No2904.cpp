#include<iostream>
#include<vector>
using namespace std;
// 수학은 너무 쉬워
// 제공되는 값들을 각각 소인수분해하고, 갯수를 셈
// 존재하는 소인수들이 모든 수에게 분배가 가능한 만큼 있는지 확인

#define MAX 1001

int num, arr[MAX], datas[100]; // 입력 데이터
int cnt[1000000]; // 등장한 소수 갯수 체크
vector<int> v; // 소수 정보

void eratos() {
	arr[0] = arr[1] = 1;
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k < MAX; m++)
			arr[m * k] = 1;
	}
}

int main() {
	eratos();
	
	cin >> num;
	for (int k = 0; k < num; k++) {
		int d;
		cin >> d;
		datas[k] = d; // 모든 입력값이 가진 소수를 판단

		for (int m = 0; m < v.size();) {
			if (!(d % v[m])) { // 해당 소수로 나눠떨어지면
				cnt[v[m]] += 1;
				d /= v[m];
				continue; // 등장 횟수를 늘리고 계속 진행
			}
			if (d == 1) break; // 1이면 끝
			m++;
		}
		if (d != 1) cnt[d] += 1; // 1이 아니라면 그 자체로 소수
	}

	int gcd = 1, check = 0;
	for (int k = 2; k < 1000000; k++) {
		if (cnt[k] / num) { // 모두에게 배분이 가능한 수만큼 있다면
			int loop = cnt[k] / num; // 배분량만큼 반복
			for (int n = 0; n < loop; n++) {
				gcd *= k; // 최대공약수 계산
				for (int m = 0; m < num; m++) { // 모든 수들에 대해 분배 체크
					if (datas[m] % k) // 나눌 수 없다면
						check += 1; // 이동이 필요
					else
						datas[m] /= k; // 나눌 수 있다면 냅둠
				}
			}
		}
	}
	cout << gcd << " " << check << endl; // 최소공배수와 등장 횟수
}

