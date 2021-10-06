import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// 스도쿠
class No2239 {
	static int[][] sudoku; // 스도쿠 배열
	static List<Integer[]> empty = new ArrayList<>(); // 빈 칸 좌표
	
	// 주어진 행,열이 소속된 그룹 인덱스 반환
	static int findDiv(int r, int c) {
		return (r/3)*3+c/3;
	}
	
	static boolean bfs(int[][] map, int[] row, int[] col, int[] div, int idx) {
		// 맵 전체 정보, 행,열,그룹 단위로 사용된 숫자 bit 정보, 방문할 빈 칸 정보
		if(idx == empty.size()) { // 모든 빈칸을 다 채웠으면
			sudoku=map; // 얻게 된 맵을 결과값으로 사용
			return true; // 성공
		}
		
		Integer[] pos = empty.get(idx); // 위치 정보
		int r=pos[0], c=pos[1]; // 행,열 정보
		// 행,열,그룹에서 사용된 숫자 정보를 전부 합치기
		int usedNum = row[r] | col[c] | div[findDiv(r, c)]; 
		
		for(int n=1; n<=9; n++) { // 해당 자리에 숫자 1~9까지 전부 대입 시도
			if((usedNum & (1<<n))!=0) continue; // 어딘가에서 사용된 숫자는 무시
					
			// 사용 정보를 복사해서 새로 갱신
			int[][] nMap = new int[9][]; // 맵 전체 복사
			for(int k=0; k<9; k++) nMap[k]=map[k].clone();
			nMap[r][c] = n; // 숫자를 대입
			
			int[] nRow = row.clone();
			nRow[r] |= (1<<n); // 해당 숫자를 사용했음을 표기
			int[] nCol = col.clone();
			nCol[c] |= (1<<n); // 해당 숫자를 사용했음을 표기
			int[] nDiv = div.clone();
			nDiv[findDiv(r, c)] |= (1<<n); // 해당 숫자를 사용했음을 표기
			
			// 재귀 진행, 완성한 스도쿠가 있으면 이를 반환
			if(bfs(nMap, nRow, nCol, nDiv, idx+1)) return true;
		}
		return false; // 그 외엔 전부 실패
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int[][] map = new int[9][9]; // 맵 정보 배열
		int[] row = new int[9]; // 행
		int[] col = new int[9]; // 열
		int[] div = new int[9]; // 9개로 나눈 그룹

		for(int r=0; r<9; r++) { // 정보 입력
			char[] input = br.readLine().toCharArray();
			for(int c=0; c<9; c++) {
				map[r][c]=input[c]-'0';
				// 빈 칸이라면 리스트에 추가
				if(map[r][c] == 0) empty.add(new Integer[] {r,c});
				else { // 숫자가 채워져 있으면, 각 위치별로 사용되었음을 표기
					row[r] |= (1<<map[r][c]); // x번째 행에는 해당 값이 사용됨
					col[c] |= (1<<map[r][c]); // y번째 열에는 해당 값이 사용됨
					div[findDiv(r,c)] |= (1<<map[r][c]); // 해당 그룹에 사용됨
				}
			}
		}
		
		// 재귀 진행
		bfs(map, row, col, div, 0);
		
		// 출력
		for(int r=0; r<9; r++) { // 행 단위
			for(int c=0; c<9; c++) System.out.print(sudoku[r][c]);
			System.out.println(); // 줄바꿈
		}
	}
}