import java.util.Scanner;

// 쇠막대기 자르기
class SW5432 {
	// 입력 정보를 담을 스택
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			// 전제 조건 3에 의해서, 닫는 괄호가 등장하면 무조건 레이저를 표현
			// 이후 연속적으로 닫히는 경우는 모두 쇠막대기

			int cut = 0; // 잘린 파이프 갯수
			int openCnt = 0; // 현재 열려있는 괄호 갯수
			boolean isOpen = false;
			for(char ch: sc.next().toCharArray()) { // 각 문자를 하나씩 읽는다
				// 여는괄호면 신경쓰지 않고 전부 넣음
				if( ch == '(' ) {
					isOpen = true; // 현재 마지막으로 읽은 놈은 열린 괄호
					openCnt++; // 열린 갯수 증가
				}
				else {
					if( isOpen ) { // 열려있는 상태였으면
						openCnt--; // 마지막 열린 기호는 레이저이므로 제거
						cut += openCnt; // 현재까지 열려있는 괄호는 전부 파이프이므로 잘려나감
						isOpen = false;
					}
					else { // 닫힌 상태가 연속으로 등장했다면 전부 파이프
						openCnt--;
						cut++; // 하나씩 덩어리가 증가
					}
				}	
			}
			System.out.println("#"+test_case+" "+cut);
		}
	}
}