import java.util.Scanner;

// 원점으로 집합
class SW8458 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			int max = 0; // 최대거리
			int N = sc.nextInt(); // 점 갯수
			int oddEven = -1; // 거리 총합의 짝,홀
			for(int k=0; k<N; k++) {
				int x = Math.abs(sc.nextInt()); // 가로
				int y = Math.abs(sc.nextInt()); // 세로

				int len = x+y;
				if(max < 0) continue; // 이미 실패한 경우도 무시
				if(oddEven < 0) oddEven = len % 2; // 첫 설정
				else { // 이후에 등장한 점
					if( oddEven != len%2 ) { // 거리의 짝홀이 다르면 불가능
						max = -1;
						continue;
					}
				}
				int cnt=0, sum=0; // 전체 이동 거리
				while(sum < len) { // 최소한 필요한 거리만큼은 이동해야함
					sum += ++cnt; // i만큼의 거리를 반드시 이동
				}
	
				int leftover = sum-len;
				while(leftover%2 != 0) { // 남은 값이 짝수가 되어야 원점이동이 가능
					leftover += ++cnt;
				}
				max = Math.max(max, cnt);
			}
			System.out.println("#"+test_case+" "+max);
		}
	}
}