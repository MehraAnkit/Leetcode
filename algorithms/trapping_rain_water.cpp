class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int lmax=0;
        int rmax=0;
        int sol=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=lmax){
                    lmax=height[i];
                }else{
                    sol +=lmax-height[i];
                }
                i++;
            }else{
                if(height[j]>=rmax){
                    rmax=height[j];
                }else{
                    sol +=rmax-height[j];
                }
                j--;
            }
        }
        return sol;
    }
};
