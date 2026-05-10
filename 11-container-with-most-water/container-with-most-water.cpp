class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0, end=height.size()-1;
        int maxi=INT_MIN;

        while(start<end){
            maxi=max(maxi, abs(end-start)*min(height[start], height[end]));
            if(height[start]<height[end]){
                start++;
            }
            else
            end--;
        }

        return maxi;
    }
};