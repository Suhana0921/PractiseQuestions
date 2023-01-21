#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
typedef long long int lli;
class Solution {
public:
   lli convertToNum(string s,int start, int end){
      lli num = 0;
      for (int i = start; i <= end; i++) {
         num = (num * 10) + (s[i] - '0');
         if (num > 255)
            return 10000;
      }
      return num;
}
string addDots(vector <int> positions){
   string res = "";
   int x = 0;
   int posIndex = 0;
   for (int i = 0; i < positions.size(); i++) {
      int num = positions[i];
      ostringstream str1;
      str1 << num;
      string temp = str1.str();
      res += temp;
      if (i < positions.size() - 1)
         res += ".";
   }
   return res;
}
void solve(string s, vector <string> &result,vector <int> positions, int dotCount = 3, int startIndex = 0){
   if (!dotCount && ((s.size() - 1) - startIndex + 1) >= 1) {
      int temp = convertToNum(s, startIndex, s.size() - 1);
      if (temp >= 0 && temp <= 255) {
         positions.push_back(temp);
         string res = addDots(positions);
         if (res.size() - 3 == s.size()) {
            result.push_back(res);
         }
      }
      return;
   }
   for (int i = startIndex; i < s.size(); i++) {
      int temp = convertToNum(s, startIndex, i);
      if (temp >= 0 && temp <= 255) {
         positions.push_back(temp);
         solve(s, result, positions, dotCount - 1, i + 1);
         positions.pop_back();
      }
   }
}
vector<string> genIp(string s){
   vector<string> result;
   vector<int> position;
   solve(s, result, position);
   return result;
}
vector<string> restoreIpAddresses(string A) {
   return genIp(A);
}};
main(){
   Solution ob;
   print_vector(ob.restoreIpAddresses("25525511135"));
}
