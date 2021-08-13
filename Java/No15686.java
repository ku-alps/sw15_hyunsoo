import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// 치킨 배달
class No15686 {
	static int N, M; // 맵의 크기, 고를 수
	static List<Integer[]> cStore = new ArrayList<>(); // 치킨 집
	static List<Integer[]> house = new ArrayList<>(); // 집 위치

	// 값 바꾸기
	static void swap(int[] arr, int f, int b) {
		int tmp = arr[f];
		arr[f] = arr[b];
		arr[b] = tmp;
	}
	
	// 순차 순열
	static boolean nextPermutation (int[] arr) {
		int idx = arr.length; // 시작점
		while(--idx > 0) { // 전부를 다 볼 동안
			if(arr[idx-1] < arr[idx]) break; // 내 앞쪽이 작아지는 순간을 찾음
		}
		
		if( idx == 0 ) return false; // 맨 앞까지 내림차순 정렬이라면, 가장 크다는 이야기
		
		int cIdx = arr.length; // 바꿀 지점의 인덱스 찾기 (찾은 지점보다 커지는 순간)
		while(arr[--cIdx] <= arr[idx-1]);
		
		swap(arr, idx-1, cIdx); // 꺾이는 구간이랑, 찾은 다음 값이랑 바꾸기

		int backIdx = arr.length - 1; // 앞뒤를 재정렬하는 과정
		while(idx <= backIdx) swap(arr, idx++, backIdx--);
		
		return true;
	}
	
	// 치킨집 고르기
	static int combination() {
		// np 를 위한 임시배열 만들기
		int[] arr = new int[cStore.size()];
		for(int k=1; k<=M; k++) arr[arr.length-k] = 1; // 뒤쪽부터 고를 수만큼 1 채우기

		int res = Integer.MAX_VALUE; // 결과로 제출할 가장 작은 치킨거리
		do { // 이번 조합에 대한 계산
			int sum = 0;
			for(Integer[] hPos: house) { // 각 집에 대해서 가까운 치킨집 거리를 탐색
				int chickLen = Integer.MAX_VALUE;
				for(int k=0; k<arr.length; k++) { 
					if(arr[k] != 1) continue; // 1이 아니면 폐업된 지점
					
					// 가정찝과 치킨집의 좌표 차이로 거리를 계산
					int calc = 0;
					Integer[] cPos = cStore.get(k);
					for(int i=0; i<2; i++) calc += Math.abs(hPos[i]-cPos[i]);
					chickLen = Math.min(chickLen, calc); // 해당 집이 가진 최소 치킨거리 선택
				}
				sum += chickLen; // 지역의 치킨거리에 더함
			}
			res = Math.min(res, sum); // 새 치킨집 거리와 기존 값 중 최소값 택
		} while(nextPermutation(arr)); // 다음 조합을 만듦

		return res; // 결과 반환
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 입력
		N = sc.nextInt();
		M = sc.nextInt(); 
		for(int x=0; x<N; x++) {
			for(int y=0; y<N; y++) {
				int field = sc.nextInt(); // 해당 지점의 분류
				if (field == 1) house.add(new Integer[] {x, y}); // 1번은 집
				else if(field == 2) cStore.add(new Integer[] {x, y}); // 2번은 치킨집
			}
		}
		
		System.out.println(combination());
		sc.close();
	}
}