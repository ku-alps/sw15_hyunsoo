import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

// 계산기2
class SW1223 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int test_case = 1; test_case <= 10; test_case++) {
			br.readLine(); // 길이는 읽어서 버림

			long plus = 0; // 계산식의 총 합
			
			// 덧셈 기준으로 문자열 자르기
			StringTokenizer plusSt = new StringTokenizer(br.readLine(), "+");
			while(plusSt.hasMoreTokens()) { // 문자열이 있으면 계속 진행
				long multi = 1; // 곱셈연산이 우선적으로 이뤄져야하고, 초기값은 무조건 1

				// 나눗셈 기준으로 문자열 자르기
				StringTokenizer multiSt = new StringTokenizer(plusSt.nextToken(), "*");				
				while(multiSt.hasMoreElements()) multi *= Integer.parseInt(multiSt.nextToken());
				plus += multi; // 총 합 구하기
			}
			
			System.out.println("#"+test_case+" "+plus);
		}
		br.close();
	}
}