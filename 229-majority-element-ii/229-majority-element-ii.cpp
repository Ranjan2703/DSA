class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
        int n=nums.size();
        int c1=0;
        int c2=0;
        int el1=-1;
        int el2=-1;
        int i=0;
        while(i<n){
            
            if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
            else if(c1==0){
                el1=nums[i];
                c1=1;
            }
            else if(c2==0){
                el2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
            i++;
        }
        
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
        }
        if(c1>n/3){
            ans.push_back(el1);
        }
        if(c2>n/3){
            ans.push_back(el2);
        }
        
        return ans;
    }
};