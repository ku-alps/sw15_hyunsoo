import java.io.BufferedReader;
import java.io.InputStreamReader;

// 알파벳 
class No1987 {
	static int R, C; // 행, 열
	static char[][] FIELD; // 전체 입력
	static final int[][] DIR = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	
	// 움직이기
	static int move(int posX, int posY, int bit) {
		// 현재 말의 위치 + 방문정보
		int cnt = 1; // 방문할 수 있는 최대 갯수
		for(int k=0; k<DIR.length; k++) { // 모든 방향으로 이동 시도
			int nx = posX+DIR[k][0], ny = posY+DIR[k][1];
			// 범위를 넘어서면 무시
			if( nx < 0 || nx >= R || ny < 0 || ny >= C ) continue;

			int alp = FIELD[nx][ny] - 'a'; // 알파벳으로 표현하는 숫자
			if((bit & (1<<alp)) != 0) continue; // 이미 방문했던 알파벳이면 무시
			cnt = Math.max(cnt, move(nx, ny, bit|(1<<alp))+1); // 가장 큰 값을 사용
		}
		return cnt;
	}
	
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 입력
		String[] input = br.readLine().split(" ");
		R = Integer.parseInt(input[0]);
		C = Integer.parseInt(input[1]);
		
		FIELD = new char[R][]; // 전채 지도 입력
		for(int x=0; x<R; x++) FIELD[x] = br.readLine().toCharArray();
		
		int startBit = 1<<(FIELD[0][0]-'a');
		System.out.println(move(0,0,startBit));
	}
}