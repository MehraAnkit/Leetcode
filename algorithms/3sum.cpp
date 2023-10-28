class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int j,k;
        int n=nums.size();
        //-4,-1,-1,0,1,2
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            int target = -1*nums[i];
            while(j<k){
                if(nums[j]+nums[k]<target){
                    j++;
                }else if(nums[j]+nums[k]>target){
                    k--;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sol.push_back(temp);
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;k--;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return sol;
    }
};
