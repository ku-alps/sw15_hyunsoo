#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
// 사이클 제거

#define NUM 5000

int num, visit[NUM + 1]; // 총 노드 수, 방문 여부
vector<int> v[NUM + 1]; // 실제 엣지 
vector<pair<int, int>> pq;

bool DFS(int idx, int p, int e) { // 현재 위치, 부모 정보, 없는 노드 정보 
    bool ans = true;
    visit[idx] = 1;
    for (int dir : v[idx]) { // 연결된 엣지들을 살펴봄
        if (dir == p || dir == e) continue; // 부모 또는 예외구간
        if (visit[dir]) return false; // 재방문을 한다면 사이클 존재
        ans &= DFS(dir, idx, e); // 자식 쪽에서 사이클이 생긴다면 false로 변함
    }
    return ans;
}

bool Cycle(int idx) { // 사이클 존재 여부
    for (int k = 1; k <= num; k++) visit[k] = 0; // 초기화
    for (int k = 1; k <= num; k++) {
        if (visit[k] || k == idx) continue; // 이미 방문했거나, 예외처리인 위치
        if (!DFS(k, 0, idx)) return false;  // 사이클이 여전히 있다면 실패
    }
    return true;
}

int solution(int n, vector<vector<int>> edges) {
    num = n;
    for (vector<int> edge : edges) {
        int a = edge[0], b = edge[1];
        v[a].push_back(b);
        v[b].push_back(a); // 엣지 구성
    }

    for (int k = 1; k <= num; k++) pq.emplace_back(k, v[k].size()); // 쌍을 구성 후, 정렬
    sort(pq.begin(), pq.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    int answer = 0;
    for (pair<int,int> idx : pq) { // 차례로 살펴봄
        if (!Cycle(idx.first)) continue;
        answer += idx.first;
    }
    return answer;
}