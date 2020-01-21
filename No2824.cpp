#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
// 최대공약수
// 주어지는 수로 얻게되는 결과값이 굉장히 큼 (곱셈이므로)
// so, 유클리드 호제법은 사용이 불가능

// 대신, 주어지는 값들을 모두 소인수분해 한 후,
// 각 값이 가진 소인수를 비교하며 최대공약수를 완성하는 방식을 사용

#define MAX 31624 // 1,000,000,000 까지의 소수 판단용

int visit[MAX + 1];
vector<int> v, a, b; // 소수 벡터, a, b 의 소인수 벡터

void eratos() { // 에라토스테네스의 체
	for (int k = 2; k <= MAX; k++) {
		if (visit[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k <= MAX; m++) {
			visit[m * k] = 1;
		}
	}
}

int main() {
	eratos(); // 소수 획득

	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		for (int m = 0; m < v.size();) {
			if (d == 1) break;
			if (!(d % v[m])) {
				a.push_back(v[m]);
				d /= v[m];
				continue;
			}
			m++;
		}
		if (d != 1) a.push_back(d);
	} // 입력되는 모든 값에 대한 소인수 저장 ( 수 a )

	cin >> loop;
	for (int k = 0; k < loop; k++) {
		int d;
		cin >> d;
		for (int m = 0; m < v.size();) {
			if (d == 1) break;
			if (!(d % v[m])) {
				b.push_back(v[m]);
				d /= v[m];
				continue;
			}
			m++;
		}
		if (d != 1) b.push_back(d);
	} // 입력되는 모든 값에 대한 소인수 저장 ( 수 b )
	sort(a.begin(), a.end());
	sort(b.begin(), b.end()); // 두 소인수를 각각 크기 순으로 정렬

	bool flag = false; // 제약 조건 수를 초과했는가를 판단 
	long long int gcd = 1; // 얻게되는 최대 공약수의 크기에 유의
	int a_pos = 0, b_pos = 0; // 각 벡터의 인덱스 포인터
	while (a_pos != a.size() && b_pos != b.size()) { // 둘을 비교하면서 진행

		// 둘이 같은 소수를 갖고 있다면 공약수에 포함시킴
		if (a[a_pos] == b[b_pos]) {
			gcd = (gcd * a[a_pos]); 
			a_pos++, b_pos++;

			if (gcd >= 1000000000) { // 만일 얻게된 공약수가 조건을 넘기면
				gcd %= 1000000000; // 그 나머지를 취하고
				flag = true; // 출력 형태를 변경하도록 함
			}
		}
		else { // 그 외의 경우
			if (a[a_pos] < b[b_pos]) a_pos++;
			else b_pos++;  // 더 작은 쪽을 이동시킴
		}
	}
	// 1,000,000,000 을 넘을경우, 빈공간은 0 을 출력하는 9 자리수가 되어야 함
	if (flag) printf("%09d\n", gcd); 
	else printf("%d\n", gcd);
}