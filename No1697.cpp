#include<iostream>
using namespace std;

void Hide_And_Seek(); // 숨바꼭질 함수
void Walk(int index, int depth); //걷기 함수
void Back(int index, int depth); //-1
void Jump(int index, int depth); //순간이동 함수

int* info; //정보를 저장할 배열
int me; //내 위치
int sis; //동생 위치
		 // 해당 문제는 다이나믹 프로그래밍 (미모아이제이션)
		 // 수 차례 틀린답이 나온 이유는 jump,back 순서의 정답에서 문제
		 // so, 배열 크기를 sis+1에서 sis+2로 확장

int main() {


	cin >> me >> sis; // 위치입력받음
	info = new int[sis + 2]; //동생 위치만큼의 배열 +2칸 (2배 후, -1 하는 경우)

	for (int i = 0; i < sis + 2; i++) {
		info[i] = 99999999;
	}
	//메모리 초기화
	// memset을 쓸려그랬는데 자꾸 안먹어서.. 결국 for문 구현
	Hide_And_Seek();
	delete[] info; //동적할당 삭제
}

void Hide_And_Seek() { //숨바꼭질 함수


	if (me >= sis) //내가 동생위치보다 뒤에있으면, -1로만 이동해야함
		cout << me - sis << endl;
	else {
		Jump(me * 2, 0);
		Walk(me + 1, 0);
		Back(me - 1, 0);
		//각각에 대해서 최선의 수의 경우 생각

		cout << info[sis] << endl;
	}
}
void Walk(int index, int depth) {
	if ((index > -1 && index < sis + 2) && info[index] > depth) { //인덱스에 저장된 값보다 내 횟수가 더 짧으면
		depth++; //깊이도 +1
		info[index] = depth; //갱신

		if (index == sis) //도착했으면 
			return; //종료
		else { // 아니라면
			Jump(index * 2, depth); //2배 점프시키고 깊이 넣고
			Walk(index + 1, depth); //한칸 전진
									// 앞으로 나간경우, 뒤돌아가는 수는 필요x (반복)
		}
	}
}
void Back(int index, int depth) {
	if ((index>-1 && index<sis + 2) && info[index] > depth) { //인덱스에 저장된 값보다 내 횟수가 더 짧으면
		depth++; //깊이도 +1
		info[index] = depth; //갱신

		if (index == sis) //도착했으면 
			return; //종료
		else { // 아니라면
			Jump(index * 2, depth); //2배 점프시키고 깊이 넣고
			Back(index - 1, depth); //한칸 빽
									// 뒤로 간 경우, 앞으로 가는 수 필요x
		}
	}
}
void Jump(int index, int depth) {
	if ((index>-1 && index<sis + 2) && info[index] > depth) { //인덱스에 저장된 값보다 내 횟수가 더 짧으면
		depth++; //깊이도 +1
		info[index] = depth; //갱신

		if (index == sis) //도착했으면 
			return; //종료
		else { // 아니라면
			Jump(index * 2, depth); //2배 점프시키고 깊이 넣고
			Walk(index + 1, depth); //한칸 전진
			Back(index - 1, depth); //한칸 빽
		}
	}
}