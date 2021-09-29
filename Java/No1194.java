import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 달이 차오른다, 가자.
class No1194 {

	static final int KEY_CNT = 6; // 키는 총 6종류가 존재 (a~f)
	static final int[][] DIR = {{0,-1},{0,1},{-1,0},{1,0}}; // 방향탐색
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Queue<Integer[]> q = new LinkedList<>(); // BFS 탐색 큐

		// 입력
		String[] NM = br.readLine().split(" ");
		int N = Integer.parseInt(NM[0]), M = Integer.parseInt(NM[1]); // 세로, 가로
		
		char[][] map = new char[N][M]; // 지도 입력
		boolean[][][] visit = new boolean[N][M][1<<KEY_CNT]; // 보유한 키 종류에 따라 방문여부를 결정
		for(int x=0; x<N; x++) {
			char[] row = br.readLine().toCharArray(); // 그냥 다 자른다
			for(int y=0; y<M; y++) {
				map[x][y] = row[y]; // 값 입력
				if(map[x][y] == '0') { // 민식이 위치를 찾아서 큐에 삽입
					q.add(new Integer[] {x,y,0,0});
					map[x][y] = '.';
				}
			}
		}
		
		// BFS
		int ans=-1; // 도착하는데 걸리는 시간
		while(!q.isEmpty()) { // 큐 전체를 탐색
			Integer[] pos = q.poll();
			int x=pos[0], y=pos[1], keys=pos[2], move=pos[3];

			if(visit[x][y][keys]) continue; // 이미 방문했던 곳은 무시
			visit[x][y][keys] = true;
			
			if(map[x][y] == '1') { // 도착 지점인 경우
				ans = move;
				break;
			}
			else if(map[x][y] == '#') continue; // 벽인 경우 무시
			else if('A'<=map[x][y] && map[x][y] <='F') { // 문인 경우
				int keyNum = map[x][y]-'A'; // 문이랑 일치하는 열쇠 번호
				if( ((1<<keyNum)&keys) == 0 ) continue; // 열쇠가 없으면 못지나감
			}
			else if('a'<=map[x][y] && map[x][y] <='f') { // 열쇠인 경우
				int keyNum = map[x][y] -'a'; // 열쇠 번호
				keys |= (1<<keyNum); // 열쇠꾸러미에 합침
			}
			
			for(int k=0; k<4; k++) { // 공통으로 4방향 탐색
				int nx=x+DIR[k][0], ny=y+DIR[k][1];
				if(nx<0||nx>=N||ny<0||ny>=M) continue; // 범위 밖
				
				q.add(new Integer[] {nx,ny,keys,move+1}); // 큐 삽입
			}
		}
		System.out.println(ans); // 출력
	}
}