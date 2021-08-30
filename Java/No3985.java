import java.util.Scanner;

// 롤 케이크
class No3985 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int L = sc.nextInt(), N = sc.nextInt(); // 롤케이크 길이, 방청객 수
		
		boolean[] eat = new boolean[L+1]; // 각 롤케이크 부위 (먹혔는가?)
		int[] wantEat = new int[N+1]; // 먹기 원하는 조각 수
		int[] canEat = new int[N+1]; // 실제 먹을 수 있는 조각 수

		int wIdx = 0, cIdx = 0; // 정답이 될 배열 인덱스 값
		for(int k=1; k<=N; k++) {
			int from = sc.nextInt(), to = sc.nextInt();
			wantEat[k] = to-from + 1; // 두 값의 차이가 원하는 조각 수
			
			int cnt = 0; // 먹은 조각 수
			for(int i=from; i<=to; i++) {
				if(eat[i]) continue; // 누가 먹은 조각이면 무시
				eat[i] = true;
				cnt++; // 먹은 조각 증가
			}
			canEat[k] = cnt; // 해당 방청객이 실제로 먹은 조각 수

			// 각각에 대해서 더 큰 놈을 선택
			if( wantEat[wIdx]<wantEat[k] ) wIdx = k;
			if( canEat[cIdx]<canEat[k] ) cIdx = k;
		}
		
		// 출력
		System.out.println(wIdx);
		System.out.println(cIdx);
	}
}