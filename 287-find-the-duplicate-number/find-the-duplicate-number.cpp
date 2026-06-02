//approach: floyyd warshall approach/ tortoise, hare method
//[1,3,4,2,2] treat it like
// 0 → 1
// 1 → 3
// 3 → 2
// 2 → 4
// 4 → 2
//where 1 column represents index and second one represent its corresponding value

// 0 → 1 → 3 → 2 → 4
//           ↑     ↓
//           └─────┘

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0];
        int fast=nums[0];
         
         slow=nums[slow];
         fast=nums[nums[fast]];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};