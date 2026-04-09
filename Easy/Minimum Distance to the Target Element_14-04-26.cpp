/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function(nums, target, start) {
    let mini=29090000000;
   for(let i =0 ;i<nums.length; i++){
    if(nums[i]==target){
        mini=Math.min(mini, Math.abs(i-start));
    }
   }
   return mini;
};