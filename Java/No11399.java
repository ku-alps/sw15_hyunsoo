import java.util.Arrays;
import java.util.Scanner;

// ATM
class No11399 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 사람 수
		
		// 걸리는 시간을 모두 입력받고 정렬 
		int[] time = new int[N]; // 걸리는 시간
		for(int k=0; k<N; k++) time[k] = sc.nextInt(); // 입력
		Arrays.sort(time); // 정렬

		// 걸리는 시간은 대기시간까지 모두 포함하므로, 앞에서부터 누적 합을 만듦
		int totalSum = time[0]; // 전체 걸리는 시간
		for(int k=1; k<N; k++) {
			 totalSum += time[k] += time[k-1]; // 앞에서 쌓인 누적합을 더함
		}
		System.out.println(totalSum); // 출력
	}
}