import java.io.BufferedReader;
import java.io.InputStreamReader;

// 빵집
class No3109 {
	static int R, C, pipe; // 행, 열, 연결된 파이프 수
	static char[][] FIELD; // 전체 맵 정보 + 방문여부
	
	// 그리티 탐색 ( 파이프 연결은 가능한 위쪽부터 차곡차곡 )
	static boolean greedy(int r, int c) {
		// 새로 진입시도 하는 곳이 맵 안쪽인지 확인
		if( r < 0 || r >= R || c < 0 ) return false;
		if( c >= C ) { // 예외로 행의 경우, 끝범주를 넘어갔으면 연결 성공
			pipe++;
			return true; 
		}
		
		// 이동 가능한 곳이 아니라면 실패
		if(FIELD[r][c] != '.') return false; 
		FIELD[r][c] = '#'; // 해당 공간은 사용해서 연결을 시도했음을 표기
		
		if(greedy(r-1, c+1)) return true; // 위쪽 대각선
		if(greedy(r, c+1)) return true; // 직선
		if(greedy(r+1, c+1)) return true; // 아래쪽 대각선
		return false; // 셋 중 하나라도 연결이 안됬다면, 모두 안되는 케이스
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 입력
		String[] RC = br.readLine().split(" ");
		R = Integer.parseInt(RC[0]);
		C = Integer.parseInt(RC[1]);
		FIELD = new char[R][C];
		
		// 지도 만들기
		for(int x=0; x<R; x++) FIELD[x] = br.readLine().toCharArray();
		
		// 빵집 파이프의 모든 지점에서 연결을 시도
		for(int k=0; k<R; k++) greedy(k, 0);
		System.out.println(pipe);
	}
}