// A+B - 4
fun No10951() {
    while (true) {
        var str: String? = readLine()
        if (str == null) break; // 빈 문자열을 받았다면 EOF

        // 한 줄을 입력받아 공백으로 쪼갠 후, 각각을 정수로 변환
        var datas = str!!.split(" ").map { it.toInt() }
        println(datas[0] + datas[1])
    }
}

fun main() {
    No10951()
}