#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// 2020 KAKAO BLIND RECRUITMENT
// 가사 검색

// 효율성 테스트를 위해선 각 쿼리에 대한 판단이 빠르게 이루어져야 함
// Trie 를 구현하였으며 와일드카드 부분을 두 개의 Queue 로 처리를 시도하였으나 시간초과
// so, 각 구간마다 입력된 문자열이 도달한 개수를 map 으로 기록해두는 방식을 선택

#define ALP 26

class Trie { // 문자열 Trie 
public:
    Trie* t[ALP]; // 각 알파벳으로 이동하는 노드
    unordered_map<int, int> cnt; // 현재 시점까지 도달한 길이 N 의 문자열 개수 

    Trie(){ // 초기 생성자
        for (int k = 0; k < ALP; k++) t[k] = NULL;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 모든 문자열에 대해 통합된 트라이를 생성
    Trie f, b; // 앞, 뒤로 읽어가는 트라이
    for (string str : words) { 
        Trie* pos_f = &f, * pos_b = &b;

        int len = str.length();
        for (int k = 0; k < str.length(); k++) { // 각 문자에 대해
            pos_f->cnt[len] += 1;
            pos_b->cnt[len] += 1; // 해당 노드에 도착한 Case 증가

            int idx_f = str[k] - 'a';
            int idx_b = str[str.length() - (k + 1)] - 'a'; // 다음에 이동할 문자

            // 아직 생성되지 않은 노드라면 새롭게 생성
            if (pos_f->t[idx_f] == NULL) {
                Trie* n = new Trie();
                pos_f->t[idx_f] = n;
            }
            if (pos_b->t[idx_b] == NULL) {
                Trie* n = new Trie();
                pos_b->t[idx_b] = n;
            }

            pos_f = pos_f->t[idx_f];
            pos_b = pos_b->t[idx_b]; // 이동
        }
    }

    // 쿼리 처리
    for (string str : queries) {
        Trie* trie;
        int k = 0, len = str.length(); // 각 쿼리의 길이

        if (str[0] == '?') { // 접두사로 붙은 경우
            trie = &b; // 뒤에서부터 찾음

            for (; k < str.length(); k++) {
                if (str[len - (k + 1)] == '?') break; // ?를 만나면 종료
                trie = trie->t[str[len - (k + 1)] - 'a']; // 이동

                if (trie == NULL) { // 값이 없다면 이동 불가
                    Trie* n_t = new Trie();
                    trie = n_t;
                    break; // 빈 트라이로 옮기고 종료 
                }
            }
        }
        else { // 접미사로 붙은경우
            trie = &f; // 앞에서부터 찾음

            for (; k < str.length(); k++) {
                if (str[k] == '?') break; // ?를 만나면 종료
                trie = trie->t[str[k] - 'a']; // 이동

                if (trie == NULL) { // 값이 없다면 이동 불가
                    Trie* n_t = new Trie();
                    trie = n_t;
                    break; // 빈 트라이로 옮기고 종료
                }
            }
        }
        answer.push_back(trie->cnt[len]); // 길이가 일치하는 문자열 수가 정답
    }
    return answer;
}