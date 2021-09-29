import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 구간 합
class SW5604 {
	static long SUM[] = new long[17]; // 자릿수 n인 구간의 전체 합
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		SUM[0] = 0;
		SUM[1] = 45; // 1의 자리들의 총 합은 45
		for(int k=2; k<17; k++) { // 10의 N승이 가지는 총 합
			// 이전 단계의 합이 총 10번 등장 (0~9) + 현재 자릿수 값은 10의 승수만큼 등장
			SUM[k] = SUM[k-1]*10 + (long)(45*Math.pow(10, k-1));
		}
		
		for(int test_case = 1; test_case <= T; test_case++) {
			String[] AB = br.readLine().split(" ");
			long[] calc = new long[2]; // 계산저장용 배열

			for(int k=0; k<2; k++) { // 각 수에 대해서 해당 숫자까지의 누적 합 계산
				String number = AB[k]; // 현재 숫자
				
				while(number.length() > 0) { // 끝까지 다 보기 전까지
					int head = Integer.parseInt(number.substring(0, 1));
					String subNum = number.substring(1);
					// head 값 전까지는 전체값을 가짐
					int subLen = subNum.length();
					for(int i=0; i<head; i++) {
						calc[k] += SUM[subLen]+(long)(Math.pow(10,subLen)*i);
					}
					// head 값은 자기 뒤쪽 값 +1만큼 등장
					calc[k] += head*(Long.parseLong("0"+subNum)+1);
					number = subNum; // 다음 값으로 넘김
				}
			}
			
			long ans = calc[1]-calc[0]; // 첫 값은 구간에 포함시킴
			for(char ch: AB[0].toCharArray()) {
				ans += Integer.parseInt(""+ch);
			}
			
			System.out.println("#"+test_case+" "+ans);
		}
	}
}