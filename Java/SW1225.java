import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 암호생성기
class SW1225 {
	static Queue<Integer> q = new LinkedList<>();
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
	
		for(int test_case = 1; test_case <= 10; test_case++) {
			sc.nextInt();
			// 8개의 수를 입력받아서 큐에 순서대로 삽입
			for(int k=0; k<8; k++) q.add(sc.nextInt());
			
			int minus = 1; // 이번 시점에 빼야 할 숫자
			int last = 0; // 마지막으로 계산된 값
			do {
				// 계산 결과는 0보다 작아질 수 없다
				last = Math.max(q.poll() - minus, 0);
				q.add(last); // 맨 뒤로 계산결과를 넘김
				minus = (minus % 5) + 1; // 빼야하는 수는 1~5를 반복 
			} while( last != 0 );
			
			// 출력
			System.out.print("#" +  test_case);
			while(!q.isEmpty()) System.out.print(" "+q.poll());
			System.out.println();
		}
	}
}