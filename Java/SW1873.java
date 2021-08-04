import java.util.Scanner;

// 상호의 배틀필드
class SW1873 {
	static int H, W, posX, posY; // 상하길이, 탱크 위치
	static char [] C_DIR = {'U', 'D', 'L', 'R'}; // 명령어 (방향)
	static char[] T_DIR = {'^', 'v', '<', '>'}; // 탱크가 보는 방향
	static int[][] DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 각 방향별 이동위치
	
	// 탱크 움직이는 함수
	static void moveTank(char[][] map, char dir) {
		for(int k=0; k<C_DIR.length; k++) {
			if(C_DIR[k] == dir) { // 해당 명령어와 일치하면
				// 새로 이동시킬 좌표 확인
				int nx = posX + DIR[k][0], ny = posY + DIR[k][1];
				// 범주를 넘어섰으면 역시 방향전환만 진행
				if( nx < 0 || nx >= H || ny < 0 || ny >= W ) {
					map[posX][posY] = T_DIR[k];
					break;
				}

				if( map[nx][ny] == '.' ) { // 평지일 때만 제대로 이동
					map[posX][posY] = '.'; // 기존 자리는 평지
					map[nx][ny] = T_DIR[k]; // 이동방향을 보도록 삽입
					posX = nx;
					posY = ny; // 포지션 변경
				}
				else map[posX][posY] = T_DIR[k]; // 그 외엔 보는 방향만 바뀜

				break; // 더이상 볼 필요 없음
			}
		}
	}
	// 탱크 쏘는 함수
	static void shootTank(char[][] map) {
		for(int k=0; k<T_DIR.length; k++) {
			if( T_DIR[k] == map[posX][posY] ) { // 바라보는 방향을 우선 찾음
				int nx = posX, ny = posY;
				while( true ) {
					nx += DIR[k][0];
					ny += DIR[k][1]; // 다음 위치로 넘어감
					// 범위를 넘으면 포탄은 사라짐
					if( nx < 0 || nx >= H || ny < 0 || ny >= W ) break;
					// 평지나 물이면 포탄은 지나감
					if(map[nx][ny] == '.' || map[nx][ny] == '-') continue;
					// 벽돌벽이면 부수고 평지로 만듦
					if(map[nx][ny] == '*') map[nx][ny] = '.';
					// 그 외엔 별다른 작용 안함
					break; // 반복문 종료 (포탄 사라짐)
				}
			}
		}
	}
	
	public static void main(String args[]) throws Exception	{		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		
		for(int test_case = 1; test_case <= T; test_case++) {
			// 입력 및 세팅
			H = sc.nextInt();
			W = sc.nextInt(); // 세로, 가로
			char[][] map = new char[H][W];
			for(int row=0; row<H; row++) { // 지도 입력
				String line = sc.next();
				for(int col=0; col<W; col++) {
					map[row][col] = line.charAt(col);
					// 탱크 위치 찾기
					for(char tank: T_DIR) {
						if( map[row][col] == tank ) {
							posX = row;
							posY = col; 
						}
					}
				}
			}

			// 명령처리
			int command_num = sc.nextInt();
			String commands = sc.next();
			for(char command: commands.toCharArray()) {
				// 입력된 순서대로 하나씩 꺼내서 문자 형태로 처리
				switch(command) {
					case 'U':
					case 'D':
					case 'L':
					case 'R':
						moveTank(map, command);
						break;
					case 'S':
						shootTank(map);
						break;
				}			
			}
			// 결과 출력
			System.out.print("#" + test_case + " ");
			for(char[] row: map) {
				for(char box: row) System.out.print(box);
				System.out.println();
			}
		}
	}
}