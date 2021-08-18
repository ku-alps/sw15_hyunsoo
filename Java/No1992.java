import java.io.BufferedReader;
import java.io.InputStreamReader;

// 쿼드트리
class No1992 {
	static int N;
	static char[][] FIELD;
	
	static String divAndConq(int xIdx, int yIdx, int size) { // 분할정복
		int half = size/2;
		// 단칸짜리면 문자열로 바꿔서 바로 반환
		if( half < 1 ) return "" + FIELD[xIdx][yIdx]; 
		// 그룹을 확인하면서 값이 모두 같은지 확인
		char flag = FIELD[xIdx][yIdx];
		for(int x=xIdx; x<xIdx+size; x++) {
			for(int y=yIdx; y<yIdx+size; y++) {
				if( flag != FIELD[x][y] ) {	// 모두 같은값이 아니라면
					// 각각을 4등분하여 재귀로 값을 받아와 합쳐서 반환
					return "("+ divAndConq(xIdx, yIdx, half)+divAndConq(xIdx, yIdx+half, half)
						+divAndConq(xIdx+half, yIdx, half)+divAndConq(xIdx+half, yIdx+half, half)+")";
				}
			}
		}
		return "" + FIELD[xIdx][yIdx]; // 반복문을 제대로 빠져나왔다면 모두 일치
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		// 입력
		FIELD = new char[N][];
		for(int x=0; x<N; x++) FIELD[x] = br.readLine().toCharArray();
		
		// 출력
		System.out.println(divAndConq(0, 0, N));
	}
}