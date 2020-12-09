#include <iostream>
# include<vector>
using std::vector;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-09 23:37:00
 * @LastEditTime: 2020-12-09 23:42:00
 * @Description: file content
 */



void printVec(vector<int>& nums){
    for(int i=0; i<nums.size()-1; i++){
        std::cout<< nums[i] <<", ";
    }
    std::cout<<nums[nums.size()-1] <<std::endl;
}