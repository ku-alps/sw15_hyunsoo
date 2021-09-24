import java.io.BufferedReader;
import java.io.InputStreamReader;

// 미세먼지 안녕!
class No17144 {
	// 퍼트릴 방향
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}};
	
	// 공기청정기 바람으로 이동
	static int wind(int[][][] map, int idx, int fX, int fY, int save) {
		int tmp = map[idx][fX][fY];
		map[idx][fX][fY] = save; // 기존 값 덮어쓰기
		return tmp;		
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] RCT = br.readLine().split(" ");
		int R = Integer.parseInt(RCT[0]); // 높이
		int C = Integer.parseInt(RCT[1]); // 너비
		int T = Integer.parseInt(RCT[2]); // 진행시간

		int[][][] map = new int[2][][]; // 전체 맵 상태 (홀수/짝수)
		map[0] = new int[R][C];
				
		int dust_sum=0; // 미세먼지 총량은 고정
		int[] fresh = new int[2]; // 위아래 공기청정기의 높이값
		for(int x=0; x<R; x++) {
			String[] row = br.readLine().split(" "); // 한 줄 입력
			for(int y=0; y<C; y++) {
				// 짝수 상태 맵에 상태를 기록 
				map[0][x][y] = Integer.parseInt(row[y]);
				if(map[0][x][y] == -1) { // 공기청정기 위치
					if(fresh[0] == 0) fresh[0]=x; // 위
					else fresh[1]=x; // 아래
				}
				else if(map[0][x][y] != 0) {
					dust_sum+=map[0][x][y]; // 공기청정기 값 외엔 전부 먼지
				}
			}
		}
		
		// 시뮬레이션
		int oddEven = 0; // 홀수 짝수
		for(int k=0; k<T; k++) {
			// 미세먼지 확산시키기
			int rOddEven = (oddEven+1)%2; // 반대편
			map[rOddEven] = new int[R][C]; // 새로 만들기
			// 공기청정기 설치
			map[rOddEven][fresh[0]][0] = map[rOddEven][fresh[1]][0] = -1; 
			
			// 미세먼지 퍼트리기
			for(int x=0; x<R; x++) {
				for(int y=0; y<C; y++) {
					// 공기청정기거나, 퍼트릴 먼지가 없으면 무시
					if(map[oddEven][x][y] <= 0) continue; 
					
					int center = map[oddEven][x][y]; // 중앙 계산값
					int spread = map[oddEven][x][y]/5; // 한번에 퍼지는 먼지량	
				
					for(int dir=0; dir<4; dir++) { // 4방향 전파
						int nx=x+DIR[dir][0], ny=y+DIR[dir][1]; // 전파위치
						if(nx<0||nx>=R||ny<0||ny>=C) continue; // 범위 확인
						if(map[oddEven][nx][ny] == -1) continue; // 공기청정기 확인
						
						map[rOddEven][nx][ny] += spread; // 해당 방향으로 전파를 시킴
						center -= spread; // 퍼트린 양만큼 중앙에서 빠짐
					}
					map[rOddEven][x][y] += center; // 전부 퍼트리고 남은 값
				}
			}
			
			// 공기청정기 확산
			int fX = fresh[0], fY = 1; // 시작 좌표
			int save = 0; // 이동시킬 먼지량
			// 위쪽 공기청정기
			while(fY<C-1) { // 오른쪽으로 이동				
				save = wind(map, rOddEven, fX, fY, save);
				fY+=1;
			}
			while(fX>0) { // 위로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fX-=1;
			}
			while(fY>0) { // 왼쪽으로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fY-=1;
			}
			while(fX<fresh[0]) { // 아래로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fX+=1;
			}
			dust_sum -= save; // 밀려나는 값은 공기청정기가 없애버림
			
			fX = fresh[1];
			fY = 1;
			save = 0;
			// 아래쪽 공기청정기
			while(fY<C-1) { // 오른쪽으로 이동				
				save = wind(map, rOddEven, fX, fY, save);
				fY+=1;
			}
			while(fX<R-1) { // 아래로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fX+=1;
			}
			while(fY>0) { // 왼쪽으로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fY-=1;
			}
			while(fX>fresh[1]) { // 위로 이동
				save = wind(map, rOddEven, fX, fY, save);
				fX-=1;
			}
			dust_sum -= save; // 밀려나는 값은 공기청정기가 없애버림
			
			oddEven = rOddEven; // 시간이 지나감
		}
		// 출력
		System.out.println(dust_sum);
	}
}