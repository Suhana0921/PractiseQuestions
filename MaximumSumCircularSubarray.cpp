#include <bits/stdc++.h>
using namespace std;
int maximum(int arr[], int size){
   int total = 0;
   for (int i = 0; i < size; i++){
      total += arr[i];
   }
   int temp = arr[0];
   int temp_2 = arr[0];
   int temp_3 = arr[0];
   int temp_4 = arr[0];
   for (int i = 1; i < size; i++){
      temp = max(temp + arr[i], arr[i]);
      temp_2 = max(temp_2, temp);
      temp_3 = min(temp_3 + arr[i], arr[i]);
      temp_4 = min(temp_4, temp_3);
   }
   if (size == 1){
      return arr[0];
   }
   if (temp_4 == total){
      return temp_2;
   }
   int max_sum = max(temp_3, total - temp_4);
   return max_sum;
}
int main(){
   int arr[] = { 2, 5, -1, 6, 9, 4, -5 };
   int size = sizeof(arr) / sizeof(arr[0]);
   cout<<"Maximum circular subarray sum is: "<<maximum(arr, size) << endl;
   return 0;
}
