// 사분면 고르기
private fun readLn() = readLine()!! // 단일 문자열
private fun readInt() = readLn().toInt() // 단일 숫자
private fun readStrings() = readLn().split(" ") // 문자열 리스트 (공백 기준)
private fun readInts() = readStrings().map { it.toInt() } // 숫자 리스트

fun No14681() {
    var A = readInt()
    var B = readInt()
    var ans: Int =
        if (A > 0) { // x 값이 양수
            if (B > 0) 1
            else 4
        } else { // x 값이 음수
            if (B > 0) 2
            else 3
        }
    print(ans)
}

fun main() {
    No14681()
}