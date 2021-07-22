import java.util.Arrays;
import java.util.Scanner;

// 알파벳 찾기
public class No10809 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[] alp = new int[26]; // 26개의 알파벳 종류
		Arrays.fill(alp, -1); // 초기값은 -1으로 설정
		
		String str = sc.next();
		for(int k=0; k<str.length(); k++) {
			// 앞서 등장했었다면 건너뛰고, 처음등장한 경우 해당 인덱스를 기록
			int idx = str.charAt(k) - 'a';
			if( alp[idx] != -1 ) continue;
			alp[idx] = k;
		}
		
		// 결과 출력
		for(int idx: alp) System.out.printf("%d ", idx);
	}
}
