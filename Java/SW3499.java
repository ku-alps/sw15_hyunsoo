import java.util.Scanner;

// 퍼펙트 셔플
class SW3499 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			int size = sc.nextInt();
			String[][] arr = new String[2][]; // 나눠진 배열
			arr[0] = new String[size/2 + size%2]; // 홀수면 a가 한칸 더 큼
			arr[1] = new String[size/2];
			for(int k=0; k<arr.length; k++) { // 입력
				for(int i=0; i<arr[k].length; i++) {
					arr[k][i] = sc.next();
				}
			}

			System.out.print("#"+test_case);

			int arrIdx = 0; // 이번에 보는 배열
			int[] idx = new int[2]; // 각 배열이 다음에 읽어야하는 인덱스 시점
			while( idx[arrIdx] < arr[arrIdx].length ) {
				// 두 배열 중 남은게 하나라도 있으면 계속 진행
				System.out.print(" " + arr[arrIdx][idx[arrIdx]++]);
				arrIdx = (arrIdx+1)%2; // 다음 배열로 넘어감
			}
			System.out.println();
		}
	}
}