// 구구단
fun No2739() {
    var n = readLine()!!.toInt()
    for (k in 1..9) // 반복문 (1~9)
        println("$n * $k = ${n * k}") // 중괄호로 문자열 내에서 연산
}

fun main() {
    No2739()
}