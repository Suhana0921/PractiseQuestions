#include <iostream>
using namespace std;

int *test(int nums[]) {
   static int  r_array[] = { nums[1], nums[2], nums[3], nums[0] };   
    return r_array;
}

int main () {
   int *p;
   int nums[] = {10, 20, 30, 40};	
   
   int arr_length = sizeof(nums) / sizeof(nums[0]);
   cout << "Original array: " << endl;   
   for ( int i = 0; i < arr_length; i++ ) {    
      cout << nums[i] << " ";
   }
   
   p = test(nums);
   cout << "\nRotated array: " << endl;
   for ( int i = 0; i < arr_length; i++ ) {
      cout << *(p + i) << " ";
   }

   return 0;
}
