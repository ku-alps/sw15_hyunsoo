import java.util.Arrays;
import java.util.Scanner;

// 냉장고
class JG1828 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int[][] arr = new int[N][2]; // 약품 정보
		for(int k=0; k<N; k++) { // 입력
			arr[k][0] = sc.nextInt();
			arr[k][1] = sc.nextInt();
		}
		Arrays.sort(arr, (a, b) -> { return a[0]!=b[0] ? a[0]-b[0] : a[1]-b[1]; });
		
		int f=0, b=0, ref=1; // 냉장고는 기본 1대
		while( b<N ) {
			if(arr[f][1] < arr[b][0]) { 
				ref += 1; // 뒤쪽에 등장한 약품이 현재 냉장고 범주를 넘어서면 새 냉장고 추가
				f = b; // 앞쪽으로 땡김				
			}
			b++;
		}
		System.out.println(ref);
	}
}