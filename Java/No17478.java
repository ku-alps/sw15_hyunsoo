import java.util.Scanner;

// 재귀함수가 뭔가요?
public class No17478 {

	static int loop;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		loop = sc.nextInt();

		// 출력 시작
		System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
		recursive(0);
	}

	// 앞쪽 구분자 작성
	static void writeTab (int cnt) {
		for(int k=0; k<cnt; k++) System.out.print("____");
	}
	
	// 재귀 함수
	static void recursive (int cnt) {
		writeTab(cnt);
		System.out.println("\"재귀함수가 뭔가요?\"");

		writeTab(cnt);
		if (cnt < loop) { // 남은 루프가 있는 동안 재귀호출
			System.out.println("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
			writeTab(cnt);
			System.out.println("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
			writeTab(cnt);
			System.out.println("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");

			recursive(cnt + 1);
		}
		else System.out.println("\"재귀함수는 자기 자신을 호출하는 함수라네\"");

		writeTab(cnt);
		System.out.println("라고 답변하였지.");
	}

}
