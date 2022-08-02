#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (r-l)/2 + l;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) {
                r = --mid;
            } else {
                l = ++mid;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int l=0, r=m-1;
        while(l<=r) {
            if(l==r) break;
            int mid = (r-l)/2 + l;
            if(target == matrix[mid][n-1]) return true;
            else if(target < matrix[mid][n-1]) {
                r = --mid;
            } else {
                l = ++mid;
            }
        }
        if(target > matrix[l][n-1])
            ++l;

        if(l < m) {
            return search(matrix[l], target) != -1;
        }
        return false;
    }
};

int main() {
    Solution s;
    bool ispresent = s.searchMatrix({{1,3,5,7},{10,11,16,20},{23,30,34,60}},34);
    cout<<"isPresent: "<<(ispresent ? "true" : "false")<<endl;
    return 0;
}