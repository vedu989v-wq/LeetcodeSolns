class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      //optimal (frequency array method)
      int n=A.size();
      vector<int>prefix(n), frequency(n+1, 0);
      int commonCount=0;
      //checking phase, iterating through the elements of both arrays

      for(int i=0; i<n; i++){
        //incrementing frequencies of current elements of A and B, if 2 reaches, we found a common elements

        //checking if the element in A has appeared before(common in prefix);
        if(++frequency[A[i]]==2)
        commonCount++;
        //same process for Array B
        if(++frequency[B[i]]==2)
        commonCount++;

        //storing phase
        prefix[i]=commonCount;
      }

      return prefix;
   }
};