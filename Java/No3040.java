import java.util.Scanner;

// 백설 공주와 일곱 난쟁이
class No3040 {
	static final int S = 7;
	static final int N = 9;
	static int[] dwaf = new int[N]; // 드워프 키 정보
	
	static void search(int idx, int sum, int cnt, int bit) {
		// 비트마스킹으로 사용 대상을 파악
		if( cnt == S ) { // 7명을 선택했을 때
			if(sum == 100) { // 100 이면  성공
				// 선택한 난쟁이들의 값을 출력
				for(int k=0; k<N; k++) if((bit & 1<<k) != 0) System.out.println(dwaf[k]);
			}
			return;
		}
		for(int k=idx; k<N; k++) search(k+1, sum+dwaf[k], cnt+1, bit | 1<<k);
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		for(int k=0; k<N; k++) dwaf[k] = sc.nextInt();
		search(0, 0, 0, 0);
	}
}