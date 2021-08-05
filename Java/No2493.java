import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

// 탑
class No2493 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cnt = Integer.parseInt(br.readLine());
		int[] height = new int[cnt+1]; // 각 타워 높이

		// 열을 입력받고, 쪼갬
		String[] strs = br.readLine().split(" ");

		// 현재까지 등장한 탑 정보를 넣을 스택
		Stack<Integer> s = new Stack<>();
		for(int k=1; k<=cnt; k++) {
			int num = Integer.parseInt(strs[k-1]);
			height[k] = num;
			while(!s.isEmpty()) { 
				// 스택이 비면, 얘보다 높은놈은 없다 = 못받는다
				int frontIdx = s.peek();
				if( height[frontIdx] >= height[k] ) { // 내 앞쪽이 더 크면
					System.out.print(frontIdx + " "); // 걔가 받음
					break;
				}
				else s.pop(); // 작은 경우, 얘는 나한테 가려서 쓸모가 없음
			}
			if(s.isEmpty()) System.out.print(0 + " "); // 비어있으면 받을 놈이 없음
			s.push(k); // 해당 타워를 넣는다
		}
	}
}