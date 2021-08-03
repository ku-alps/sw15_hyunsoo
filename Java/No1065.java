import java.util.Scanner;

// 한수
public class No1065 {
	public static void main(String[] args) {
		// '자연수' 이므로 1부터 모든 값을 탐색
		// 등장할 수 있는 모든 수열을 생성
		Scanner sc = new Scanner(System.in);
		final int NUMBER = sc.nextInt();
		
		int cnt = 0;
		for(int k=1; k<10; k++) { // 1~9까지가 키워드
			// A, AA, AAA, AAAA 도 등차수열 ( 각 수는 0차이 )
			int calc = 0;
			while( true ) {
				calc = calc * 10 + k;
				// 범위 초과면 종료
				if ( calc > NUMBER ) break;
				cnt++;
			}

			for(int i=1; i<10; i++) { // 증감값을 1씩 증가하면서 탐색
				int nextUp, nextDown; // 다음 자리 수
				nextUp = nextDown = k;

				// 증가 수열
				calc = k; // 맨 앞자리는 k
				while( true ) {
					nextUp += i; // 수열 생성
					if( nextUp > 9 ) break; // 2자릿 수로 넘어가면 종료
					
					calc *= 10; // 자릿수 올려서 값을 생성
					calc += nextUp;

					// 범위 초과면 무시
					if ( calc > NUMBER ) break;
					cnt++;
				}
				
				// 감소 수열
				calc = k; // 맨 앞자리는 k
				while( true ) {
					nextDown -= i; // 수열 생성
					if( nextDown < 0 ) break; // 음수는 의미없음
					
					calc *= 10; // 자릿수 올려서 값을 생성
					calc += nextDown;

					// 범위 초과면 무시
					if ( calc > NUMBER ) break;
					cnt++;
				}
			}
		}
		// 모든 경우 수의 총합 출력
		System.out.println(cnt);
	}
}
