import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 사칙연산 유효성 검사
class SW1233 {
	static final int ROOT = 1; // 루트인덱스는 1
	static int NODE;
	static String[] nodes;
	
	static boolean dfs(int idx) { // 깊이우선 탐색
		boolean possible = true;
		if( idx*2 + 1 <= NODE ) {
			// 자식에 대한 입력은 2개의 값을 가지므로, 있다면 양방향을 반드시 다 가지고 있음
			// 자식이 있다면 좌우 조건을 따지고, 사칙연산인지 확인
			possible &= dfs(idx*2) && dfs(idx*2 + 1);
			possible &= "+-*/".contains(nodes[idx]);
		}
		else {
			// 자식이 없으면 얘는 숫자값이 되야함
			// 사칙연산 기호를 갖고있으면 얘는 불가능
			possible &= !"+-*/".contains(nodes[idx]);
		}
		return possible;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		for(int test_case = 1; test_case <= 10; test_case++) {
			NODE = Integer.parseInt(bf.readLine());
			nodes = new String[NODE + 1]; // 완전이진트리로 사용할 배열

			for(int k=0; k<NODE; k++) {
				StringTokenizer st = new StringTokenizer(bf.readLine());
				int idx = Integer.parseInt(st.nextToken()); // 첫 입력은 번호
				nodes[idx] = st.nextToken(); // 다음 입력은 노드 정보
			} 
			// ** 입력 정보가 배열 기준의 완전이진트리를 만들고 있다는 가정하에 만들어진 코드이므로
			// 실제로는 부정확한 코드가 맞음
			System.out.println("#" + test_case + " " + (dfs(ROOT) ? 1 : 0));
		}
	}
}