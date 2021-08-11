import java.io.BufferedReader;
import java.io.InputStreamReader;

// 배열 돌리기 3
class No16935 {
	static int N, M, R;
	static String[][] map;
	
	// 상하반전
	static void calc1() {
		for(int y=0; y<M; y++) {
			for(int x=0; x<N/2; x++) {
				String swap = map[x][y];
				map[x][y] = map[N-x-1][y];
				map[N-x-1][y] = swap;
			}
		}
	}
	// 좌우반전
	static void calc2() {
		for(int x=0; x<N; x++) {
			for(int y=0; y<M/2; y++) {
				String swap = map[x][y];
				map[x][y] = map[x][M-y-1];
				map[x][M-y-1] = swap;
			}
		}		
	}
	// 우측 90도
	static void calc3() {
		String[][] newArr = new String[M][N];
		for(int x=0; x<N; x++) {
			for(int y=0; y<M; y++) {
				newArr[y][N-x-1] = map[x][y];
			}
		}
		map = newArr;
		int temp = M;
		M = N;
		N = temp;
	}
	// 좌측 90도
	static void calc4() {
		String[][] newArr = new String[M][N];
		for(int x=0; x<N; x++) {
			for(int y=0; y<M; y++) {
				newArr[M-y-1][x] = map[x][y]; 
			}
		}
		map = newArr;
		int temp = M;
		M = N;
		N = temp;
	}
	// 4등분해서 시계방향
	static void calc5() {
		String[][] newArr = new String[N][M];
		for(int x=0; x<N/2; x++) for(int y=0; y<M/2; y++) newArr[x][y+M/2] = map[x][y];
		for(int x=0; x<N/2; x++) for(int y=M/2; y<M; y++) newArr[x+N/2][y] = map[x][y];
		for(int x=N/2; x<N; x++) for(int y=M/2; y<M; y++) newArr[x][y-M/2] = map[x][y];
		for(int x=N/2; x<N; x++) for(int y=0; y<M/2; y++) newArr[x-N/2][y] = map[x][y];
		map = newArr;
	}
	// 4등분해서 반시계방향
	static void calc6() {
		String[][] newArr = new String[N][M];
		for(int x=0; x<N/2; x++) for(int y=0; y<M/2; y++) newArr[x+N/2][y] = map[x][y];
		for(int x=0; x<N/2; x++) for(int y=M/2; y<M; y++) newArr[x][y-M/2] = map[x][y];
		for(int x=N/2; x<N; x++) for(int y=M/2; y<M; y++) newArr[x-N/2][y] = map[x][y];
		for(int x=N/2; x<N; x++) for(int y=0; y<M/2; y++) newArr[x][y+M/2] = map[x][y];
		map = newArr;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		// 기본 정보 입력
		String[] input = bf.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		R = Integer.parseInt(input[2]);
		
		// 초기 배열 세팅
		map = new String[N][];
		for(int k=0; k<N; k++) map[k] = bf.readLine().split(" ");
		for(String type: bf.readLine().split(" ")) {
		switch(type) { // 입력 명령에 따라서 수행
			case "1":
				calc1();
				break;
			case "2":
				calc2();
				break;
			case "3":
				calc3();
				break;
			case "4":
				calc4();
				break;
			case "5":
				calc5();
				break;
			case "6":
				calc6();
				break;
			}
		}
		for(String[] rows: map) { // 출력
			for(String col: rows) System.out.print(col+" ");
			System.out.println();
		}
	}
}