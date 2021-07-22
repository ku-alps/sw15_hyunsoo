import java.util.Scanner;

// 상수
public class No2908 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 두 수 입력
		int a = sc.nextInt(), b = sc.nextInt();
		int sa = 0, sb = 0;

		while( a != 0 ) { // 뒤집힌 a 계산
			sa = (sa*10) + (a%10);
			a /= 10;
		}
		while( b != 0 ) { // 뒤집힌 b 계산
			sb = (sb*10) + (b%10);
			b /= 10;
		}
		System.out.println(Math.max(sa, sb));
	}
}
