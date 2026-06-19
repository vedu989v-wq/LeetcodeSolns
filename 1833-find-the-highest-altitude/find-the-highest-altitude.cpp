class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int maxi=INT_MIN;
        for(int i=0; i<gain.size(); i++){
            maxi=max(maxi, alt);
            alt=alt+gain[i];
        }
        maxi=max(maxi, alt);
        return maxi;
    }
};