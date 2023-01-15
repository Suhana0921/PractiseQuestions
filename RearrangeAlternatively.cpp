#include <bits/stdc++.h>
using namespace std;

void rearrangeArrayAlternatively(int a[], int n) {

   int output[n];

   int i = 0, j = n - 1, k = 0;

   while (i <= j) {
      output[k++] = a[j--];
      output[k++] = a[i++];

   }

   for (int i = 0; i < n; i++)
      cout << output[i] << "  ";
}

int main() {
   int a[] = {1, 2, 3, 4, 5, 6};
   int n = sizeof(a) / sizeof(a[0]);

   cout << "Array formed after alternative rearrangement is: " << endl;
   rearrangeArrayAlternatively(a, n);

   return 0;
}
