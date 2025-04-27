/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const numap={};
    for(let i=0;i<nums.length;++i){
        const complement = target- nums[i];
        if(numap.hasOwnProperty(complement)){
            return [numap[complement],i];
        }
        numap[nums[i]]=i;
    }
};