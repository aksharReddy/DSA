class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k=1;
        string findword = "";
        int maxi = 0;
        while(1){
            findword+=word;
            if(sequence.find(findword)== string::npos){
                break;
            }
             maxi = max(maxi,k);
                  k++;
        }
        return maxi;
    }
};