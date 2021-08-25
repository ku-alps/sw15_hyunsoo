import java.io.BufferedReader;
import java.io.InputStreamReader;

// 하나로
class SW1251 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine()); // 섬의 개수
			String[] input_x = br.readLine().split(" ");
			String[] input_y = br.readLine().split(" ");

			int[][] islands = new int[N][]; // 섬을 담을 공간
			for(int k=0; k<N; k++) {
				islands[k] = new int[] { // 섬 정보 나열
						Integer.parseInt(input_x[k]), Integer.parseInt(input_y[k])
				};
			}
						
			double E = Double.parseDouble(br.readLine());

			boolean[] v = new boolean[N]; // 섬에 다리가 만들어졌는지 확인
			double[] bridge = new double[N]; // 연결할 때 필요한 부담금
			for(int k=0; k<N; k++) bridge[k] = Double.MAX_VALUE; // 최대치 설정
			
			int island = 0; // 시작하는 섬은 임의 출발지점 결정 및 세팅
			bridge[island] = 0; 
			v[island] = true;
			
			double price = 0.0d; // 총 환경부담금
			for(int k=1; k<N; k++) { // 총 N-1 만큼의 연결시도가 필요
				int next = island; // 다음에 선택할 놈
				double n_bridge = Double.MAX_VALUE;
				for(int i=0; i<N; i++) { // 모든 섬을 돌면서 확인
					if(v[i]) continue; // 이미 방문한 곳이면 무시
					
					double height = islands[island][0]-islands[i][0]; // 세로
					double width = islands[island][1]-islands[i][1]; // 가로					
					bridge[i] = Double.min( // 기존 값 vs 선택한 새 섬에서 연결
							bridge[i], (height*height + width*width)*E );

					if(n_bridge > bridge[i]) { // 여태 등장한 놈 중, 가장 작은걸 선택
						next = i;
						n_bridge = bridge[i];
					}
				}
				island = next; // 다음 섬으로 이동
				price += bridge[island]; // 다리 연결
				v[island] = true; // 해당 지점을 그룹에 포함시킴
			}
			
			System.out.println("#"+test_case+" "+ Math.round(price));
		}
	}
}