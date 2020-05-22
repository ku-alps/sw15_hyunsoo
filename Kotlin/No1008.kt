// A/B
// Kotlin 에서 지원하는 입출력 함수 사용
private fun readLn() = readLine()!! // 단일 문자열
private fun readInt() = readLn().toInt() // 단일 숫자
private fun readStrings() = readLn().split(" ") // 문자열 리스트 (공백 기준)
private fun readInts() = readStrings().map { it.toInt() } // 숫자 리스트

fun No1008() {
    var datas = readInts() // 입력 숫자 배열
    print(datas[0].toDouble() / datas[1].toDouble()) // 실수형으로 변환하여 연산
}

fun main() {
    No1008()
}