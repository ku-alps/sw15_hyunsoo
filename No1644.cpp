#include<iostream>
#include<vector>
using namespace std;
// 소수의 연속합
// 배열의 부분합을 판단하는 문제와 동일한 풀이 방식 (투포인터)

#define MAX 4000001

bool arr[MAX];
vector<int> v; // 소수를 저장할 벡터

void eratos() { // 에라토스테네스의 체
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k < MAX; m++) {
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // 소수 획득

	int num;
	cin >> num;

	int f = 0, b = 0, sum = 0, cnt = 0;
	while (f != v.size() && v[f] <= num) { // 모든 소수를 살펴보며
		if (sum < num && b < v.size()) sum += v[b++];
		else sum -= v[f++]; // 값의 크기에 따라 앞,뒤 포인터를 이동

		if (sum == num) cnt++; // 원하는 값이면 횟수 증가
	}

	cout << cnt << endl;
}