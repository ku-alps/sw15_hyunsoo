import java.io.BufferedReader;
import java.io.InputStreamReader;

// 성수의 비밀번호 공격
class SW6026 {
	static final long MOD = 1000000007;
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			String[] MN = br.readLine().split(" ");
			int M=Integer.parseInt(MN[0]); // 사용된 문자 갯수
			int N=Integer.parseInt(MN[1]); // 문자열 길이
			
			// 문자 M개를 모두 사용해서 길이 N짜리 문자열을 만들 수 있는 모든 케이스
			long[][] dp = new long[M+1][N+1];
			dp[0][0] = 1; // 0개로 1개를 만드는 방법은 1가지
			for(int m=1; m<=M; m++) {
				for(int n=1; n<=N; n++) {
					// 문자 m개를 다 사용한 경우 + 문자를 m-1개만 사용한 경우
					// m개를 모두 사용해서 n-1 길이의 문자열을 만든 경우,
					// 마지막으로 들어올 수 있는 문자는 m개 (모두 가능)
					// m-1개를 모두 사용해서 n-1 길이의 문자열을 만든 경우,
					// 마지막으로 들어올 수 있는 문자는 1개 (단, m개의 문자에 대해 각각 적용 가능)
					// so, 두 값의 합 * 사용된 문자수 m 이 dp의 수식이 된다
					dp[m][n]=((dp[m][n-1]+dp[m-1][n-1])*m)%MOD;
				}
			}
			System.out.println("#"+test_case+" "+dp[M][N]);
		}
	}
}