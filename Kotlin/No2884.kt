import java.util.*
// 알람 시계
// 값을 입력받아 연산 후 출력

fun No2884() {
    var sc: Scanner = Scanner(System.`in`) // 입력 객체 생성
    var h: Int = sc.nextInt()
    var m: Int = sc.nextInt() // 값을 입력받음

    m += 15
    h = (h + 23 + m / 60) % 24
    m %= 60
    print("$h $m") // 계산 후 출력
}

fun main() {
    No2884()
}