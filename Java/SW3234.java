import java.io.BufferedReader;
import java.io.InputStreamReader;

// 준환이의 양팔저울
class SW3234 {
	static int N; // 추의 개수
	static int[] WEIGHTS; // 추
	static long[][] memoization; // 기록

	// 재귀탐색
	static long balance(int left, int right, int lBit, int rBit) {
		// 왼쪽 무게 , 오른쪽 무게, 사용한 추
		if((lBit|rBit) == (1<<N)-1) return 1; // 모든 추를 다 사용했으면 성공
		if(memoization[lBit][rBit] != 0) return memoization[lBit][rBit];
		
		long cnt = 0; // 성공한 경우의 수
		// 모든 추를 살피며 다음에 놓을 놈을 선택
		for(int k=0; k<N; k++) {
			if(((lBit|rBit)&(1<<k)) != 0) continue; // 사용했던 놈은 무시
			if(left+WEIGHTS[k] >= right) // 왼쪽에 올리는 경우
				cnt += balance(left+WEIGHTS[k], right, lBit|(1<<k), rBit);
			if(left >= right+WEIGHTS[k]) // 오른쪽에 올리는 경우
				cnt += balance(left, right+WEIGHTS[k], lBit, rBit|(1<<k)); 
		}
		memoization[lBit][rBit] = cnt; // 좌우 사용 상태에 따라 나올 수 있는 경우수를 기록해둠
		return cnt; // 가능한 모든 경우 반환
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력
			N = Integer.parseInt(br.readLine());
			WEIGHTS = new int[N]; // 추 무게
			int idx = 0;
			for(String input: br.readLine().split(" ")) WEIGHTS[idx++]=Integer.parseInt(input);
			memoization = new long[(1<<N)][(1<<N)]; // 좌우 상태에 따른 기록
			
			// 출력
			System.out.println("#"+test_case+" "+balance(0, 0, 0, 0));
		}
	}
}