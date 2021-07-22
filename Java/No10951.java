import java.util.Scanner;

// A+B - 4
// 파일상에서 마지막값은 '\0' 이므로, hasNext() 로 충분함
public class No10951 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) System.out.println(sc.nextInt() + sc.nextInt());
	}
}
