import java.io.BufferedReader;
import java.io.InputStreamReader;

// 회전 초밥(고)
class JG2577 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] NDKC = br.readLine().split(" "); // 공백으로 쪼개서 입력받음
		int N = Integer.parseInt(NDKC[0]); // 접시 수
		int D = Integer.parseInt(NDKC[1]); // 초밥 종류 수
		int K = Integer.parseInt(NDKC[2]); // 연속으로 먹는 접시 수
		int C = Integer.parseInt(NDKC[3]); // 쿠폰 번호
		
		int[] kind = new int[D+1]; // 종류 별로 등장한 초밥 수 카운팅
		int[] sushi = new int[N]; // 접시에 올라간 초밥
		for(int n=0; n<N; n++) sushi[n]=Integer.parseInt(br.readLine()); // 초밥 정보
		
		// 초기 세팅
		int f=0,b=0,cnt=0; // 투포인터 인덱스, 등장한 초밥 종류
		while(b<K) {
			int type = sushi[b++]; // 이번 접시에 담긴 초밥 종류
			if(kind[type]==0) cnt++; // 처음 등장하는거면 종류+1
			kind[type]++; // 0번~D번까지 등장한 번호초밥의 수 체크
		}
		
		// 탐색
		int ans=cnt+(kind[C] == 0 ? 1 : 0); // 정답값
		do {
			// 이번 연산에 빠질 초밥종류와, 새로 들어갈 초밥 종류
			int fType=sushi[f], bType=sushi[b];
			kind[fType]--; // 앞쪽 초밥은 등장 수 -1
			if(kind[fType] == 0) cnt--; // 빼내서 0이 되면 가능한 종류가 줄어듦
			if(kind[bType] == 0) cnt++; // 넣기 전에 0이었으면 새로 등장하는 종류
			kind[bType]++; // 뒤쪽 초밥은 등장 수 +1
			
			// 쿠폰을 포함해서, 먹을 수 있는 초밥 종류를 최대치로 갱신
			ans = Math.max(ans, cnt+(kind[C] == 0 ? 1 : 0));
			
			f += 1;
			b = (b+1)%N; // 앞뒤 포인터 갱신
		} while(f<N); // 모든 접시를 시작점으로 죄다 살펴봄
		System.out.println(ans); // 출력
	}
}