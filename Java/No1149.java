import java.util.Scanner;

// RGB거리
class No1149 {
	static int[][] price; 
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt(); // 건물 수
		price = new int[N+1][3]; // N번째 집의 색을 R,G,B 로 칠할 때의 최소 가격
		
		for(int k=1; k<=N; k++) {
			for(int i=0; i<3; i++) {
				int color = sc.nextInt(); // 색칠에 드는 비용
				price[k][i] = Integer.MAX_VALUE; // 연산을 위한 초기화

				// dp 연산
				for(int j=0; j<3; j++) {
					if ( i == j ) continue; // 같은 색은 칠하지 못함					
					price[k][i] = Math.min(price[k][i], price[k-1][j]);
					// 이전 블록의 결과 값 중, 작은 값을 가져와서 선택
				}
				price[k][i] += color; // 실제 색칠을 진행
			}
		}
		// 마지막 집에 색칠하는 3가지 경우의 수 중, 가장 작은 경우를 선택
		int ans = Integer.MAX_VALUE;
		for(int i=0; i<3; i++) ans = Math.min(ans, price[N][i]);
		System.out.println(ans);
	}
}