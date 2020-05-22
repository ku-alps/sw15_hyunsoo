// 윤년
fun No2753() {
    var year = readLine()!!.toInt() // 값을 반드시 읽어옴
    var ans: Int = // 4의 배수면서 100의 배수가 아니거나, 400의 배수인 경우
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 1
        else 0
    print(ans)
}

fun main() {
    No2753()
}