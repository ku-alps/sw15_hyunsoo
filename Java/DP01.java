import java.util.Scanner;

// DP 연습 1
class DP01 {
	static int n;
	static int[][] memo;
	
	static int dp(int floor, int isBlue) {
		if( floor == n ) return 1; // 딱 맞춰서 칠했으면 성공
		else if ( floor > n ) return 0; // 넘어서면 계산안함
		
		if( memo[floor][isBlue] == 0 ) {
			if( isBlue == 1 ) { // 이번 층을 칠한게 파랑이라면
				// 노랑으로 칠함
				memo[floor][isBlue] += dp(floor+1, 0); // 한층
				memo[floor][isBlue] += dp(floor+2, 0); // 또는 두층을 칠함
			}
			else { // 이번층이 노랑이면 다음은 파랑
				memo[floor][isBlue] += dp(floor+1, 1);
			}
		}
		return memo[floor][isBlue];
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		memo = new int[n][2];
		
		int sum = dp(0, 1) + dp(0, 0);
		System.out.println(sum);
	}
}