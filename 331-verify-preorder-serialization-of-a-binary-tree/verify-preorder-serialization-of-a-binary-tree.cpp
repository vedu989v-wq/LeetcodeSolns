class Solution {
public:
// I will be using slot logic in this one, if hashish is found, will decrease the slot, 
bool checker(string a){
    int slots=1;
    for(int i=0; i<a.length(); i++){
        if(a[i] == ',')
        continue;

        slots--;

        if(slots<0)
        return false;

        if(a[i]!='#'){
            while(i < a.size() && a[i] != ',') {
                    i++;
                }

            slots+=2;
        }

        

    }
    return slots==0;

}

    bool isValidSerialization(string preorder) {
        return checker(preorder);
    }
};