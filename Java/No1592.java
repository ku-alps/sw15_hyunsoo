import java.util.Scanner;

// 영식이와 친구들
class No1592 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		// 사람 수, 받아야 할 공 횟수, 넘길 사람 수
		int N = sc.nextInt(), M = sc.nextInt(), L = sc.nextInt();
		int[] cnt = new int[N]; // 각자 받은 공 수

		int stage = 0, ball = 0; // 전체 던진 횟수, 초기 공의 위치는 0번
		while(++cnt[ball] < M) { // 아직 횟수를 못채웠으면 계속 던짐
			// 다음에 받을 사람번호를 계산
			ball = (ball + N + L*(cnt[ball]%2 == 0 ? -1 : 1)) % N; 
			stage += 1; // 던진 횟수도 증가
		}
		System.out.println(stage); // 출력
	}
}