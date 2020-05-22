import java.util.*
// 두 수 비교하기

fun No1330() {
    var sc: Scanner = Scanner(System.`in`)

    var A = sc.nextInt()
    var B = sc.nextInt() // 두 수 입력
    var ans = if (A < B) "<"
              else if (A > B) ">"
              else "==" // 조건에 따라 정답 결정
    print(ans) // 출력
}

fun main() {
    No1330()
}