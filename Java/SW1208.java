import java.util.Scanner;

// Flatten
class SW1208 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 총 10회의 테스트케이스
		for(int test_case = 1; test_case <= 10; test_case++) {
			// 입력 및 세팅
			int temp = sc.nextInt();
			int map[] = new int[100];
			
			for(int k=0; k<100; k++) map[k] = sc.nextInt();

			// 옮길 수 있는 횟수를 전부 소모
			for(int k=0; k<temp; k++) {
				int max = searchMax(map);
				int min = searchMin(map);
				map[max]--; // 박스를 뺴서
				map[min]++; // 낮은 곳에 채워넣음
			}
			
			// 높이 차이 계산
			int ans = map[searchMax(map)] - map[searchMin(map)];
			System.out.println("#"+test_case+" "+ans);
		}
	}
	
	// 가장 높은 곳의 좌표를 반환
	static int searchMax(int[] map) {
		int idx = 0;
		for(int k=0; k<map.length; k++) idx = map[idx] >= map[k] ? idx : k;
		return idx;
	}
	// 가장 낮은 곳의 좌표를 반환
	static int searchMin(int[] map) {
		int idx = 0;
		for(int k=0; k<map.length; k++) idx = map[idx] <= map[k] ? idx : k;
		return idx;
	}
}
