/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mymap=new Map();

    for(let i=0; i<nums.length; i++){
        let comp=target-nums[i];
        
        if (mymap.has(comp)){
            let a=[mymap.get(comp), i];
            return a;
        }

        mymap.set(nums[i], i);

    }
};