class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        vector<int>posarr(m);
        vector<int>negarr(m);
        int j=0;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                posarr[j] = nums[i];
                j++;
            }
            else{
                negarr[k] = nums[i];
                k++;
            }
        }
        int x=0;
        int y=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i] = posarr[x];
                x++;
            }
            else{
                nums[i] = negarr[y];
                y++;
            }
        }
        return nums;
    }
};