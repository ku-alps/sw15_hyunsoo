import java.util.Scanner;

// 최장 증가 부분 수열
class SW3307 {
	static int N, top;
	static int[] list;
	
	static int binarySearch(int f, int b, int val) { // 이분탐색
		if(f > b) return f; // 찾을 수 있는거 다 찾았다면 그 값을 선택
		
		int m = (f+b)/2; // 중앙 값
		if(list[m] == val) return m; // 찾는 값이랑 일치하면 끝
		
		// 찾는 값이 안나왔으면 크기 비교
		return list[m] > val ?
				binarySearch(f, m-1, val): // 작은 범위를 탐색
				binarySearch(m+1, b, val); // 큰 범위를 탐색
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int test_case = 1; test_case <= T; test_case++) {
			N = sc.nextInt(); // 총 숫자 갯수
			top = 0; // 리스트의 시작인덱스  0
			list = new int[N+1]; // 최장길이가 i를 만드는 숫자값
			list[0] = Integer.MIN_VALUE;
			
			for(int k=0; k<N; k++) { // 숫자 하나씩 받아옴
				int num = sc.nextInt();
				int pos = binarySearch(0, top, num); // 넣을 위치

				if( pos > top ) {
					top++; // 넣을 공간이 끝이면 추가하고 꼭대기 올림
					list[pos] = num; // 해당 값을 덮어씀
				}
				else { // 이미 있는 값이 있으므로 비교 후에 넣음
					list[pos] = Math.min(list[pos],num);
				}
			}
			// 출력
			System.out.println("#"+test_case+" "+top);
		}
	}
}