import java.io.BufferedReader;
import java.io.InputStreamReader;

// 사칙연산 유효성 검사
class SW1233_ver_2 {
	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		for(int test_case = 1; test_case <= 10; test_case++) {
			boolean ans = true; // 가능 여부
			int NODE = Integer.parseInt(bf.readLine());
			for(int k=0; k<NODE; k++) {
				String[] input = bf.readLine().split(" "); // 입력 정보
				// 입력 정보가 3개 이상이면, 사칙연산이여야하고,
				// 2개 이하면 숫자여야 함
				ans &= input.length > 2 ^ !"+-*/".contains(input[1]);
			}
			
			System.out.println("#" + test_case + " " + (ans ? 1 : 0));
		}
	}
}