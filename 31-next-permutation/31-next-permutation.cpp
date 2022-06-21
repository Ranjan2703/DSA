class Solution {
public:
    void nextPermutation(vector<int>& vect) {
        int n = vect.size();
        int leftPeak, rightPeak;
        leftPeak = -1;
        for(int i = n-2; i >= 0; i--){
            if(vect[i] < vect[i+1]){
                leftPeak = i;
                break;
            }
        }
        if(leftPeak == -1){
            reverse(vect.begin(), vect.end());
        }
        else{
            for(int i = n-1; i >= 0; i--){
                if(vect[i] > vect[leftPeak]){
                    rightPeak = i;
                    break;
                }
            }
            swap(vect[leftPeak], vect[rightPeak]);
            sort(vect.begin() + leftPeak + 1, vect.end());   
        }
    }
};
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int start = 0;
        
//         for(int i = n-2;i>=0;i--)
//         {
//              if( nums[i] < nums[i+1])
//                  start = i;
//             break;
//         }
        
//         if(start == -1){
//              reverse(nums.begin(), nums.end());
//         return;
//     }
        
//         else
//         {    
//          int end = 0;
//          for(int i =n-1;i>start ;i--)
//          {
//               if( nums[i]  > nums[start])
//                  //swap(nums[i],nums[start] );
//                   end = i;
//              break;
//          }
//           swap(nums[end],nums[start]);
        
//         reverse(nums.begin()+start+1 , nums.end());}
        
//     }
// };