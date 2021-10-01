import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 낚시왕
class No17143 {
	
	static int[][] DIR = {null,{-1,0},{1,0},{0,1},{0,-1}}; // 상어의 방향
	
	static class Shark { // 상어 클래스
		public int s, d, z; // 속력, 이동방향, 크기
		public Shark(int s, int d, int z) {
			super();
			this.s = s;
			this.d = d;
			this.z = z;
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] RCM = br.readLine().split(" "); // 입력
		int R=Integer.parseInt(RCM[0]); // 세로
		int C=Integer.parseInt(RCM[1]); // 가로
		int M=Integer.parseInt(RCM[2]); // 상어 수
		
		Shark[][][] sea=new Shark[2][R+1][C+1]; // 바다 정보
		
		Queue<Integer[]>[] q = new Queue[2];
		for(int k=0; k<2; k++) q[k] = new LinkedList<Integer[]>(); // 상어 좌표
		
		for(int k=0; k<M; k++) { // 상어 정보
			String[] rcsdz = br.readLine().split(" ");
			int r=Integer.parseInt(rcsdz[0]);
			int c=Integer.parseInt(rcsdz[1]); // 좌표
			int s=Integer.parseInt(rcsdz[2]); // 속력
			int d=Integer.parseInt(rcsdz[3]); // 이동방향
			int z=Integer.parseInt(rcsdz[4]); // 크기
						
			sea[1][r][c] = new Shark(s,d,z); // shark 객체를 만들어서 상어를 위치시킴
			q[1].add(new Integer[] {r,c}); // 상어가 존재하는 좌표 기록
		}
		
		// 낚시왕이 오른쪽으로 한칸씩 이동
		int weight = 0; // 낚은 상어 무게
		for(int y=1; y<=C; y++) {
			int oddEven = y%2; // 홀수,짝수
			for(int x=1; x<=R; x++) { // 밑으로 낚싯대를 굴려서 낚아봄
				if(sea[oddEven][x][y] != null) { // 가장 처음에 걸린 상어를 낚아 올림
					weight += sea[oddEven][x][y].z; // 낚은 상어 무게를 더하고
					sea[oddEven][x][y] = null; // 상어를 제거
					break;
				}
			}
			
			// 남은 상어들을 이동시킴
			sea[1-oddEven] = new Shark[R+1][C+1]; // 새 공간 생성
			while(!q[oddEven].isEmpty()) {
				Integer[] sXY = q[oddEven].poll(); // 상어 좌표 꺼내오기
				int sx=sXY[0], sy=sXY[1];
				Shark shark=sea[oddEven][sx][sy]; // 상어 꺼내오기
				sea[oddEven][sx][sy] = null;
				if(shark == null) continue; // 좌표가 비어있으면 누가 잡아먹었거나, 낚아챈것
				
				int nx=sx+DIR[shark.d][0]*shark.s;
				int ny=sy+DIR[shark.d][1]*shark.s; // 상어의 속력과 방향을 기반으로 새 좌표를 설정
				
				while(nx<1||nx>R) { // 높이값이 꺾인 경우, 방향전환이 필요
					if(nx<1) nx=1+(1+Math.abs(nx)); // 높이값이 위로 넘치는 경우
					else nx=R-(nx-R);
					shark.d = shark.d%2 + 1;
				}
				while(ny<1||ny>C) { // 가로값이 꺾인 경우, 방향전환이 필요
					if(ny<1) ny=1+(1+Math.abs(ny));
					else ny=C-(ny-C);
					shark.d = shark.d%2 + 3;
				}
				// 이동시킬 자리에 다른 상어가 있는지 확인
				Shark other = sea[1-oddEven][nx][ny];
				if(other != null) { // 다른 상어가 있다면
					if(other.z>=shark.z) continue; // 기존에 있던 상어가 더 크면 내가 잡아먹힘
				}
				sea[1-oddEven][nx][ny] = shark; // 상어 위치 이동
				q[1-oddEven].add(new Integer[] {nx,ny}); // 상어 좌표 삽입
			}
		}
		System.out.println(weight); // 출력
	}
}