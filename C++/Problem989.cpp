#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int size_num = num.size();
        int counter = 1;
        ans.push_back(0);
        while(k != 0) {
            int tempnum;
            if (size_num - counter < 0) {
                tempnum = 0;
            }else {
                tempnum = num[size_num - counter];
            }
            if ((k % 10) + tempnum + ans[0] >= 10) {
                ans[0] = ((k % 10) + tempnum + ans[0]) % 10;
                ans.insert(ans.begin(), 1);
                k = k / 10;
                counter++;
            }else {
                ans[0] = ((k % 10) + tempnum + ans[0]) % 10;
                ans.insert(ans.begin(), 0);
                k = k / 10;
                counter++;
            }
        }
        if (ans[0] == 1 && size_num - counter > -1) {
            ans.erase(ans.begin());
            while(num[size_num - counter] + 1 == 10) {
                if (size_num - counter == 0) {
                    ans.insert(ans.begin(), 0);
                    ans.insert(ans.begin(), 1);
                    counter++;
                    break;
                }
                ans.insert(ans.begin(), 0);
                counter++;
            }
            if (size_num - counter >= 0) {
                ans.insert(ans.begin(), num[size_num - counter] + 1);
                counter++;
            }
            while(size_num - counter >= 0) {
                ans.insert(ans.begin(), num[size_num - counter]);
                counter++; 
            }      
        }else if (ans[0] == 0) {
            ans.erase(ans.begin());
            while(size_num - counter >= 0) {
                printf("%d\n", size_num - counter);
                ans.insert(ans.begin(), num[size_num - counter]);
                counter++; 
            }
        }
        return ans;
    }
};


int main() {

}