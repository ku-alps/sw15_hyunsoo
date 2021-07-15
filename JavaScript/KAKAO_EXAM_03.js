const O = 'O';
const X = 'X';
function solution(n, k, cmd) {
    let answer = [];
    for ( let k=0;k<n;k++) answer.push(O);

    let last_line = n - 1; // 마지막 라인
    let d_order = []; // 삭제 순서
    let line = k; // 현재 줄 위치
    for (let c of cmd) {
        let [ todo, cnt ] = c.split(' ');
        // console.log(todo, cnt);
        if( ['D','U'].includes(todo) ){
            cnt = parseInt(cnt);
            if( !d_order.length ) {
                line += ( todo === 'D' ? 1 : -1 ) * cnt;
            }
            else {
                while( cnt ) {
                    line += ( todo === 'D' ? 1 : -1 ); // 한칸 이동
                    if ( answer[line] === O ) cnt -= 1;
                }
            }
        }
        else if ( todo === 'C' ) { // 삭제
            d_order.push(line); // 현재 행 삭제
            // console.log(answer[line]);
            answer[line] = 'X';
            if(line === last_line) { // 마지막행인 경우
                while( answer[line] === X ){
                    line -= 1;
                }
                last_line = line;
            }
            else {
                while( answer[line] === X) {
                    line += 1;
                }
            }
        }
        else { // 복구
            let a = d_order.pop();
            answer[a] = O;
            if( last_line < a ) last_line = a; // 더 뒤쪽 줄이 복구되면 수정
        }
        // console.log(line, answer.join(""));
    }
    
    return answer.join("");
}