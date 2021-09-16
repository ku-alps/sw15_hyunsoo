import java.io.BufferedReader;
import java.io.InputStreamReader;

// 맥주 마시면서 걸어가기
class No9205 {
	static boolean[] visit; // 각 편의점을 방문했는가?
	static boolean[] isConnect; // 연결 여부
	static int[][] store; // 가게 위치 정보
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {

			int N = Integer.parseInt(br.readLine()); // 편의점 수
			visit = new boolean[N+1];			
			isConnect = new boolean[N+1];
			
			// 각 좌표정보 입력
			store = new int[N+1][2]; // 집 + 가게 좌표

			String[] houseInput = br.readLine().split(" "); // 집 입력
			for(int k=0; k<2; k++) store[0][k] = Integer.parseInt(houseInput[k]);
			
			for(int k=1; k<=N; k++) { // 편의점 좌표
				String[] storePos = br.readLine().split(" ");
				int x=Integer.parseInt(storePos[0]);
				int y=Integer.parseInt(storePos[1]);
				store[k] = new int[] {x,y};
			}
			
			String[] rockInput = br.readLine().split(" "); // 페스티벌 좌표
			int[] rockPos = new int[2];
			for(int k=0; k<2; k++) rockPos[k] = Integer.parseInt(rockInput[k]);

			// 탐색 시도
			boolean success = false;
			int pos = 0; // 시작 위치는 집
			for(int k=0; k<=N; k++) { // 총 N번을 도착 시도
				int[] xy = store[pos]; // 현재 위치의 좌표
				visit[pos] = true; // 해당 좌표는 방문했음
				
				int distance = 0; // 페스티벌 위치랑 거리계산
				for(int i=0; i<2; i++) distance += Math.abs(xy[i]-rockPos[i]);
								
				if((distance-1)/50<20) { // 20병 이내로 갈 수 있는 거리면
					success = true;
					break; // 성공
				}
				
				for(int x=1; x<=N; x++) {
					// 해당 놈을 포함했을 때, 다른 편의점에 갈 수 있는가를 계산
					// 이미 방문했거나, 이미 연결된 경우 계산 필요없음 
					if(visit[x] || isConnect[x]) continue;
					
					int canConnect = 0;
					for(int i=0; i<2; i++) canConnect += Math.abs(xy[i]-store[x][i]);
					isConnect[x] = ((canConnect-1)/50 < 20); // 20병으로 갈수있는가?
				}
				
				pos = 0; // 다음 지역을 선택
				for(int x=1; x<=N; x++) {
					if(!isConnect[x] || visit[x]) continue;
					pos=x;
					break;
				}
				if(pos == 0) break; // 더 이상 갈 수 있는 곳이 없음
			}
			// 출력
			if(success) System.out.println("happy");
			else System.out.println("sad");
		}
	}
}