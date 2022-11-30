#include <bits/stdc++.h>
#include "print.cpp"
using namespace std;

// 380. Insert Delete GetRandom O(1)
class RandomizedSet {
public:
    vector<int> array;
    unordered_map<int,int> set; // value -> index in array

    bool insert(int val) {
      if(set.find(val) != set.end()) return false;
      set[val] = array.size();
      array.emplace_back(val);
      return true;
    }
    
    bool remove(int val) {
        if(set.find(val) == set.end()) return false;
        array[set[val]] = array.back();
        set[array.back()] = set[val];
        set.erase(val);
        array.pop_back();
        return true;
    }
    
    int getRandom() {
      return array[rand() % array.size()];
    }
};

int main() {
  RandomizedSet s;
  s.insert(10);
  if(s.insert(10)) cout << "successfully inserted element" << endl;
  s.insert(12);
  s.remove(11);

  cout << s.array << endl;
  cout << s.getRandom() << endl;
  return 0;
}