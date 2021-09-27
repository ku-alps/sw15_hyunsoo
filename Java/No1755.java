import java.util.PriorityQueue;
import java.util.Scanner;

// 숫자놀이
class No1755 {
	static final String[] alp = { // 숫자->문자로 명칭 변경
			"zero","one","two","three","four","five","six","seven","eight","nine"
		};
	
	// 숫자정보 + 알파벳정보
	static class Num implements Comparable<Num> {
		public int num; // 숫자 정보
		public String convert; // 알파벳으로 변환했을 떄

		public Num() {}	
		public Num(int num, String convert) {
			super();
			this.num = num;
			this.convert = convert;
		}

		@Override
		public int compareTo(Num o) {
			// TODO Auto-generated method stub
			return this.convert.compareTo(o.convert); // 사전순으로 나열
		}
	}
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		
		PriorityQueue<Num> pq = new PriorityQueue<>(); // 문자열 사전순 정렬
		for (int k=M; k<=N; k++) { // M~N까지 전부 문자열로 변경하면서 큐에 삽입
			String convert = ""; // 변경시킨 문자열
			int num=k; // 변경할 숫자
			while(num>0) { // 0이 아닐 때까지 진행
				int digit = num%10; // 1의 자릿수를 얻어옴
				num /= 10; // 1의 자릿수를 제거하고, 각 숫자의 자릿수를 낮춤
				convert = alp[digit]+" "+convert; // 변환한 문자를 앞쪽에 연결
			}
			pq.add(new Num(k, convert)); // 바꾼 이름을 우선순위큐에 삽입
		}
		
		int lineCnt = 0; // 출력한 갯수
		while(!pq.isEmpty()) { // 큐에서 전부 꺼내서 출력
			System.out.print(pq.poll().num+" "); // 사전순으로 출력
			lineCnt++; // 출력한 숫자 갯수 증가
			
			// 10개마다 줄바꿈
			if( lineCnt%10 == 0 ) System.out.println();
		}
	}
}