import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

// 암호문1
class SW1228_ver_2 {
	static List<String> list = new LinkedList<>();
	public static void main(String args[]) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		for(int test_case = 1; test_case <= 10; test_case++) {
			list.clear(); // 처음엔 항상 비우고 시작

			int N = Integer.parseInt(bf.readLine()); // 원본 길이
			{
				StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
				for(int k=0; k<N; k++) list.add(st.nextToken()); // 원본 입력
			}
			
			int C = Integer.parseInt(bf.readLine()); // 명령어 갯수
			StringTokenizer st = new StringTokenizer(bf.readLine(), "I");
			for(int k=0; k<C; k++) {
				StringTokenizer sst = new StringTokenizer(st.nextToken());
				int idx = Integer.parseInt(sst.nextToken());
				int cnt = Integer.parseInt(sst.nextToken()); // 삽입 지점, 갯수
				// 리스트에 값을 넣을수록, 인덱스 위치가 뒤로 밀려나감
				for(int i=0; i<cnt; i++) list.add(idx + i, sst.nextToken());
			}
			
			// 출력
			System.out.print("#"+test_case);
			for(int k=0;k< Math.min(10, list.size()); k++) System.out.print(" "+list.get(k));
			System.out.println();
		}
	}
}