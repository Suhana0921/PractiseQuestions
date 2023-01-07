#include <iostream>
using namespace std;
class gas {
   public:
      int gas;
      int distance;
};
int findStartIndex(gas stationQueue[], int n) {
   int start_point = 0;
   int end_point = 1;
   int curr_gas = stationQueue [start_point].gas - stationQueue [start_point].distance;
   while (end_point != start_point || curr_gas < 0) {
      while (curr_gas < 0 && start_point != end_point) {
         curr_gas -= stationQueue[start_point].gas - stationQueue [start_point].distance;
         start_point = (start_point + 1) % n;
         if (start_point == 0)
         return -1;
      }
      curr_gas += stationQueue[end_point].gas - stationQueue [end_point].distance;
      end_point = (end_point + 1) % n;
   }
   return start_point;
}
int main() {
   gas gasArray[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
   int n = sizeof(gasArray)/sizeof(gasArray [0]);
   int start = findStartIndex(gasArray, n);
   if(start == -1)
      cout<<"No solution";
   else
      cout<<"Index of first gas station : "<<start;
}
