import java.util.Arrays;
import java.util.Scanner;

// 블랙잭
class No2798 {		
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		int N = sc.nextInt(), M = sc.nextInt(); // 카드 수, 기준값
		int[] cards = new int[N]; // 카드 값 
		for(int k=0; k<N; k++) cards[k] = sc.nextInt(); // 입력

		// 3장을 뽑으며 최대값 고르기
		int maxSum = 0; // 최대 합
		for(int one=0; one<N; one++) { // 첫번쨰 카드 고르기
			for(int two=one+1; two<N; two++) { // 두번째 카드 고르기
				for(int three=two+1; three<N; three++) { // 세번째 카드 고르기
					int newSum = cards[one] + cards[two] + cards[three]; // 세 카드의 합
					// 제한 값을 넘지않으면 최대값이 될 가능성이 있음
					if(newSum <= M) maxSum = Math.max(maxSum, newSum);
				}
			}
		}
		System.out.println(maxSum); // 출력
	}
}