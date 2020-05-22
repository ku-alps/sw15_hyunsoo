// 시험 성적
fun No9498() {
    var score = readLine()!!.toInt()
    var ans: Char = // 점수에 따라 결과 결정
        if (score >= 90) 'A'
        else if (score >= 80) 'B'
        else if (score >= 70) 'C'
        else if (score >= 60) 'D'
        else 'F'
    print(ans)
}

fun main() {
    No9498()
}