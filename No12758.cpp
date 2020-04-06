#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// 천상용섬
// 벨 수 있는 높이는 감소하지 않는다는 제약이 존재하므로,
// 누적 합을 사용한 DP 방식을 사용하여 해결 가능

#define NUM 300 // 입력되는 값의 최대 수
#define DIV 1000000007 // 나누는 수

int main() {
	int T;
	cin >> T; // 테스트 케이스

	while (T--) {
		int N;
		cin >> N; // 입력될 수의 갯수

		vector<int> v[2][NUM]; // DP 구조를 만들 벡터 ( 약수, 누적 합 )
		for (int k = 0; k < N; k++) {
			int num;
			cin >> num; // 입력값
			for (int m = 1; m <= sqrt(num); m++) { // 제곱근까지 모든 정수를 살펴봄
				if (num % m) continue; // 나누어 떨어지지 않으면 무시

				v[0][k].push_back(m); // 두 약수를 벡터에 삽입 ( 중복 불허 )
				if (num / m != m) v[0][k].push_back(num / m);
			}
			sort(v[0][k].begin(), v[0][k].end()); // 해당 벡터를 오름차순으로 정렬 ( 이진탐색을 위함 )
		}

		for (int k = 0; k < v[0][0].size(); k++) v[1][0].push_back(k + 1); // 첫 배열 세팅 ( 누적 합 형태 )
		for (int k = 1; k < N; k++) { // 입력된 모든 값에 대해 처리
			v[1][k].push_back(1);
			// '1' 은 모든 값의 약수이며, 벨 수 있는 높이는 크거나 같으므로
			// 해당 값이 가질 수 있는 조합은 1가지 경우 수로 고정 됨

			for (int m = 1; m < v[0][k].size(); m++) { // 그 외 나머지 약수들
				// 현재 약수를 통해 만들어지는 경우의 수는
				// 이전 배열에서 자신보다 작거나 같은 값이 만들 수 있는 모든 조합의 합과 동일 ( 누적 합 배열로 해결 )

				// lower_bound 의 경우, 동일한 값을 가지면 해당 값을 반환하기 때문에
				// 예외처리 필요가 없는 upper_bound 를 사용 후, 한 칸 앞의 값을 사용

				int idx = upper_bound(v[0][k - 1].begin(), v[0][k - 1].end(), v[0][k][m]) - v[0][k - 1].begin();
				// 이전에 처리한 값에서 현재 약수보다 큰 최초의 값의 인덱스

				v[1][k].push_back((v[1][k][m - 1] + v[1][k - 1][idx - 1]) % DIV);
				// 자신보다 작은 약수들이 만들 수 있는 조합 수 + 자신이 만들 수 있는 조합 수
			}
		}
		cout << *v[1][N - 1].rbegin() << endl; // 가장 마지막에 등장한 값이 정답
	}
}