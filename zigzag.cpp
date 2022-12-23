#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   string convert(string s, int numRows);
};
string Solution::convert(string a, int b) {
   if(b == 1)return a;
   string arr[b];
   int row = 0;
   bool down = true;
   for(int i = 0; i < a.size(); i++){
      arr[row].push_back(a[i]);
      if(row == b - 1) down = false;
      else if(row == 0)down = true;
      if(down) row++;
      else row--;
   }
   string ans = "";
   for(int i = 0; i < b; i++){
      ans += arr[i];
   }
   return ans;
}
main(){
   Solution ob;
   cout << ob.convert("IWANTTOLEARNCODE", 3);
}
