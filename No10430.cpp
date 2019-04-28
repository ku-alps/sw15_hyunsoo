#include<iostream>
using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C; //값 입력

	cout << (A + B) % C << endl;
	cout << ((A % C) + (B % C)) % C << endl;
	cout << (A * B) % C << endl;
	cout << ((A % C) *(B % C)) % C << endl; //각각 출력
}