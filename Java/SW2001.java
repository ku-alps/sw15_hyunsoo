import java.util.Scanner;

// 파리 퇴치
class SW2001 {
	public static void main(String args[]) throws Exception {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)	{
			int max = 0;
			
			int N = sc.nextInt(), M = sc.nextInt();
			// 인덱스 0은 예외처리용으로 생성 (빈 값)
			int[][] map = new int[N+1][N+1];

			// 1번 방부터 채우기
			for(int x=1; x<=N; x++) {
				for(int y=1;y<=N; y++) {
					// 누적 합으로 배열을 생성 ( 왼쪽 + 위쪽 + 신규 값 - 중복부분 )
					map[x][y] = map[x-1][y] + map[x][y-1] 
							- map[x-1][y-1] + sc.nextInt();
				}
			}
			
			// 최대값이기 떄문에 파리채가 바닥에 전부 닿는 시점부터 탐색
			for(int x=M; x<=N; x++) {
				for(int y=M; y<=N; y++) {
					// 누적합 개념이므로, 불필요한 지역을 쳐내고 중복된 부분을 처리해줄 것
					int val = map[x][y] + map[x-M][y-M]
							- (map[x-M][y] + map[x][y-M] );
					max = Math.max(max, val);
				}
			}
			
			System.out.println("#"+test_case+" "+ max);
		}
	}
}