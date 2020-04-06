#include <string>
#include <vector>
#include <queue>
#include <utility>
// 2019 KAKAO BLIND RECRUITMENT
// 무지의 먹방 라이브

// 규칙성을 활용하여 각 횟수를 줄이는 것이 목표
// 효율성 테스트의 입력값 범주가 int 형을 넘어서므로, long long int 타입을 고려해야 함

using namespace std;

int solution(vector<int> food_times, long long k) {
    queue<pair<int, int>> q[2];
    for (int m = 0; m < food_times.size(); m++) {
        q[0].push({ m, food_times[m] }); // 초기 세팅
    }

    long long int m = 0, loop, left = k; // 효율성 테스트에서 범위 조심
    for (; !q[m].empty(); m = !m) {
        loop = left / q[m].size(); // 전체 반복 가능 횟수
        left = left % q[m].size(); // 남은 처리 횟수

        if (!loop) break; // 전체에 대해 불가능하면 종료

        while (!q[m].empty()) { // 큐의 모든 원소에 대해
            pair<int, int> d = q[m].front();
            q[m].pop();

            int v = d.second - loop; // 남은 음식양에서 먹어야 하는 횟수를 차감
            if (v > 0) q[!m].push({ d.first, v }); // 양수인 경우, 다음에도 먹을 수 있음
            else if (v < 0) left -= v; // 음수인 경우, 부족한만큼 다른 음식을 먹어야 함
        }
    }

    if (q[m].empty()) return -1; // 보려는 큐가 비어있다면 먹을 음식이 없음
    else {
        while (left--) q[m].pop(); // 남은 횟수만큼 음식을 먹음
        return q[m].front().first + 1; // 결과 값
    }
}