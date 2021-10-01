import java.util.Scanner;

// 일우는 야바위꾼
class No20361 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt(), X=sc.nextInt(), K=sc.nextInt();

		int snack = X; // 현재 간식위치
		for(int k=0; k<K; k++) {
			int A=sc.nextInt(), B=sc.nextInt();
			if(snack==A) snack=B; // 간식이 들어있는 곳을 섞으려 함
			else if(snack==B) snack=A;
		}
		System.out.println(snack); // 출력
	}
}