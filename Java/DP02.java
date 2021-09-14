import java.util.Scanner;

// DP 연습 2
class DP02 {
	static int n;
	static int memo[];
	
	static int dp(int length) {
		if( length == n ) return 1; // 딱 맞춰서 칠했으면 성공
		else if ( length > n ) return 0; // 넘어서면 계산안함
		
		if( memo[length] == 0 ) {
			memo[length] += dp(length+1); // 파란 막대 사용
			memo[length] += dp(length+1); // 노란 막대 사용
			memo[length] += dp(length+2); // 빨간 막대 사용
		}
		return memo[length];
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		memo = new int[n];

		int sum = dp(0);
		System.out.println(sum);
	}
}