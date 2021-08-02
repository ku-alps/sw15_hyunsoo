import java.util.Scanner;

// 원재의 메모리 복구하기
class SW1289 {
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		sc.nextLine();
        
		for(int test_case = 1; test_case <= T; test_case++)	{
			int cnt = 0;
            boolean type = false; // 초기 메모리 비교값은 0
            String str = sc.nextLine();
           
            for(char ch: str.toCharArray()) {
                if( type ^ ( ch != '0' ) ) { // 마지막으로 등장한 값과 현재 위치의 문자 비교
                    /* 
                    	type = false (0) / ch = '0' --> false
                        type = false (0) / ch = '1' --> true
                        type = true (1) / ch = '0' --> true
                        type = true (1) / ch = '1' --> false
                    */
                    cnt++;
                    type = ( ch != '0' ); // 현재 타입 변경
                }
            }
            System.out.println("#" + test_case + " " + cnt);
		}
	}
}