import java.io.BufferedReader;
import java.io.InputStreamReader;

// 벽돌 깨기
class SW5656 {
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}}; // 폭파 방향
	
	static int N,W,H; // 폭발 횟수, 너비, 높이
	
	// 폭파시키기
	static void boom (int[][] map, int x, int y) {
		int num = map[x][y]; // 폭발이 발생하는 횟수
		map[x][y] = 0; // 중심부를 먼저 터트려 무한루프를 방지

		for(int d=0; d<4; d++) { // 해당 좌표를 기준으로 4방향 폭발이 발생
			for(int n=1; n<num; n++) { // 횟수만큼 폭발
				int nx=x+DIR[d][0]*n, ny=y+DIR[d][1]*n; // 폭팔시킬 위치
				if(nx<0||nx>=H||ny<0||ny>=W) continue; // 범주 확인
				
				if(map[nx][ny] < 2) map[nx][ny]=0;
				else boom(map, nx, ny); // 해당 좌표를 터트림
			}
		}
	}
	
	// 정돈하기
	static void trim(int[][] map) {
		for(int y=0; y<W; y++) { // 하나씩 돌리면서 끌어내리기
			int btm, top;
			btm = top = H-1; // 바닥부터 탐색

			while(btm > 0 && top >= 0){
				// 현재 바라보는 바닥이 돌로 채워져있으면 넘어감
				if(map[btm][y] != 0) {
					top--;
					btm--;
				}
				else { // 빈 공간이면, 위쪽을 찾아서 끌어내려야함
					while(top >= 0 && map[top][y] == 0) {
						top--; // 한칸 위로 전진						
					}
					if( top >= 0 ) { // 블록을 찾았다면
						map[btm][y] = map[top][y]; // 끌어내리고
						map[top][y] = 0; // 블록이 있던 공간은 비움
					}
				}
			}
		}
	}
	
	// 구슬 떨구기
	static int drop (int[][] map, int n) { // 지도정보, 폭파시킨 폭탄 수
		int leftover = Integer.MAX_VALUE; // 남은 벽돌 수
		if( n==N ) { // 횟수를 모두 사용
			// 남은 벽돌 수를 직접 계산
			leftover = 0;
			for(int x=0; x<H; x++) {
				for(int y=0; y<W; y++) {
					// 빈 공간은 0, 그 외엔 벽돌 하나
					leftover += map[x][y] != 0 ? 1 : 0;
				}
			}
		}
		else { // 벽돌을 더 떨어뜨려봄
			for(int y=0; y<W; y++) { // 가로에 하나씩 떨어뜨려보기
				int x;
				int[][] nMap = new int[H][]; // 지도 복제
				for(x=0; x<H; x++) nMap[x]=map[x].clone();
				for(x=0; x<H-1 && nMap[x][y] == 0; x++); // 가장 위쪽을 터트려야 함				
				
				boom(nMap, x, y); // 폭파 시켜봄
				trim(nMap); // 끌어내리기				
				leftover = Math.min(leftover, drop(nMap,n+1)); // 재귀로 호출
			}
		}
		return leftover;
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++) {
			String[] NWH = br.readLine().split(" "); // 입력
			N = Integer.parseInt(NWH[0]); // 폭파 횟수
			W = Integer.parseInt(NWH[1]); // 가로
			H = Integer.parseInt(NWH[2]); // 세로
			
			int[][] map = new int[H][W];
			for(int x=0; x<H; x++) { // 맵 전체 읽기
				String[] row = br.readLine().split(" ");
				for(int y=0; y<W; y++) {
					map[x][y] = Integer.parseInt(row[y]);
				}
			}
			int ans = drop(map, 0);
			System.out.println("#"+test_case+" "+ans);
		}
	}
}