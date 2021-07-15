function solution(s) {
    const change = {
        zero: '0',
        one: '1',
        two: '2',
        three: '3',
        four: '4',
        five: '5',
        six: '6',
        seven: '7',
        eight: '8',
        nine: '9'
    };
    
    const reg = new RegExp(/\d/);

    var answer = '';
    let str = '';
    for(const a of s) {
        if( reg.test(change[str]) ) {
            answer += change[str];
            str = "";
        }
        if( reg.test(a) ) {
            answer += a;
        }
        else {
            str += a;
        }
    }

    if( reg.test(change[str]) ) {
        answer += change[str];
        str = '';
    }
    
    return parseInt(answer);
}