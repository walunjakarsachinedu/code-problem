#include<vector>
#include<iostream>
using namespace std;


// 2305. Fair Distribution of Cookies
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
      vector<int> children(k,0);
      return _rec(0, cookies, children);
    }
private:
    int _rec(int i, vector<int>& cookies, vector<int>& children) {
      if(i >= cookies.size()) return max_element(children);
      int min_cookies = 1e6;
      for(int c=0; c<children.size(); c++) {
        children[c] += cookies[i];
        min_cookies = min(_rec(i+1, cookies, children), min_cookies);
        children[c] -= cookies[i];
      }
      return min_cookies;
    }
    int max_element(vector<int>& children) {
      int result = 0;
      for(int child : children) result = max(child, result);
      return result;
    }
};

int main() {
    Solution s;
    vector<int> cookies = {6,1,3,2,2,4,1,2};
    int k = 3;
    cout << s.distributeCookies(cookies, k) << endl;
    return 0;
}