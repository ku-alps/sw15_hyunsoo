import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

// 암호 만들기
class No1759 {
	static String[] alp; // 문자 종류
	static int L, C; // 암호 길이, 사용가능한 문자 종류

	static void encrypt(int idx, int consonant, int vowel, String crypto) {
		// 살펴볼 문자배열 번호, 자음 수, 모음 수, 만들어진 암호
		if(consonant+vowel >= L) {
			if(consonant < 2 || vowel < 1) return; // 자음 모음수 체크
			System.out.println(crypto); // 만든 암호 출력
			return; // 종료
		}
		
		// 재귀 호출로 순열 생성
		for(int k=idx; k<C; k++) {
			int nConsonant = consonant, nVowel = vowel;
			if( "aeiou".contains(alp[k]) ) nVowel++; // 모음인 경우
			else nConsonant++;
			encrypt(k+1, nConsonant, nVowel, crypto+alp[k]);
		}
	}
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] LC = br.readLine().split(" ");
		L = Integer.parseInt(LC[0]);
		C = Integer.parseInt(LC[1]);

		// 문자 입력
		alp = br.readLine().split(" ");
		Arrays.sort(alp); // 사전 순으로 정렬
		encrypt(0,0,0, "");
	}
}