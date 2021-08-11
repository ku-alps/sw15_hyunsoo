import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

// 배열 돌리기 4
class No17406 {
	static int N, M, R;
	static int[][] flag; // 회전 정보
	static boolean[] visit; // 선택 정보
	
	static int permutation(int[][] arr, int cnt) {
		int ans = Integer.MAX_VALUE;
		if( cnt == R ) { // 모든 경우를 다 선택했다면
			// 회전이 끝난 상태이므로, 각 라인을 더해서 배열의 값을 구함	
			for(int[] intArr: arr) {
				int sum = 0;
				for(int intNum: intArr) sum += intNum;
				ans = Math.min(ans, sum);
			}
		}
		else { // 아직 처리할 회전이 있다면
			for(int k=0; k<R; k++) {
				if(visit[k]) continue;
				visit[k] = true;
				
				// 회전시키기 위한 복제 배열 생성 + 선택한 방식으로 회전
				int[][] copyArr = new int[N][];
				for(int i=0; i<N; i++) copyArr[i] = arr[i].clone();
				
				int x = flag[k][0]-1, y = flag[k][1]-1, len = flag[k][2];
				rotate(copyArr, x-len, x+len+1, y-len, y+len+1); // 회전

				ans = Math.min(ans, permutation(copyArr, cnt+1)); // 재귀		
				visit[k] = false;
			}
		}
		return ans;
	}
	
	static void rotate(int[][] map, int xFrom, int xTo, int yFrom, int yTo) {
		// 홀수크기만큼이라서, 기존 구간으로 조건을 걸면 좌우 이동이 1회 일어나서 값이 문제가 생김
		if( xFrom >= xTo-1 || yFrom >= yTo-1 ) return;
		
		// 가장 처음에 옮길 시작점
		int next = map[xFrom][yFrom];
		
		int x=xFrom, y=yFrom; // 바라볼 x,y 좌표
		for(y++; y< yTo-1; y++) { // 우측방향
			int save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; x<xTo-1 ; x++) { // 아래방향
			int save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; y>yFrom; y--) { // 좌측방향
			int save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		for(; x>xFrom; x--) { // 위쪽방향
			int save = map[x][y]; // 스왑
			map[x][y] = next;
			next = save;
		}
		map[x][y] = next; // 마지막 하나도 바꾸기
		
		// 재귀로 안쪽 테두리에 대해서 반복 (시작점과 끝점이 이동)
		rotate(map, xFrom+1, xTo-1, yFrom+1, yTo-1);		
	};
	
	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] str = bf.readLine().split(" ");
		N = Integer.parseInt(str[0]); // 높이
		M = Integer.parseInt(str[1]); // 너비
		R = Integer.parseInt(str[2]); // 회전 수

		flag = new int[R][3]; // 회전 정보
		visit = new boolean[R]; // 방문 여부
		int[][] map = new int[N][M]; // 값을 기록할 위치
		for(int k=0; k<N; k++) { // 숫자로 변환
			String[] strs = bf.readLine().split(" ");
			for(int i=0; i<strs.length; i++) {
				map[k][i] = Integer.parseInt(strs[i]);
			}
		}
		
		for(int k=0; k<R; k++) { // 회전 정보 입력
			String[] data = bf.readLine().split(" ");
			for(int i=0; i<data.length; i++) flag[k][i] = Integer.parseInt(data[i]);
		}
		
		// R번만큼 반시계로 전체를 회전하면서 최적
		System.out.println(permutation(map, 0));
	}
}