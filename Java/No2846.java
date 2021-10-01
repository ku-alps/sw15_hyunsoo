import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

// 오르막길
class No2846 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 등교길 크기
		
		// 정답값 (최대 크기의 오르막길)
		int slide=Integer.MAX_VALUE, ans=0;
		int[] road=new int[N+1];
		for(int k=1; k<=N; k++) {
			int height = sc.nextInt(); // 현재 지점의 높이값
			if( slide < height ) { // 오르막길을 만든다
				// 이전까지의 오르막길 차이값 + 이번에 생긴 오르막길 값
				road[k] = road[k-1]+ (height-slide);
				ans = Math.max(ans, road[k]); // 등장한 오르막길 중 최대치 선택
			}
			slide = height; // 높이값 갱신
		}
		System.out.println(ans); // 출력
	}
}