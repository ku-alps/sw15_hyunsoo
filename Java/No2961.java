import java.util.Scanner;

// 도영이가 만든 맛있는 음식
class No2961 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] flavor = new int[N][2]; // 1번은 신맛, 2번은 쓴맛
		for(int k=0; k<N; k++) for(int i=0; i<2; i++) flavor[k][i] = sc.nextInt();
				
		// 바이너리 카운팅 = 하나의 숫자가 가지는 비트정보를 '조합' 정보로 바라보는 방식
		int differ = Integer.MAX_VALUE; // 신맛과 쓴맛의 차이값
		int limit = 1 << N; // 비트마스킹 시, 살펴봐야 할 경우수의 마지막
		for(int binary=1; binary<limit ; binary++) {
			// 음식 재료는 최소 하나이상 들어가야 하므로 1부터 시작
			int bitter = 1, sour = 0; // 쓴맛, 신맛
			for(int k=0; k<N; k++) { // 각 재료의 사용 여부 확인
				if((binary & 1<<k)!=0) { // 사용되는 재료에 대해서 값 계산
					bitter *= flavor[k][0];
					sour += flavor[k][1];
				}
			}
			// 기존 정답과 새로 만들어진 요리가 가지는 차이 중, 작은걸 선택
			differ = Math.min(differ, Math.abs(bitter - sour));
		}
		// 출력
		System.out.println(differ);
	}
}