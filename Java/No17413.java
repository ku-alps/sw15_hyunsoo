import java.io.BufferedReader;
import java.io.InputStreamReader;

// 단어 뒤집기 2
class No17413 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = br.readLine(); // 열림 태그 기준으로 문자열을 자름
		boolean tag = false; // 태그가 열렸는가?
		int f = -1, b = -1; // 시작, 끝
		
		for(int k=0; k<input.length(); k++) {
			char ch = input.charAt(k); // 단어 하나하나 확인
			if(ch == '<') {
				// 새로 태그가 열리기 전까지 읽은 글자를 뒤집어서 출력
				for(int i=b; f<i; i--) {
					System.out.print(input.charAt(i));
				}
				f = b = k; // 다음 글자를 읽을 준비
				
				tag = true; // 태그 열기
				System.out.print('<');
			}
			else if(ch == '>') {
				tag = false; // 태그 닫기
				System.out.print('>');
				f = k; // 다시 단어가 시작될 가능성이 있음
			}
			else { // 그 외의 문자
				if(tag) System.out.print(ch); // 태그 정보면 그대로 출력
				else { // 태그 외엔 공백 단위로 뒤집어쓰기
					if(ch != ' ') b = k; // 공백이 아니라면 뒤집을 범위를 넓힘
					else {
						// 글자를 뒤집어서 출력
						for(int i=b; f<i; i--) {
							System.out.print(input.charAt(i));
						}
						System.out.print(' ');
						f = b = k; // 다음 글자를 읽을 준비
					}
				}
			}
		}
		if(f < b) { // 출력 안한 단어가 있다면 마저 출력
			// 글자를 뒤집어서 출력
			for(int i=b; i>f; i--) {
				System.out.print(input.charAt(i));
			}	
		}
	}
}