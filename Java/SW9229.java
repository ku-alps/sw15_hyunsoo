import java.util.Scanner;

// 한빈이와 Spot Mart
class SW9229 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			int N = sc.nextInt(), M = sc.nextInt(); // 과자봉지 수, 가능한 무게

			int[] w = new int[N]; // 과자 각각의 무게
			for(int k=0; k<N; k++) w[k] = sc.nextInt();

			// 반드시 2개를 골라야 하므로, 반복문 2번으로 조합
			int ans = -1; // 불가능하면 -1
			for(int k=0; k<N; k++) {
				for(int i=k+1; i<N; i++) {
					int sum = w[k] + w[i];
					if( sum <= M ) ans = Math.max(ans, sum);
				}
			}
			// 출력
			System.out.println("#"+test_case+" "+ans);
		}
	}
}