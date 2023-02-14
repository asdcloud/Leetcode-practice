#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string rever_a (a.rbegin(), a.rend());
        string rever_b (b.rbegin(), b.rend());
        int a_size = a.length();
        int b_size = b.length();
        string substring;
        string result;
        result.push_back('0');
        int less;
        if (a_size > b_size) {
            less = b_size;
            substring = rever_a.substr(less);
        }else {
            less = a_size;
            substring = rever_b.substr(less);
        }
        for (int fora = 0; fora < less; fora++) {
            if (result[fora] == '0') {
                if (rever_a[fora] == '0' && rever_b[fora] == '0') {
                    result.push_back('0');
                }else if (rever_a[fora] == '1' && rever_b[fora] == '1') {
                    result.push_back('1');
                }else {
                    result[fora] = '1';
                    result.push_back('0');
                }
            }else if (result[fora] == '1') {
                if (rever_a[fora] == '0' && rever_b[fora] == '0') {
                    result.push_back('0');
                }else if (rever_a[fora] == '1' && rever_b[fora] == '1') {
                    result.push_back('1');
                }else {
                    result[fora] = '0';
                    result.push_back('1');
                }
            }
        }
        if (result[less] == '1' && substring.length() > 0) {
            result.pop_back();
            for (int forb = 0; forb < substring.length(); forb++) {
                if (forb == substring.length() - 1 && substring[forb] == '1') {
                    substring[forb] = '0';
                    substring.push_back('1');
                    break;
                }

                if (substring[forb] == '1') {
                    substring[forb] = '0';
                }else if (substring[forb] == '0') {
                    substring[forb] = '1';
                    break;
                }
            }
        }else if (result[less] == '0') {
            result.pop_back();
        }
        result = result + substring;
        string ans (result.rbegin(), result.rend());
        return ans;
    }
};


int main() {



}