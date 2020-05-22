// 방학숙제

#include<iostream>
using namespace std;
int main() {
	int vacation;
	int lang, math, cando_l, cando_m;
	cin >> vacation >> math >> lang >> cando_m >> cando_l;
	//싹 입력받고
	int need = lang / cando_l > math / cando_m ? (lang + cando_l - 1) / cando_l : (math + cando_m - 1) / cando_m;
		//두 경우 중 더 큰 값을 선택
		// 딱 떨어지지 않는 이상, 마무리를 위해서는 하루를 더 소비해야함.
		// but, 단순히 결과에 +1을 하기 위해선 나누어 떨어지는지 확인하는 과정이 필요,
		// 문제 해결을 위한 일반화를 식으로 표현
	cout << vacation - need << endl;
}