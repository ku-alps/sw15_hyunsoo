import java.util.Scanner;

// 팩토리얼
public class No10872 {
	
	// 팩토리얼 재귀함수
	public static long factorial(long n) {
		// 1이하면 무조건 1을 반납하고, 그 외엔 재귀로 호출
		return n > 1 ? n * No10872.factorial(n-1) : 1;
	}
	
	public static void main(String[] args) {
		// 입력을 받고 바로 출력
		Scanner sc = new Scanner(System.in);
		System.out.println( No10872.factorial(sc.nextInt()) );
	}
}
