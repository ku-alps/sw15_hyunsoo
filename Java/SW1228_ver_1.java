import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

// 암호문1
class SW1228 {
	static List<Integer> list = new LinkedList<>();
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++) {
			list.clear(); // 처음엔 항상 비우고 시작

			int N = sc.nextInt(); // 원본 길이
			for(int k=0; k<N; k++) list.add(sc.nextInt()); // 원본 입력
			
			int C = sc.nextInt(); // 명령어 갯수
			for(int k=0; k<C; k++) {
				sc.next(); // 삽입 명령 I 무시
				int idx = sc.nextInt(), cnt = sc.nextInt(); // 삽입 지점, 갯수
				// 리스트에 값을 넣을수록, 인덱스 위치가 뒤로 밀려나감
				for(int i=0; i<cnt; i++) list.add(idx + i, sc.nextInt());
			}
			
			// 출력
			System.out.print("#"+test_case);
			for(int k=0;k< Math.min(10, list.size()); k++) System.out.print(" "+list.get(k));
			System.out.println();
		}
	}
}