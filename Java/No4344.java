import java.util.Scanner;

// 평균은 넘겠지
public class No4344 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 테스트 케이스 돌리기
		for(int k=sc.nextInt(); k>0; k--) {
			int students = sc.nextInt();

			int sum = 0; // 총 합
			int[] arr = new int[students]; // 학생 점수
			for(int i=0; i<students; i++) {
				arr[i] = sc.nextInt();
				sum += arr[i];
			}
			
			// 평균 이상 학생의 퍼센티지 계산
			float percent = 0.0f;
			float avg = (float)sum / students; // 평균 정보 계산
			for(int score: arr) {
				percent += score > avg ? 1 : 0;
			}
			percent /= students;
			percent *= 100;
			System.out.printf("%.3f%%\n", percent);
		}
	}

}
