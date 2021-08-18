import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

// 요리사
class SW4012 {
	static int N; // 재료의 수
	static int[][] SYNERGY; // 시너지 정보

	static int comb(int idx, int n, int bit) {
		// 현재 인덱스, 선택한 갯수, 선택정보
		if( n == N/2 ) { // 다 골랐으면
			// 시너지 계산해서 반환
			int foodA = 0, foodB = 0; // 각 요리가 가질 재료들의 시너지 총합
			for(int k=0; k<N; k++) { // 비교 기준
				if((bit & (1<<k))!= 0) { // 선택했던 놈이라면
					for(int i=0; i<N; i++) { // 똑같이 선택한 놈들을 골라서 시너지값 확인
						if((bit & (1<<i)) != 0) foodA += SYNERGY[k][i];
					}
				}
				else { // 그 외에 나머지 요리재료면
					for(int i=0; i<N; i++) { // 남은 재료로 만든 요리의 시너지 확인
						if((bit & (1<<i)) == 0) foodB += SYNERGY[k][i];
					}
				}
			}
			return Math.abs(foodA - foodB); // 시너지의 차이값을 반환
		}

		int result = Integer.MAX_VALUE;
		for(int k=idx; k<N; k++) { // 남은 식재료들을 하나씩 선택해봄
			// 모든 경우의 수 중. 가장 작은 결과를 선택
			result = Math.min(result, comb(k+1, n+1, bit | (1<<k)));
		}
		return result;
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력
			N = Integer.parseInt(br.readLine());
			SYNERGY = new int[N][N];

			// 문자열을 읽고 공백으로 잘라서 숫자로 변환 및 저장
			for(int k=0; k<N; k++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int i=0; i<N; i++) SYNERGY[k][i] = Integer.parseInt(st.nextToken());
			}
			
			// 출력
			System.out.println("#"+test_case+" "+comb(0,0,0));
		}
	}
}