import java.util.Scanner;

// 농작물 수확하기
class SW2805 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)	{
			int size = sc.nextInt();

			int sum = 0; // 농작물 총 합
			for(int x=0; x<size; x++) {
				// 한 줄씩 읽으면서 처리
				char[] row = sc.next().toCharArray();
				int outOfBox = Math.abs(size/2 - x); // 각 라인별 포함되지 않는 박스의 수
				for(int y=outOfBox; y < size-outOfBox; y++) {
					// 버리는 앞쪽 부분 + 뒤쪽 부분 무시
					sum += row[y] - '0'; // 농작물의 가치가 0~5 이므로, 아스키코드로 처리 가능
				}
			}
			System.out.println("#" + test_case + " " + sum);
		}
	}
}