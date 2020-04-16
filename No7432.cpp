#include<iostream>
#include<vector>
#include<cstring>
#include<sstream> // 문자열 분리를 위한 라이브러리
#include<algorithm>
using namespace std;
// 디스크 트리
// Trie 를 사용한 구현
// 다만, 해당 코드는 경로 존재 여부를 완전탐색으로 찾아내므로 상당히 비효율적

class Dir { // 트라이 구조체
public:
	vector<pair<string, Dir*>> folder; // 다음 경로
};

int N;
Dir dir; // 트라이

void DFS(Dir* move, int idx) { // 모든 경로 출력 함수
	sort(move->folder.begin(), move->folder.end(), [](pair<string, Dir*> a, pair<string, Dir*> b) -> bool {
		return strcmp(a.first.c_str(), b.first.c_str()) < 0;
	});

	for (pair<string, Dir*> info : move->folder) {
		for (int k = 0; k < idx; k++) cout << " ";
		cout << info.first << endl; // 해당 폴더정보 출력
		DFS(info.second, idx + 1); // 하위 폴더 출력
	}
}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) { // 경로 입력
		string str;
		cin >> str;

		vector<string> list; // 디렉토리를 나누어 기록할 벡터
		stringstream ss(str); // 입력된 str 에서 읽어내는 string stream
		string part; // 쪼개진 부분 문자열 저장할 공간
		while (getline(ss, part, '\\')) { // \ 를 기준으로 각 부분을 잘라냄
			list.push_back(part);
		}

		Dir* move = &dir;
		for (string path : list) { // 주어진 모든 경로에 대해 트라이 구성
			Dir* find = NULL;
			for (int k = 0; k < move->folder.size(); k++) { // 해당 경로가 있다면 선택
				if (move->folder[k].first == path) find = move->folder[k].second;
			}

			if (find == NULL) { // 찾는 경로가 없으면
				find = new Dir();
				move->folder.push_back({ path, find }); // 직접 만들어서 삽입
			}
			move = find;
		}
	}

	DFS(&dir, 0); // 시작점부터 경로 출력
}
