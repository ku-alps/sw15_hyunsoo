import java.io.BufferedReader;
import java.io.InputStreamReader;

// 활주로 건설
class SW4014 {	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine()); // 테스트 케이스

		// 테스트 케이스만큼 반복
		for(int test_case = 1; test_case <= T; test_case++) {
			String[] NX = br.readLine().split(" ");
			int N=Integer.parseInt(NX[0]); // 가로세로
			int X=Integer.parseInt(NX[1]); // 경사로 길이
			
			// 지형 정보 입력
			int[][] map=new int[N][N];
			for(int r=0; r<N; r++) {
				String[] row = br.readLine().split(" "); 
				for(int c=0; c<N; c++) map[r][c]=Integer.parseInt(row[c]);
			}
			
			// 실제로 시뮬레이션
			int cnt = 0; // 설치 가능한 활주로 수
			
			buildRow:
			for(int r=0; r<N; r++) { // 행 단위로 확인
				int conti=1; // 연속된 값이 등장했는가?
				boolean toDown = false; // 위로 올라가는가? 아래로 내려가는가?
				for(int c=1; c<N; c++) {
					int front=map[r][c-1], now=map[r][c]; // 높이 정보

					if(front==now) conti++; // 같은 높이가 연속으로 등장
					else { // 높이가 달라지는 경우
						if(toDown) { // 아래쪽을 아직 확인해야하는 상황이었으면 
							// 얘는 아래쪽 설치는 불가능 (거리가 부족함)
							continue buildRow;
						}
						else { // 아직 조건을 모르는 경우
							if(front+1==now) { // 위로 올라가는 방향
								if(conti < X) continue buildRow; // 경사로를 깔 수 없는 경우
							}
							else if(front==now+1) toDown=true; // 아래로 내려가는 방향
							else continue buildRow; // 높이차가 1이 아닌 경우
							conti = 1; // 높이값이 변했으므로 연속된 값 초기화
						}
					}
					// 아래로 내려가는 상황이었고, 경사로를 깔 충분한 공간이 있다면
					if(toDown && conti==X) {
						toDown = false;
						conti = 0; // 경사로를 깔아버림
					}
				}
				if(toDown) continue; // 아래쪽 경사로를 아직 확인하는 중이었으면, 미완성
				cnt++; // 활주로를 놓을 수 있는 라인 증가
			}
			
			buildColumn:
			for(int c=0; c<N; c++) { // 열 단위로 확인
				int conti=1; // 연속된 값이 등장했는가?
				boolean toDown = false; // 위로 올라가는가? 아래로 내려가는가?
				for(int r=1; r<N; r++) {
					int front=map[r-1][c], now=map[r][c]; // 높이 정보

					if(front==now) conti++; // 같은 높이가 연속으로 등장
					else { // 높이가 달라지는 경우
						if(toDown) { // 아래쪽을 아직 확인해야하는 상황이었으면 
							// 얘는 아래쪽 설치는 불가능 (거리가 부족함)
							continue buildColumn;
						}
						else { // 아직 조건을 모르는 경우
							if(front+1==now) { // 위로 올라가는 방향
								if(conti < X) continue buildColumn; // 경사로를 깔 수 없는 경우
							}
							else if(front==now+1) toDown=true; // 아래로 내려가는 방향
							else continue buildColumn; // 높이차가 1이 아닌 경우
							conti = 1; // 높이값이 변했으므로 연속된 값 초기화
						}
					}
					// 아래로 내려가는 상황이었고, 경사로를 깔 충분한 공간이 있다면
					if(toDown && conti==X) {
						toDown = false;
						conti = 0; // 경사로를 깔아버림
					}
				}
				if(toDown) continue; // 아래쪽 경사로를 아직 확인하는 중이었으면, 미완성
				cnt++; // 활주로를 놓을 수 있는 라인 증가
			}
			System.out.println("#"+test_case+" "+cnt); // 출력
		}
	}
}