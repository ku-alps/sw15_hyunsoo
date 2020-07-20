#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Trie {
public:
	unordered_map<char, Trie*> m;
};

bool solution(vector<string> name_list) {
	bool answer = false;
	sort(name_list.begin(), name_list.end(), [](string a, string b)->bool {
		// 이름을 길이 순으로 정렬
		return a.length() > b.length();
		});

	Trie trie; // 트라이 생성
	for (string name : name_list) { // 이름에 대해
		bool flag = false;
		vector<Trie*> v;
		for (char c : name) { // 문자로 트라이 생성
			v.push_back(&trie); // 새 시작점 추가
			for (int k = 0; k < v.size(); k++) {
				if (!(v[k]->m[c])) { // 연결된 곳이 없으면
					v[k]->m[c] = new Trie();
					if (k == 0) flag = true;
					// 원본이 새로운 길을 트는 경우, 중복없음
				}
				v[k] = v[k]->m[c]; // 각 좌표를 이동시킴
			}
		}
		if (!flag) {
			// 새 길을 만들지 못한 원본이 있다면 중복
			answer = true;
			break;
		}
	}
	return answer;
}