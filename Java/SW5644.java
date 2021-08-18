import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

// 무선 충전
class SW5644 {
	static final int[][] DIR = {{0,0},{0,-1},{1,0},{0,1},{-1,0}}; // 시계방향 회전
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++) {
			List<Integer[]> BC = new ArrayList<>(); // BC 정보
			Queue<Integer> a = new LinkedList<>(), b = new LinkedList<>(); // 사람 이동정보
			
			int M = sc.nextInt(), A = sc.nextInt();
			for(int k=0; k<M; k++) a.add(sc.nextInt());
			for(int k=0; k<M; k++) b.add(sc.nextInt()); // 이동 정보

			for(int k=0; k<A; k++) // BC 정보
				BC.add(new Integer[] {
						sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt() });
			Collections.sort(BC, (front, back) -> { return back[3] - front[3]; }); // 출력이 큰 순으로 정렬

			int sum = 0;
			int[] posA = {1,1}, posB = {10,10}; // 시작지점
			do {
				int sA = -1, sB = -1; // 선택할 장치의 인덱스번호

				// A의 선택
				for(int k=0; k<A; k++) { // 장치들을 훑으면서 선택
					Integer[] d = BC.get(k);
					int disA = Math.abs(posA[0]-d[0]) + Math.abs(posA[1]-d[1]);
					if( disA <= d[2] ) { // 장치 범위 내에 있으면
						sA = k; // A가 선택한 충전단자
						break; // 충전량 순으로 정렬했으므로 종료
					}
				}
				
				// B의 선택
				for(int k=0; k<A; k++) { // 장치들을 훑으면서 선택
					Integer[] d = BC.get(k);
					int disB = Math.abs(posB[0]-d[0]) + Math.abs(posB[1]-d[1]);
					if( disB <= d[2] ) { // 장치 범위 내에 있으면
						sB = k; // B가 선택한 충전단자
						break; // 충전량 순으로 정렬했으므로 종료
					}
				}
				
				// A, B의 선택단자를 비교
				if(sA != -1 && sB != -1) { // 둘다 뭔가를 선택을 했다면
					if(sA == sB) { // 둘이 같은걸 선택했다면..
						for(int k=sA+1; k<A; k++) { // 차선책을 찾아냄
							Integer[] d = BC.get(k);
							// A 차선책 찾기
							int disA = Math.abs(posA[0]-d[0]) + Math.abs(posA[1]-d[1]);
							if( disA <= d[2] ) { // 장치 범위 내에 있으면
								sA = k; // A가 선택한 충전단자
								break; // 충전량 순으로 정렬했으므로 종료
							}
							// B 차선책 찾기
							int disB = Math.abs(posB[0]-d[0]) + Math.abs(posB[1]-d[1]);
							if( disB <= d[2] ) { // 장치 범위 내에 있으면
								sB = k; // B가 선택한 충전단자
								break; // 충전량 순으로 정렬했으므로 종료
							}
						}
					}
					// 차선책이 없으면 반만 사용
					sum += BC.get(sA)[3] + (sA!=sB ? BC.get(sB)[3] : 0);
				}
				else { // 하나라도 선택된게 없으면 확인해서 값을 추가
					sum += (sA>=0 ? BC.get(sA)[3] : 0) + (sB>=0 ? BC.get(sB)[3] : 0);
				}
				
				// 이동
				if( M <= 0 ) break;
				int[] dirA = DIR[a.poll()], dirB = DIR[b.poll()];
				for(int k=0; k<2; k++) posA[k] += dirA[k];
				for(int k=0; k<2; k++) posB[k] += dirB[k]; // 다음 위치로 이동							
				M--;
			} while(true); // 이동횟수를 전부 사용
			
			System.out.println("#"+test_case+" "+sum);
		}
	}
}