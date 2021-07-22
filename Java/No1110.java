import java.util.Scanner;

// 더하기 사이클
public class No1110 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int count = 0, val = num;

		do {
			int sum = (val/10) + (val%10);
			val = ((val%10)*10) + (sum%10);
			count++;
		} while( num != val );
		
		System.out.println(count);
	}
}
