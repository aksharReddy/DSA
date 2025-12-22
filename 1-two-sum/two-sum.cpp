class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mpp;

        for(int i=0;i<arr.size();i++){
            int need = target - arr[i];
            if(mpp.find(need)!=mpp.end()){
                return {i,mpp[need]};
            }
            mpp[arr[i]] = i;
        }
        return {-1,-1};
    }
};