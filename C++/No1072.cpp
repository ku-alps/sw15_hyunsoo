#include<iostream>
using namespace std;
// 게임
// 더하는 값에 대해 빠르게 판단해야하므로, 이분 탐색을 사용
// but, 이 외에 수식을 통한 계산도 가능

// 연산 과정에서 int 범위를 넘길 수 있으니,
// long long int 를 기반으로 코드 작성

#define MAX 1000000000 // 판단 최대값

long long int X, Y;
int Z;

bool Cal(long long int mid) { 
	int new_Z = (int)(((Y + mid) * 100) / (X + mid));
	return new_Z == Z; // 동일한가를 판단
}

int main() {
	cin >> X >> Y;

	Z = (int)((Y * 100) / X); // 현재 확률

	long long int f = 0, b = MAX;
	while (f <= b) { // 이분 탐색 (파라메트리 서치)
		long long int mid = (f + b) / 2;
		if (Cal(mid)) f = mid + 1;
		else b = mid - 1;
	}

	if (f > MAX) f = -1; // 멈춘 값이 최대값을 넘어가면 -1
	cout << f << endl;
}