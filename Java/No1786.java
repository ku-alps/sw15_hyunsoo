import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

// 찾기
class No1786 {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] T = br.readLine().toCharArray(); // 타겟
		char[] P = br.readLine().toCharArray(); // 패턴

		int[] kmp = new int[P.length]; // 각 인덱스의 접미사와 일치하는 접두사의 길이 
		for(int k=1, j=0; k<kmp.length; k++) { // KMP 만들기
			while( j>0 && P[k] != P[j] ) j=kmp[j-1]; // 값이 다르면, 더 앞에서 일치하는 위치로 변경
			if(P[k] == P[j]) kmp[k] = ++j; // 일치하는 문자열의 길이를 기록 = 해당 지점까지 일치할 때, 살펴봐야 할 다음 인덱스
		}
		
		// KMP 시도
		List<Integer> list = new LinkedList<>();
		for(int k=0, j=0; k<T.length; k++) {
			// 현재 값이 불일치하면, 내 앞쪽까진 전부 일치한다는 의미
			while( j>0 && T[k] != P[j]) j=kmp[j-1];
			if(T[k]==P[j]) { // 값이 같으면
				if(j+1 == P.length) { // 끝까지 전부 일치
					list.add(k+1-j); // 해당 구간의 시작위치를 저장
					j = kmp[j]; // 살펴볼 구간을 앞으로 당김
				}
				else j++; // 아직 끝까진 도달 못함
			}
		}
		
		// 출력
		StringBuilder sb = new StringBuilder();
		sb.append(list.size());
		sb.append("\n");
		for(Integer idx: list) { // 모든 등장 위치
			sb.append(idx);
			sb.append(" ");
		}
		System.out.println(sb.toString());
	}
}