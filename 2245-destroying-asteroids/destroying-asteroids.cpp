class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long currmass=mass;

        for(int i=0; i<asteroids.size(); i++){
            if(currmass>=asteroids[i]){
                currmass=currmass+asteroids[i];
            }
            else if(currmass<asteroids[i]){
                return false;
            }
        }

        return true;
    }
};