import java.util.Scanner;

// 스위치 켜고 끄기
public class No1244 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 총 버튼 수 입력받고 초기화
		int btnSize = sc.nextInt();
		int[] state = new int[btnSize + 1];
		state[0] = -1; // 각 스위치 번호는 1부터 시작하므로, 0번은 못쓰는 값		
		for(int k=1; k<state.length; k++) state[k] = sc.nextInt();
		
		// 학생 수만큼 반복
		int students = sc.nextInt();
		for(int k=0; k<students; k++) {
			// true 면 남학생, false 면 여학생
			int btnNum = sc.nextInt(); // 스위치 번호
			if(isBoy) {
				for(int i=1; btnNum*i<=btnSize; i++) {
					// 배수가 되는 모든 버튼들에 대해 처리
					int idx = btnNum*i; // 처리할 인덱스 위치
					state[idx] = (state[idx]+1)%2; // 0->1, 1->0
				}
			}
			else {
				for(int i=0; true; i++) {
					// 왼쪽 오른쪽 대칭좌표
					int lIdx = btnNum -i, rIdx = btnNum +i;

					// 범위값 넘어가면 종료
					if( lIdx < 1 || rIdx > btnSize ) break;
					// 양쪽이 대칭이 아니라면 반복문 종료
					if( state[lIdx] != state[rIdx] ) break;
					
					// 그 외에는 값을 바꾸고 계속 진행
					state[lIdx] = state[rIdx] = (state[rIdx]+1)%2;
				}
			}
		}
		
		// 출력
		for(int k=1; k<=btnSize; k++) {
			System.out.print(state[k] + " ");
			if((k%20) == 0) System.out.println();
		}
	}
}
