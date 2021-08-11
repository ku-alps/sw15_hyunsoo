import java.io.BufferedReader;
import java.io.InputStreamReader;

// 배열 돌리기 1
class No16926 {
	static String[][] map; // 공용으로 사용할 맵
	static void rotate(int xFrom, int xTo, int yFrom, int yTo) {
		// 시작점과 끝점이 만나거나 엇갈리면 회전 불가 (종료)
		if( xFrom >= xTo || yFrom >= yTo ) return;
		
		// 가장 처음에 옮길 시작점
		String next = map[xFrom][yFrom];

		int x=xFrom, y=yFrom; // 바라볼 x,y 좌표
		for(x+=1; x<xTo-1 ; x++) { // 아래방향
			String save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; y<yTo-1; y++) { // 우측방향
			String save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; x>xFrom; x--) { // 위쪽방향
			String save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; y>yFrom; y--) { // 좌측방향
			String save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		map[x][y] = next; // 마지막 하나도 바꾸기
		
		// 재귀로 안쪽 테두리에 대해서 반복 (시작점과 끝점이 이동)
		rotate(xFrom+1, xTo-1, yFrom+1, yTo-1);		
	};
	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] str = bf.readLine().split(" ");
		int N = Integer.parseInt(str[0]); // 높이
		int M = Integer.parseInt(str[1]); // 너비
		int R = Integer.parseInt(str[2]); // 회전 수

		map = new String[N][M]; // 값을 기록할 위치
		for(int k=0; k<N; k++) { // 숫자가 아닌 하나의 문자로 받아서 사용
			map[k] = bf.readLine().split(" ");
		}
		// R번만큼 반시계로 전체를 회전
		for(int k=0; k<R; k++) rotate(0, N, 0, M);
		
		// 출력
		for(String[] row: map) {
			for(String col: row) System.out.print(col + " ");
			System.out.println();
		}
	}
}