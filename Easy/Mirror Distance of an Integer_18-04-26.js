/**
 * @param {number} n
 * @return {number}
 */
var mirrorDistance = function(n) {
    let num=n;
    let reversedNum='';
    while(num>0){
        let i=num%10;
        reversedNum+=i;
        num=Math.floor(num/10);
    }
    
    return Math.abs(n-Number(reversedNum));
};