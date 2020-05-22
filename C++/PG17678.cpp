#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
// 2018 KAKAO BLIND RECRUITMENT
// 셔틀버스

// 문자열과 시간처리 + 규칙성 에 대한 구현 문제

string solution(int n, int t, int m, vector<string> timetable) {

    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순으로 시간 정렬
    for (string time : timetable) {
        string str; // 받을 문자열을 저장할 공간
        stringstream ss(time); // 문자열을 나눌 스트링스트림

        int t = 0; // 시간,
        getline(ss, str, ':');
        t += atoi(str.c_str()) * 100; // 시간
        getline(ss, str, ':');
        t += atoi(str.c_str()); // 분

        pq.push(t); // 만든 시간을 넣음
    }

    bool left = false; // 빈 좌석이 있는가?
    int ans = 0; // 버스에 탐승한 승객 중, 가장 마지막에 도착한 시간
    int s_h = 9, s_m = 0; // 가장 최근에 보낸 버스 시간
    int t_h = 9, t_m = 0; // 현재 버스 시간
    for (int k = 0; k < n; k++) {
        left = false; // 마지막 버스의 빈 좌석 여부가 중요하므로, 매번 확인

        int bus_time = 100 * t_h + t_m; // 버스 도착 시간
        for (int i = 0; i < m; i++) { // 탑승 수만큼 줄임
            if (pq.empty()) { // 더 뽑으려했더니 큐가 빈 경우
                left = true; // 빈 자리 있음
                break;
            }
            if (pq.top() > bus_time) { // 태울 승객이 아직 도착 안했다면,
                left = true; // 남은 좌석이 있음
                break; // 종료
            }
            ans = max(ans, pq.top()); // 현재까지 가장 늦게 등장한 승객 시간
            pq.pop();
        }

        s_h = t_h;
        s_m = t_m; // 가장 마지막에 출발한 버스 시간 저장

        t_m += t;
        t_h += t_m / 60;
        t_m %= 60; // 시간 갱신
    }

    string answer = "";
    int hour, minute;
    if (left) { // 마지막에 빈 자리가 있었다면
        hour = s_h;
        minute = s_m; // 마지막 버스 시간에 맞춰오면 됨
    }
    else { // 빈 자리가 없었다면, 가장 마지막에 등장한 승객보다 1분 빨리
        minute = (ans % 100) + 59;
        hour = (ans / 100) - 1 + (minute / 60);
        minute %= 60;
    }

    if (hour < 10) answer += "0"; // 형태에 맞춰 값을 생성
    answer += to_string(hour) + ":";
    if (minute < 10) answer += "0";
    answer += to_string(minute);
    return answer;
}
