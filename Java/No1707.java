import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// 이분 그래프
public class No1707 {	
	public static void main(String[] args) throws IOException {
		// 입력 도구
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine()); // 전체 테스트 케이스 횟수
		
		while(T-- > 0) { // 테스트 케이스 만큼
			String[] VE = br.readLine().split(" "); // V, E 입력
			int V = Integer.parseInt(VE[0]);
			int E = Integer.parseInt(VE[1]); // V,E 를 각각 숫자로 변환
			
			List<Integer>[] edges = new List[V+1]; // 엣지 정보를 저장할 리스트배열
			for(int k=1; k<=V; k++) edges[k] = new ArrayList<>(); // 리스트 객체 생성
			
			// 엣지 입력
			for(int k=0; k<E; k++) { // 엣지 수만큼 시도
				String[] nodeNum = br.readLine().split(" "); // 문자열 입력
				int a = Integer.parseInt(nodeNum[0]); // 첫 노드
				int b = Integer.parseInt(nodeNum[1]); // 다음 노드
				edges[a].add(b); // a는 b로 가는 길이 있음
				edges[b].add(a); // b도 a로 가는 길이 있음
			}
			
			boolean flag = true; // 이분 그래프 여부
			int[] groupNum = new int[V+1]; // 각 노드가 속한 그룹번호 (1 또는 2)
			
			outer:
			for(int k=1; k<=V; k++) { // 모든 노드에 대해서 시도
				if(groupNum[k] != 0) continue; // 이미 어딘가에 소속된 노드

				Queue<Integer[]> q = new LinkedList<>(); // BFS 탐색 시도할 큐
				q.add(new Integer[] {k,1}); // k 노드로 넘어가고, 이놈의 그룹번호는 1
				while(!q.isEmpty()) { // BFS 탐색
					Integer[] node = q.poll(); // 노드를 꺼내옴
					int nNum = node[0]; // 노드 번호
					int gNum = node[1]; // 이놈이 소속될 그룹번호
					
					if(groupNum[nNum] != 0) { // 해당 노드가 이미 그룹소속인 경우
						if(groupNum[nNum]==gNum) { // 예상했던 그룹과 소속이 같으면
							continue; // OK ( 넘어가도 괜찮음 )
						}
						else { // 예상 했던 그룹 소속이 아니면
							flag = false; // 이분 그래프가 아님
							break outer; // 반복문 종료
						}
					}
					// 그 외에는 아직 소속이 아님
					groupNum[nNum] = gNum; // 그룹에 소속시킴
					int nGNum = (gNum%2)+1; // 1~2 사이값을 유지
					for(int next: edges[nNum]) { // 이 노드와 연결된 놈들에 대해서 BFS
						q.add(new Integer[] {next, nGNum}); // BFS 대상으로 사용
					}
				}
			}
			
			System.out.println(flag ? "YES" : "NO"); // 조건에 따라 결과 출력
		}
		
	}

}
