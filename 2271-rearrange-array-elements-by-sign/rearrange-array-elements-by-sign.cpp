class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posarr[n/2];
        int negarr[n/2];

        int k=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
            posarr[k] = nums[i];
            k++;
            }
            else{
                negarr[j] = nums[i];
                j++;
            }
        }

        for(int i=0;i<n/2;i++){
            nums[2*i] = posarr[i];
            nums[2*i+1] = negarr[i];
        }
        return nums;
    }
};