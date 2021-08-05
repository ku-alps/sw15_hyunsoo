import java.util.Scanner;
import java.util.Stack;

// 괄호 짝짓기
class SW1218 {
	static Scanner sc;
	// 사용할 스택
	static Stack<Character> st = new Stack<>();

	// 괄호를 제대로 닫을 수 있는지 확인
	static boolean closeBox(char ch) {
		boolean success = false;
		if(!st.isEmpty()) { // 비어있으면 그냥 건너뜀 (실패)
			char open = st.pop(); // 현재 마지막으로 열린 괄호
			switch (ch) { // 닫힌 괄호 종류에 따라서 제대로 닫혔는지 확인
				case ')':
					success = (open == '(');
					break;
				case '}':
					success = (open == '{');
					break;
				case ']':
					success = (open == '[');
					break;
				case '>':
					success = (open == '<');
					break;
			}
		}
		return success; // 결과 반환
	}
	
	 // 각 테스트를 실행시킬 구문
	static int test() {
		sc.nextInt(); // 입력 문자열 정보를 사용할 것이므로, 길이정보는 버림
		st.clear(); // 각 케이스별로 스택 비우기
		for(char ch: sc.next().toCharArray()) { // 문자 하나하나를 사용
			switch (ch) {
				case '(':
				case '{':
				case '[':
				case '<':
					st.push(ch); // 열린괄호면 단순하게 삽입
					break;
				default: // 닫는 괄호면 종료 확인
					if(!closeBox(ch)) return 0;
					break;
			}
		}
		return st.isEmpty() ? 1 : 0; 
	}
	
	// 메인
	public static void main(String args[]) throws Exception {
		sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++) {
			// 출력
			System.out.println("#" + test_case + " " + test());
		}
	}
}