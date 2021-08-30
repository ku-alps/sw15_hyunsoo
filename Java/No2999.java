import java.io.BufferedReader;
import java.io.InputStreamReader;

// 비밀 이메일
class No2999 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int len = str.length(), R = 1, C = 1;
		for(int k=(int)Math.floor(Math.sqrt(len)); k>0; k--) {
			if(len%k == 0) { // 딱 나눠 떨어지는 R,C 조합을 찾기
				R = k;
				C = len/k;
				break;
			}
		}
		
		// 규칙에 따라 출력
		for(int r=0; r<R; r++) {
			for(int c=0; c<C; c++) {
				System.out.print(str.charAt(r+c*R));
			}
		}
	}
}