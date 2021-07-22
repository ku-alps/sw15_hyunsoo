import java.util.Scanner;

// 최소, 최대
public class No10818 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
		
		// 입력되는 수 갯수 확인
		int loop = sc.nextInt();
		for(int k=0; k<loop; k++) {
			int val = sc.nextInt(); // 값 받아서 비교
			min = Math.min(min, val);
			max = Math.max(max, val);
		}
		System.out.printf("%d %d", min, max);
	}
}
