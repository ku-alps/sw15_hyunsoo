#include <string>
#include <vector>
using namespace std;
// 2020 KAKAO BLIND RECRUITMENNT
// 자물쇠와 열쇠

// 입력 크기가 최대 20 이므로, 완전 탐색으로 비교해도 충분

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int N = key.size(), M = lock.size();

    int value, key_set[20][20][4] = {}; // 4 방향으로 회전시킨 열쇠

    // 회전시킨 열쇠 생성
    for (int k = 0; k < N; k++) {
        for (int m = 0; m < N; m++) {
            key_set[k][m][0] = key[k][m]; // 열쇠에서 값 추출
            key_set[m][(N - 1) - k][1] = key_set[k][m][0];
            key_set[(N - 1) - k][(N - 1) - m][2] = key_set[k][m][0];
            key_set[(N - 1) - m][k][3] = key_set[k][m][0];
        }
    }

    for (int k = -N; k < M && !answer; k++) {
        for (int m = -N; m < M && !answer; m++) { // 키를 자물쇠 바깥부터 한 칸씩 옮기며 확인

            // 키를 회전 시킨 각 경우에 대해 판단 (4가지)
            for (int i = 0; i < 4 && !answer; i++) {
                bool flag = true;
                vector<vector<int>> cpy(lock);

                for (int v = 0; v < N && flag; v++) {
                    for (int h = 0; h < N && flag; h++) { // 열쇠의 각 위치
                        int x = k + v, y = m + h; // 해당 열쇠 파트가 맵에서 맞춰질 좌표
                        if (x < 0 || x >= M || y < 0 || y >= M) continue; // 범위 초과

                        // 0인 값이 존재하면서, 양 값이 서로 다른 경우 ( 0,1 조합 )
                        if (!(cpy[x][y] & key_set[v][h][i]) && (cpy[x][y] ^ key_set[v][h][i])) {
                            cpy[x][y] = 1;
                        }
                        else flag = false;
                    }
                }
                if (flag) { // 가능하다면 암호 전체가 채워졌는가 확인
                    for (int v = 0; v < M && flag; v++) {
                        for (int h = 0; h < M && flag; h++) {
                            if (!cpy[v][h]) flag = false;
                        }
                    }
                }
                answer = flag; // 결과 값을 저장
            }
        }
    }
    return answer;
}