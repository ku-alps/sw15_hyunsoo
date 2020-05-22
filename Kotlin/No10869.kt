// 사칙연산
private fun readLn() = readLine()!! // 단일 문자열
private fun readInt() = readLn().toInt() // 단일 숫자
private fun readStrings() = readLn().split(" ") // 문자열 리스트 (공백 기준)
private fun readInts() = readStrings().map { it.toInt() } // 숫자 리스트

fun No10869() {
    var datas = readInts() // 숫자 배열
    println(datas[0] + datas[1]) // 덧셈
    println(datas[0] - datas[1]) // 뺄셈
    println(datas[0] * datas[1]) // 곱셈
    println(datas[0] / datas[1]) // 나눗셈
    println(datas[0] % datas[1]) // 나머지
}

fun main() {
    No10869()
}