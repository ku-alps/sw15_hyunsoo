#include<iostream>
using namespace std;
// 벌집
// 규칙 수식을 이용한 풀이를 할 생각
// 중심부 1, 2~7(6개) - 2층라인, 8~19(12) - 3층라인.. 
// 2*2 + 1*2 , 3*2 + 3*2 , 4*2 + 5*2 ...
// n*2 + (1 + 2(n-2)) *2 의 수식을 갖고있음
// = 6n - 6

int main() {
	int room; //입력받을 룸 번호

	cin >> room; // 번호입력받고
	
	int total = 1; //1을 덮은 전체 방 수
	int index = 1; //그 방의 겹 번호

	while (total < room) { //방 번호를 쭉 더하면서. 해당 방이 나올 때 까지 시도
		// room보다 total 값이 커지는 경우, 해당 index가 room의 겹 번호
		index++; //방 겹을 한겹 더 감싸고
		total += index * 2 + (1 + 2 * (index - 2)) * 2; //해당 수식을 적용
	} //반복문을 빠져나오면, 해당 겹 수 == 최단거리 수
	
	cout << index << endl; //출력
}