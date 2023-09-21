#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;
//這題概念拆分，類似DP的解法，把問題最優化子結構，如何得出不product自己的list，最簡單就是將自身左邊的總乘*右邊的總乘，因此我們落後一位就可以得出左邊直到自身之前的總乘，相反右邊則是要領先一位
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(),1);
        vector<int> rightProduct(nums.size(),1);      
        vector<int> answer;
        for (int index=0;index<nums.size()-1;index++){
            leftProduct[index+1]=leftProduct[index]*nums[index];//leftProduct落後nums一位
            rightProduct[rightProduct.size()-1-index-1]= rightProduct[rightProduct.size()-1-index]*nums[nums.size()-1-index];//有點偷懶 ，何在一起做，這邊就是總長度-1在-現在的index在-1(領先一位)                
        }
        for (int index=0;index<leftProduct.size();index++){
            answer.push_back(leftProduct[index]*rightProduct[index]);//推進去就好了
        }
        return answer;
    }

};

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        vector<int> answer(nums.size(),1);
        for (int index=0;index<nums.size()-1;index++){
            answer[index+1]=answer[index]*nums[index];               
        }
        int rightProduct = 1;
        for (int index=answer.size()-1;index>=0;index--){
            answer[index]=rightProduct*answer[index];
            rightProduct =nums[index]*rightProduct;
        }
        return answer;
    }

};

int main(){
    vector<int> rest ={1,2,3,4};
    Solution2 sol;
    sol.productExceptSelf(rest);

}