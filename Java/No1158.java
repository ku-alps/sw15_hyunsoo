import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 요세푸스 문제
class No1158 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), K = sc.nextInt(); // 사람 수, 건너뛸 수
		
		Queue<Integer> q = new LinkedList<>(); // 문제풀이용 큐
		for(int k=1; k<=N; k++) q.offer(k);
		
		StringBuilder sb = new StringBuilder("<"); // 출력 구문
		while(!q.isEmpty()) {
			// 앞쪽을 빼서 뒤로 넘김
			for(int k=1; k<K; k++) q.offer(q.poll());
			sb.append(q.poll());
			sb.append(", ");
		}
		sb.delete(sb.length()-2, sb.length()); // 마지막 ", " 를 삭제
		sb.append(">");
		System.out.println(sb);
	}
}