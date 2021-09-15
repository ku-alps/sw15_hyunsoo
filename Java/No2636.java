import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 치즈 
class No2636 {
	// 이동 방향 정보
	static final int[][] DIR = {{-1,0},{1,0},{0,-1},{0,1}};
	
	static int[][] map; // 맵 정보
	static Queue<Integer[]>[] q = new Queue[2]; // BFS 에 사용할 정보

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		// 높이, 너비
		int H = sc.nextInt(), W = sc.nextInt();
		// 큐  생성
		for(int k=0; k<2; k++) q[k] = new LinkedList<Integer[]>();

		// 전체 상태 입력
		map = new int[H][W];
		for(int x=0; x<H; x++) {
			for(int y=0; y<W; y++) {
				map[x][y] = sc.nextInt();
			}
		}
				
		// 가장 테두리는 무조건 바깥쪽이므로, BFS로 테두리를 찾아서 큐에 삽입
		int hour = -1, cnt = 0; // 현재 경과시간, 다 없어지기 직전의 조각 수
		q[0].offer(new Integer[] {0,0}); // 시작점 삽입

		while(!q[(hour+1)%2].isEmpty()) { // 현재 시간이 비어있지 않으면
			hour++; // 시간이 흐름
			cnt = q[hour%2].size(); // 첫 시행을 제외하고, 해당 시점에는 큐에 치즈만 담겨있음

			while(!q[hour%2].isEmpty()) { // 하나씩 꺼내봄
				Integer[] pos = q[hour%2].poll();
				// 모든 방향 살펴보기
				for(int dir=0; dir<4; dir++) {
					int px = pos[0] + DIR[dir][0];
					int py = pos[1] + DIR[dir][1]; // 좌표값으로 사용
					
					// 범위를 넘거나, 이미 방문했던 곳은 무시
					if( px < 0 || px >= H || py < 0 || py >= W ) continue; // 범위 확인
					if( map[px][py] < 0 ) continue; // 방문 확인

					// 공기(0)이면, 새로 연결된 지점이므로 현재 단계에서 처리하고
					// 치즈(1)라면, 다음 단계에서 없어지므로 넘김
					q[(hour+map[px][py])%2].offer(new Integer[] {px, py}); 
					map[px][py] = -1; // 방문 처리
				}
			}
		}
		System.out.println(hour); // 걸린 시간
		System.out.println(cnt); // 직전에 남아있던 치즈 수
	}
}