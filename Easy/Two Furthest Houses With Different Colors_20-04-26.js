/**
 * @param {number[]} colors
 * @return {number}
 */
var maxDistance = function(colors) {
    let maxi=-1;
    for(let i=0; i<colors.length; i++){
        for(let j=colors.length-1; j>=0; j--){
            if(colors[i]!=colors[j])maxi=Math.max(maxi,Math.abs(i-j))
        }
    }
    return maxi;
};