import java.io.BufferedReader;
import java.io.InputStreamReader;

// 톱니바퀴
class No14891 {
	static final int MAGNET=4, BLADE=8; // 자석 수,톱니 날 갯수
	static int[] top; // 현재 자석의 최상단을 가리키는 인덱스
	static int[][] magnet; // 자석 정보
	
	static void turnMag(int mag, int dir, int prop) {
		// 이번에 회전시킬 자석번호, 회전 방향, 회전을 전파시킬 방향
		int nextMag = mag + prop; // 다음에 전파시킬 마그넷 번호
		if(1<=nextMag&&nextMag<=MAGNET) { // 전파시킬 마그넷이 있는 경우만 추가 비교
			int conn = (top[mag]+BLADE+prop*2)%BLADE ; // 전파시킬 방향과 붙은 날 위치
			int rConn = (top[nextMag]+BLADE-prop*2)%BLADE; // 이와 맞붙은 방향

			// 서로 붙은 자석 종류가 다른 경우만 회전이 전파
			if(magnet[mag][conn] != magnet[nextMag][rConn]) {
				turnMag(nextMag, -dir, prop);
			}
		}
		top[mag]=(top[mag]+BLADE-dir)%BLADE; // 자석 회전시키기
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		top = new int[MAGNET+1]; // 초기에는 첫번째 값이 최상단에 존재
		magnet = new int[MAGNET+1][BLADE]; // 4개의 자석이 8개의 톱니를 가짐
		for(int x=1; x<=MAGNET; x++) { // 톱니정보 입력
			char[] m = br.readLine().toCharArray();
			for(int y=0; y<BLADE; y++) magnet[x][y]=m[y]-'0';
		}
		
		int K = Integer.parseInt(br.readLine()); // 회전 횟수
		for(int k=0; k<K; k++) { // 실제 회전 연산 시도
			String[] turn = br.readLine().split(" "); // 회전 정보
			int mag=Integer.parseInt(turn[0]); // 회전시킬 자석번호
			int dir=Integer.parseInt(turn[1]); // 회전 방향

			int save_top = top[mag]; // 중간 저장용 TOP 정보
			turnMag(mag, dir, -1); // 왼쪽으로 전파하는 경우
			top[mag] = save_top; // 오른쪽 전파를 위해 다시 초기화
			turnMag(mag, dir, +1); // 오른쪽으로 전파하는 경우
		}
		
		// 결과 계산
		int ans = 0;
		for(int k=1; k<=MAGNET; k++) {
			int idx = top[k]; // 각 톱니별 인덱스 정보
			if(magnet[k][idx] > 0) ans |= (1<<k); // S극이면 점수 계산
		}
		ans >>= 1; // idx 를 1부터 사용했기 때문에, 한칸씩 왼쪽으로 올라가 있음
		
		// 출력
		System.out.println(ans);
	}
}