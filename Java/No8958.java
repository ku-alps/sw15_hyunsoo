import java.io.BufferedReader;
import java.io.InputStreamReader;

// OX퀴즈
class No8958 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine()); // 테스트 케이스

		for(int test_case = 1; test_case <= T; test_case++) {
			
			char[] oxQuiz = br.readLine().toCharArray(); // 문자 배열로 변환
			
			int score = 0, acc = 0; // 전체 점수, 누적 점수
			for(char ox: oxQuiz) {
				// 정답이면 +1 을 증가시킨 값을 전체 점수에 더하고, 틀렸다면 0으로 초기화
				score += ( acc = ox=='O' ? acc+1 : 0);
			}
			System.out.println(score); // 출력
		}
	}
}