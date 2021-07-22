import java.util.Scanner;

// 별 찍기 - 1
public class No2438 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int loop = sc.nextInt();
		for(int k=1; k<=loop; k++) {
			for(int i=0; i<k; i++) System.out.print("*");
			System.out.println();
		}
	}

}
