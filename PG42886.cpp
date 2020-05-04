#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 저울
// 완전 탐색방법을 사용하려 했으나, 시간초과가 발생
// so, 이전까지 탐색에 성공한 값들은 무조건 만들 수 있다는 가정을 기반으로
// 누적 합을 통해 값의 탐색을 시도

// 다만, 추가적으로 탐색값을 1씩 증가시키는 것이 아닌,
// 누적합을 따라 바로 이동시키는 형태를 사용해야만 효율성 테스트를 통과할 수 있음

long long int solution(vector<int> weight) {
    
    sort(weight.begin(), weight.end()); // 정렬

    long long int idx = 0, val = 0, mw = 1; // 값의 누적합이 int 형을 벗어남
    while (idx <= weight.size()) { // 누적 합을 생성
        if (val < mw) { // 현재 보는 값이 누적합보다 크다면,
            val += weight[idx++]; // 누적 합을 더 키움
            continue;
        }
        if (val >= 2 * mw) break; 
        // "누적합 - 탐색값 < 탐색값" 이 성립해야 해당 값을 만들 수 있음
        // cause, 해당 시점 이전의 값은 모두 만들 수 있다는 전제가 있기 때문

        mw = val + 1; // 현재 누적값까진 생성이 가능하므로 다음으로 넘어감
    }

    return mw;
}