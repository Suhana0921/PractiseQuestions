#include <bits/stdc++.h<
using namespace std;
void print_vector(vector<vector<auto> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
class SummaryRanges {
   public:
   set <int> nums;
   int low, high;
   SummaryRanges() {
      low = INT_MAX;
      high = INT_MIN;
   }
   void addNum(int val) {
      nums.insert(val);
   }
   vector<vector<int>> getIntervals() {
      vector < vector <int> > ret;
      set <int> :: iterator it = nums.begin();
      while(it != nums.end()){
         int x = *it;
         if(ret.empty() || ret.back()[1] + 1 < x){
            ret.push_back({x, x});
         } else {
            ret.back()[1]++;
         }
         it++;
      }
      return ret;
   }
};
main(){
   SummaryRanges ob;
   ob.addNum(1);
   print_vector(ob.getIntervals());
   ob.addNum(3);
   print_vector(ob.getIntervals());
   ob.addNum(8);
   print_vector(ob.getIntervals());
   ob.addNum(2);
   print_vector(ob.getIntervals());
   ob.addNum(7);
   print_vector(ob.getIntervals());
}
