import java.util.Scanner;

// 달팽이 숫자
class SW1954 {
	
	static int num;
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)	{
			int size = sc.nextInt();
			int[][] map = new int[size][size];
			num = 1;
			
			genSnail(map, 0, 0, size, true);
			System.out.println("#"+ test_case);
			for(int[] row: map) {
				for(int v: row) {
					System.out.print(v + " ");
				}
				System.out.println();
			}
		}
	}
	
	static void genSnail(int[][] map, int x, int y, int len, boolean rightDown) {
		if(len < 1) return;
		if( rightDown ) { // 우->하 방향
			for(int k=0; k<len; k++) { // 오른쪽
				map[x][y++] = num++;
			}
			y--; x++; // 범위 조정
			for(int k=1; k<len; k++) { // 아래쪽
				map[x++][y] = num++;
			}
			x--; y--; // 다음 사이클 준비
		} else { // 좌->상
			for(int k=0; k<len; k++) { // 왼쪽
				map[x][y--] = num++;
			}
			y++; x--; // 범위 조정
			for(int k=1; k<len; k++) { // 위쪽
				map[x--][y] = num++;
			}
			x++; y++; // 다음 사이클 준비 
		}
		genSnail(map, x, y, len-1, !rightDown);
	}
}