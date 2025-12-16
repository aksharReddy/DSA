class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posind = 0;
        int negind = 1;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                arr[posind] = nums[i];
                posind+=2;
            }
            else{
                arr[negind] = nums[i];
                negind +=2;
            }
        }
        return arr;
    }
};