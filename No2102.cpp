#include<iostream>
#include<algorithm>
using namespace std;
// 보석 줍기
// 파라매트릭 서치를 사용하여 해당 문제를 풀 수 있음
// 힌트를 보고 int 형태로 구현하려 시도했으나,
// 소수 이하의 단위의 차이로 답이 틀리는 경우가 발생

// so, 부동소수점 타입을 사용해야하며,
// 시중에 돌아다니는 해답 코드를 이해하는 수준에 그칠 수 밖에 없었음

#define NUM 100000

int N, M, a[NUM + 1];

bool F(double x) { // 탐색하려는 평균값 x 
    double sl = 0, sr = 0, mini = 0;
    for (int i = 1; i < M; i++) sr += a[i] - x; // 평균을 뺀 차이의 누적합
    for (int i = M; i <= N; i++) {
        sr += a[i] - x;
        mini = min(mini, sl); // 누적 합에서 제하는 값을 최소로 선택
        if (sr >= mini) return true; // 만들어낸 누적합이 0 이상이면, 해당 평균을 만들 수 있음
        sl += a[i - M + 1] - x;
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];

    // 0 ~ 2000 사이의 파라매트릭 서치
    double low = 0, up = 2000, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + up) / 2;
        F(mid) ? low = mid : up = mid;
    }
    cout << (int)(mid * 1000 + 1e-6) << endl;
    return 0;
}