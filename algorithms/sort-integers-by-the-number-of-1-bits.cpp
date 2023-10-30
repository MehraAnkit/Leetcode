class Solution {
    static bool comp(pair<int, int> p1, pair<int, int> p2){
        if(p1.second==p2.second){
            if(p1.first<=p2.first){
                return true;
            }
        }
        if(p1.second<p2.second){
            return true;
        }
        return false;
    }
public:
     void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            int a=__builtin_popcount(nums[i]),b=__builtin_popcount(nums[j]);
            if(a<b){
                temp.push_back(nums[i]);
                i++;
            }else if(a==b){
                if(nums[i]<=nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }else{
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low;k<=high;k++){
            nums[k]=temp[k-low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums,low, mid, high);
    }
    vector<int> sortByBits(vector<int>& arr) {
        mergeSort(arr, 0, arr.size()-1);
        return arr;
    }
};
