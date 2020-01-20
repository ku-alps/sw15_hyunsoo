#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 두 배열의 합
// 서로다른 두 배열 사이에서 합을 계산해야하므로,
// 각 배열에 대해 얻을 수 있는 모든 구간 합을 미리 계산 후
// 앞 뒤 포인터를 사용하여 값을 조절

int main() {
	int T, n, m, A[1000], B[1000];
	vector<int> A_sum, B_sum;

	cin >> T >> n;

	for (int k = 0; k < n; k++) { // 첫번째 배열
		int data;
		cin >> data;
		if (k != 0) A[k] = A[k - 1] + data;
		else A[k] = data; // 입력 데이터를 통해 누적 합 배열을 생성

		A_sum.push_back(A[k]); // 생성된 배열을 벡터에 추가
		for (int m = 0; m < k; m++)
			A_sum.push_back(A[k] - A[m]);
		// 새로 만들어진 누적 합에 대해, 얻을 수 있는 모든 구간 합을 계산
	}

	cin >> m;
	for (int k = 0; k < m; k++) { // 두번째 배열
		int data;
		cin >> data;
		if (k != 0) B[k] = B[k - 1] + data;
		else B[k] = data;

		B_sum.push_back(B[k]);
		for (int m = 0; m < k; m++)
			B_sum.push_back(B[k] - B[m]);
	}

	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end()); // 구간 합을 크기 순으로 정렬

	long long int select = 0;
	int a_pos = 0, b_pos = B_sum.size() - 1;

	while (a_pos <= A_sum.size() - 1 && b_pos >= 0) { // 두 벡터가 모두 끝을 볼 때 까지
		long long int a_count = 1, b_count = 1; // 동일한 값의 등장 횟수
		for (int k = a_pos + 1; k < A_sum.size(); k++) { 
			if (A_sum[a_pos] == A_sum[k]) a_count += 1;
			else break;
		}
		for (int k = b_pos - 1; k >= 0; k--) {
			if (B_sum[b_pos] == B_sum[k]) b_count += 1;
			else break;
		} // 현재 인덱스부터 중복 값의 등장 수를 체크

		int sum = A_sum[a_pos] + B_sum[b_pos]; 
		if (sum == T) { // 원하는 값과 합이 동일하면
			select += a_count * b_count;
			a_pos += a_count;
			b_pos -= b_count; // 현재 등장한 중복 값을 통해 가능한 경우 수를 계산
		}
		else if (sum > T) { // 큰 경우, 값을 빼줘야하므로
							// 뒤부터 탐색하는 두번째 배열의 포인터를 이동
			b_pos -= b_count;
			if (b_pos < 0) break;
		}
		else { // 작은 경우, 값을 더해줘야 하므로
				// 앞부터 탐색하는 첫번째 배열의 포인터를 이동
			a_pos += a_count;
			if (a_pos > A_sum.size() - 1) break;
		}
	}

	cout << select << endl;
}