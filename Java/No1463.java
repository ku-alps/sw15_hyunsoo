import java.util.Scanner;

// 1로 만들기
class No1463 {
	static int dp[];
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		dp = new int[N+1]; // 해당 숫자를 만드는데 소요되는 최소 연산 수
		for(int k=2; k<=N; k++) {
			dp[k] = dp[k-1]; // 1을 빼는 경우
			if(k%3 == 0) // 3으로 나눠지는 경우
				dp[k] = Math.min(dp[k], dp[k/3]);
			if(k%2 == 0) // 2로 나눠지는 경우
				dp[k] = Math.min(dp[k], dp[k/2]);
			dp[k] += 1; // 연산에 소요된 값을 1 증가시킴
		}
		System.out.println(dp[N]);
	}
}