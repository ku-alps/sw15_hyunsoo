import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

// 다리 만들기 2
class No17472 {
	// 이동 방향
	static final int[][] DIR = {{0,1},{1,0},{-1,0},{0,-1}};
	
	static int iNum; // 섬의 갯수
	static int[] islands; // union-find 용
	static int[][] sea; // 맵 전체 입력
	
	// union-find
	static int find(int idx) {
		if( idx == islands[idx] ) return idx;
		return islands[idx] = find(islands[idx]);
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt(), M = sc.nextInt(); // 바다 정보 입력
		sea = new int[N][M];
		for(int x=0; x<N; x++) for(int y=0; y<M; y++) sea[x][y]=sc.nextInt();
		
		PriorityQueue<Integer[]> pq = new PriorityQueue<Integer[]>(
					(Integer[] a, Integer[] b)->a[2]-b[2]
				); // 크루스칼용 우선순위 큐
		Queue<Integer[]> round = new LinkedList<>(); // 섬의 테두리정보
		for(int x=0; x<N; x++) { // 섬을 그룹핑 시도
			for(int y=0; y<M; y++) { // 좌표 하나씩 살펴봄
				// 새로운 섬이 아니거나, 바다인 경우는 무시
				if(sea[x][y] != 1) continue;
				
				iNum++; // 섬 갯수 증가
				
				// 새 섬을 만났으면 BFS 시도
				Queue<Integer[]> q = new LinkedList<>();
				q.add(new Integer[] {x,y}); // 시작좌표
				while(!q.isEmpty()) { // 전체를 탐색
					Integer[] next = q.poll(); // 값 꺼내오기
					// 음수면 이미 섬의 한 부분으로 들어갔다
					if(sea[next[0]][next[1]] < 0) continue;
					sea[next[0]][next[1]] = -iNum; // 섬에 소속시킴
					
					for(int dir=0; dir<4; dir++) {
						// 새로운 좌표
						int nx=next[0]+DIR[dir][0], ny=next[1]+DIR[dir][1];
						if(nx<0||nx>=N||ny<0||ny>=M) continue; // 범위 밖
						if(sea[nx][ny] < 0) continue; // 이미 섬의 일부
						if(sea[nx][ny]==0) { // 해당 위치가 바다인 경우
							if(dir < 2) { // 우측, 하단 방향인 경우만 테두리 탐색용
								round.add(new Integer[] {nx,ny,dir});
							}
							continue; // 계속 진행
						}
						q.add(new Integer[] {nx,ny});
					}
				} // 섬 합치기				
			}
		} // 섬 그룹핑
		
		// 테두리 정보로 주변에 연결 가능한 섬들이랑 거리값 계산
		while(!round.isEmpty()) {
			Integer[] edge = round.poll();
			int length = 1; // 시작 길이는 1
			int px=edge[0], py=edge[1], d=edge[2]; // 값 분리
			int start = sea[px-DIR[d][0]][py-DIR[d][1]]; // 한쪽 섬의 번호

			while(true) {
				px += DIR[d][0];
				py += DIR[d][1]; // 다음 위치로 이동
				if(px>=N || py>=M) break; // 위치를 벗어남
				if(sea[px][py] != 0) { // 바다가 아니면
					if(length > 1) { // 길이가 1보다는 길고
						if(sea[px][py] != start) { // 같은 그룹에 속한게 아니면
							// 엣지로 인지
							pq.add(new Integer[] {-start, -sea[px][py], length});
						}
					}
					break;
				}
				length++; // 길이 증가
			}
		}
		
		islands = new int[iNum+1]; // 섬의 갯수보다 1개 많게
		for(int k=1; k<=iNum; k++) islands[k] = k; // 초기화
		
		int sum = 0; // 전체 연결
		while(!pq.isEmpty()) { // 엣지 연결 시도
			Integer[] edge = pq.poll(); // 엣지 정보
			int a=edge[0], b=edge[1], len=edge[2];

			int rA = find(a), rB = find(b); // 루트정보
			if(rA == rB) continue; // 이미 연결되어있으면 무시
			islands[rA] = rB; // 두 섬을 연결
			sum += len; // 전체 다리 길이 증가
			iNum--; // 섬이 합쳐져서 전체 섬 수는 1개 감소
		}
		
		// 남은 섬이 1개보다 많으면, 전체 연결에 실패했음
		System.out.println(iNum>1 ? -1 : sum);
	}
}