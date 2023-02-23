#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        vector<int>arr(100001);
        int size_nums = nums.size();
        int ans;
        for (int a = 0; a < size_nums; a++) {
            arr[nums[a]]++;
        }
        for (int a = 0; a < 100000; a++) {
            if (arr[a] == 1) {
                ans = a;
            }
        }
        return ans;
    }
};

int main() {

}