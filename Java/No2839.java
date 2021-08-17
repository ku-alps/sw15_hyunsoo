import java.util.Scanner;

// 설탕 배달
class No2839 {
	static int N;
	static final int SMALL = 3, BIG = 5, MAX = 10000;
	
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		int sum = 0;
		for(int k=0; k<5 && N>=0 ; k++) { 
			// 15부터는 5의 배수로 쪼갤 수 있으므로 3/6/9/12 만 보면 됨
			if( N % BIG == 0 ) {
				// 큰 포대로 가능하다면
				sum += N / BIG;
				N %= BIG;
			}
			else {
				N -= SMALL; // 작은 포대 하나 추가
				sum += 1;
			}
		}
		System.out.println( N != 0 ? -1 : sum ); // 출력
		sc.close();
	}
}