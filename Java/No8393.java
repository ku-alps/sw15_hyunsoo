import java.util.Scanner;

// 합
public class No8393 {
	public static void main(String[] args) {
		// 연속합을 구하는 계산식을 사용
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		System.out.println( (num*(num+1))/2 );
	}
}
