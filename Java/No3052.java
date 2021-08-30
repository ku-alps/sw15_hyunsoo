import java.util.Scanner;

// 나머지
class No3052 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		final int N = 42; // 나눠버릴 값
		int cnt = 0; // 중복하지 않은 값의 수
		boolean[] check = new boolean[N]; // 0~41의 등장 여부
		for(int k=0; k<10; k++) { // 입력값은 10개
			int leftover = sc.nextInt() % N; // 입력값을 42로 나눈 나머지
			cnt += !check[leftover] ? 1 : 0; // 처음 나온 값이면 1 증가, 아니면 제외
			check[leftover] = true; // 등장했음
		}
		System.out.println(cnt);
	}
}