import java.util.Scanner;

// Z
class No1074 {	
	static int order(int n, int r, int c) {
		// 작은 분기로 쪼개서 처리
		// divide and conquer
		if( n == 0 ) return 0; // 한칸 짜리면 제일 처음

		int half = (int)Math.pow(2, n-1); // 절반만큼의 크기
		int quarter = ( r<half ? 0 : 2 ) + ( c<half ? 0 : 1 );
		// 4분면 중, 해당 지점의 위치를 파악 (좌측 상단 -> 우측 상단 -> 좌측 하단 -> 우측 하단)
		// 이 정보를 기준으로, 내 앞쪽에 있는 분기값 처리 + 속한 사분면에서의 위치를 재귀탐색
		return half*half*quarter + order(n-1, r%half, c%half);
	}
	
	public static void main(String args[]) throws Exception {
		// 입력
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), R = sc.nextInt(), C = sc.nextInt();
		
		// 함수 호출 및 출력
		System.out.println(order(N, R, C));
		sc.close();
	}
}