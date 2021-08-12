import java.io.BufferedReader;
import java.io.InputStreamReader;

// 규영이와 인영이의 카드게임
class SW6808 {
	static final int N = 18;
	static int win, lose;
	static int[] cards; // 보유한 카드
	static int[] owner; // 각 카드를 가진 주인
	static boolean[] visit; // 사용 여부
	
	static void versus(int gScore, int iScore, int round) { 
		// 규영이 점수, 인영이 점수, 라운드 수(제출할 카드 인덱스)

		if(round > N/2) { // 마지막 라운드까지 다 본 경우
			if( gScore > iScore ) win += 1; // 규영이 승리한 경우 
			else if ( gScore < iScore ) lose += 1; // 인영이 승리한 경우
			return;
		}
		
		for(int i=1; i<=N; i++) {
			// 인영이 가진 카드번호가 아니거나, 사용한 카드면 스킵
			if(owner[i] != 0 || visit[i]) continue;
			visit[i] = true; // 방문 처리
			
			// 승패 비교
			int score = cards[round] + i;
			if (cards[round] > i) versus(gScore+score, iScore, round+1); // 규영 승
			else if(cards[round] < i) versus(gScore, iScore+score, round+1); // 인영 승
			else versus(gScore, iScore, round+1); // 무승부
			
			visit[i] = false;
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			win = lose = 0; // 초기값 세팅
			cards = new int[N/2 + 1];
			owner = new int[N+1];
			visit = new boolean[N+1];

			// 보유한 카드의 주인을 바꿈
			String[] cardsStr = bf.readLine().split(" ");
			for(int k=0; k<cardsStr.length; k++) {
				cards[k + 1] = Integer.parseInt(cardsStr[k]); // 카드 번호
				owner[cards[k+1]] = 1;
			}
			
			versus(0,0,1);
			System.out.println("#"+test_case+" "+win+" "+lose);
		}
	}
}