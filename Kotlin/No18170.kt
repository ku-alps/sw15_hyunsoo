import java.util.*
// 두 동전 언리미티드

private val SIZE = 20
private val X = "1210"
private val Y = "2101" // 이동 좌표

private var m = Array(SIZE) { Array<Char>(SIZE) { ' ' } } // 지도 배열
private var intArr: List<Int> = listOf() // 가로, 세로

data class TP(val a: Pair<Int,Int>, val b: Pair<Int,Int>, val c:Int) // 튜플 선언

fun CheckOut(a: Pair<Int,Int>): Boolean { // 범위 확인
    return a.first < 0 || a.first >= intArr[0] || a.second < 0 || a.second >= intArr[1]
}

fun No18170() {
    intArr = readLine()!!.split(' ').map { it.toInt() } // 크기 입력

    var pos = arrayListOf<Pair<Int, Int>>() // 동전 위치
    for (k in 0 until intArr[0]) {
        var str: String = readLine()!!
        for (i in 0 until intArr[1]) { // 맵 입력
            m[k][i] = str[i]
            if (m[k][i] == 'o') pos.add(Pair(k, i)) // 시작점 기록
        }
    }

    var ans = -1 // 초기값은 실패 값 (-1)
    val visit = Array(20) { Array(20) { Array(20) { Array(20) { false } } } } // 방문 여부
    val q: Queue<TP> = LinkedList<TP>()
    q.add(TP(pos[0], pos[1], 0)) // 큐에 삽입

    val getNum = { num: Char -> num.toInt() - '1'.toInt() } // 계산 함수 정의 (람다식)

    total@
    while (q.isNotEmpty()) { // 큐 탐색 BFS
        val (a, b, cost) = q.peek() // q.top()
        q.poll() // q.pop()

        for (k in 0 until 4) { // 상하좌우로 이동 시도
            // 두 동전의 새로운 좌표
            var a_nx = a.first + getNum(X[k])
            var a_ny = a.second + getNum(Y[k])
            var b_nx = b.first + getNum(X[k])
            var b_ny = b.second + getNum(Y[k])

            // 위치 확인
            if (CheckOut(Pair(a_nx, a_ny)) or CheckOut(Pair(b_nx, b_ny))) {
                // 동전이 떨어진 경우.
                if (CheckOut(Pair(a_nx, a_ny)) xor CheckOut(Pair(b_nx, b_ny))) {
                    // 하나만 떨어졌는가 확인
                    ans = cost + 1
                    break@total // 완전히 성공 (끝)
                }
                continue // 그 외엔 건너감
            }

            // 이동할 공간이 벽인지 확인
            if (m[a_nx][a_ny] == '#') { // 새 좌표가 벽이면
                a_nx = a.first
                a_ny = a.second // 원상 복구 (이동 불가능)
            }
            if (m[b_nx][b_ny] == '#') {
                b_nx = b.first
                b_ny = b.second // 원상 복구 (이동 불가능)
            }

            if (visit[a_nx][a_ny][b_nx][b_ny]) continue // 이전 좌표와 동일한 조합인가?
            visit[a_nx][a_ny][b_nx][b_ny] = true

            // 두 동전의 좌표가 겹치면, 불가능
            if (a_nx == b_nx && a_ny == b_ny) continue
            q.add(TP(Pair(a_nx, a_ny), Pair(b_nx, b_ny), cost + 1)) // 큐에 삽입
        }
    }
    print(ans) // 정답 출력
}

fun main() {
    No18170()
}