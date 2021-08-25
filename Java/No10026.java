import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

// 적록색약 
class No10026 {
	static char[][] AREA; // 전체 맵 정보
	static int[][] normal, blind; // 일반 사람, 색약
	static int N, nNum, bNum; // 맵 크기, 각 경우의 그룹 수

	static final int[][] DIR = {{-1,0},{1,0},{0,-1},{0,1}}; // 방향 정보
	
	static void nGroup(int x, int y, char c) { // 일반인의 그룹핑
		// 좌표, 색상
		if(normal[x][y] != 0) return; // 다른 곳에서 방문한 지점 무시
		if(AREA[x][y] != c) return; // 색상이 달라도 무시

		normal[x][y] = nNum; // 그룹 번호를 기록
		for(int[] dir: DIR) { // 주변을 다시 탐색
			int nx = x+dir[0], ny = y+dir[1]; // 다음 좌표
			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue; // 범위 확인
			nGroup(nx, ny, c); // 재귀로 탐색 (BFS)
		}
	}
	static void bGroup(int x, int y, char c) { // 색약의 그룹핑
		// 좌표, 색상
		if(blind[x][y] != 0) return; // 다른 곳에서 방문한 지점 무시
		if(AREA[x][y] != c) { // 색상이 다른경우
			// 둘 중 하나라도 R,G가 아니라면 빠져나옴
			if("RG".indexOf(c) == -1 || "RG".indexOf(AREA[x][y]) == -1) return;
		}

		blind[x][y] = bNum; // 그룹 번호를 기록
		for(int[] dir: DIR) { // 주변을 다시 탐색
			int nx = x+dir[0], ny = y+dir[1]; // 다음 좌표
			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue; // 범위 확인
			bGroup(nx, ny, c); // 재귀로 탐색 (BFS)
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		// 입력
		AREA = new char[N][]; // 구역
		for(int k=0; k<N; k++) AREA[k] = br.readLine().toCharArray();
		
		normal = new int[N][N]; // 일반 사람의 시선
		blind = new int[N][N]; // 적록색약의 시선
		
		// 일반인 기준으로 전체를 그룹핑
		for(int x=0; x<N; x++) {
			for(int y=0; y<N; y++) { // 전체 돌려보면서
				if(normal[x][y] != 0) continue; // 방문했던 곳이면 무시
				nNum++;
				nGroup(x, y, AREA[x][y]);
			}
		}
		// 색약 기준으로 전체를 그룹핑
		for(int x=0; x<N; x++) {
			for(int y=0; y<N; y++) { // 전체 돌려보면서
				if(blind[x][y] != 0) continue; // 방문했던 곳이면 무시
				bNum++;
				bGroup(x, y, AREA[x][y]);
			}
		}
		// 출력
		System.out.println(nNum + " " + bNum);
	}
}