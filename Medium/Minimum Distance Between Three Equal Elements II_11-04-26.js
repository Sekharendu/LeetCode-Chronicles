/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDistance = function(nums) {
    //HashMap Creation
    const hashMap=new Map();
    for(let i=0;i<nums.length;i++){
        const arrVal=nums[i];
        if(hashMap.has(arrVal)){
            hashMap.get(arrVal).push(i);
        }else{
            hashMap.set(arrVal,[i]);
        }
    }

    //Finding min Value
    let minVal=200001010;
    for(const [key,val] of hashMap){
        if(val.length>=3){
            for(let it=0;it<=val.length-3;it++){
                const i=val[it];
                const j=val[it+1];
                const k=val[it+2];
                const sum=Math.abs(i-j)+Math.abs(j-k)+Math.abs(k-i);
                minVal=Math.min(minVal,sum);
            }
        }
    }   
    return minVal==200001010?-1:minVal;
};