#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// 타자연습

string str; // 문자열을 입력받음

int main() {

	int left, right, check; //왼쪽, 오른쪽, 분배 가능한 값
	left = right = check = 0; // 다 0으로 세팅
	
	getline(cin,str); //getline 을 통해 공백을 포함해 전부 입력
	for (int k = 0; k < str.size(); k++) { // 각 문자에 대해
		char a = str.at(k);
	
		switch (a) { 
		case 'q': // 왼쪽 손이면 (소문자 기준)
		case 'w':
		case 'e':
		case 'r':
		case 't':
		case 'y':

		case 'a':
		case 's':
		case 'd':
		case 'f':
		case 'g':

		case 'z':
		case 'x':
		case 'c':
		case 'v':
		case 'b':
			left += 1; // 왼쪽 +1
			break;
		case 'u': // 오른쪽 손이면 (소문자 기준)
		case 'i':
		case 'o':
		case 'p':

		case 'h':
		case 'j':
		case 'k':
		case 'l':

		case 'n':
		case 'm':
			right += 1;
			break;
		case ' ': // 공백인 경우
			check += 1; // 체크 +1
			break;
		default: // 그 외의 경우 (대문자)
			check += 1; // 체크 +1
			switch (a) // 내부적으로 다시 좌, 우를 구분
			{
			case 'Q':
			case 'W':
			case 'E':
			case 'R':
			case 'T':
			case 'Y':

			case 'A':
			case 'S':
			case 'D':
			case 'F':
			case 'G':

			case 'Z':
			case 'X':
			case 'C':
			case 'V':
			case 'B':
				left += 1;
				break;
			case 'U':
			case 'I':
			case 'O':
			case 'P':

			case 'H':
			case 'J':
			case 'K':
			case 'L':

			case 'N':
			case 'M':
				right += 1;
				break;
			}
			break;
		}
	}

	while (check != 0) { // 분배가능한 값이 0이 될때까지 시도
		int minus = left - right; // 두 값의 차이를 계산
		if (minus > 0) { // 양수 = 왼쪽이 더 많다
			int add = min(minus, check); // 남은 값과 차이 중, 작은값을 선택
			check -= add; 
			right += add; //적용
		}
		else if(minus < 0){ // 음수 = 오른쪽이 더 많다
			int add = min(-1 * minus, check);
			check -= add;
			left += add; // 적용
		}
		else { // 같은 경우, 왼손잡이므로 왼손 +1
			check -= 1;
			left += 1;
		}
	}

	cout << left << " " << right; // 출력
}