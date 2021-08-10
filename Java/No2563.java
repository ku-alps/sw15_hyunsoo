import java.util.Scanner;

// 색종이
class No2563 {
	static final int WP_SIZE = 100;
	static final int P_SIZE = 10;
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int P = sc.nextInt();
		boolean[][] whitePaper = new boolean[WP_SIZE+1][WP_SIZE+1]; // 흰 도화지

		int area = 0;
		for(int k=0; k<P; k++) {
			int x = sc.nextInt(), y = sc.nextInt(); // 좌표값
			for(int h=0; h<P_SIZE; h++) {
				for(int w=0; w<P_SIZE; w++) {
					if( whitePaper[x+h][y+w] ) continue;
					whitePaper[x+h][y+w] = true;
					area += 1;
				}
			}
		}
		System.out.println(area);
	}
}