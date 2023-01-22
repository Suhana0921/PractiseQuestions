#include <iostream>
#include <climits>
using namespace std;
int min (int a, int b){
   return (a < b)? a : b;
}
int minPalPartion(string str){
   int n = str.size();
   int cut[n][n];
   bool pal[n][n]; //true when palindrome present for i to j th element
   for (int i=0; i<n; i++){
      pal[i][i] = true; //substring of length 1 is plaindrome
      cut[i][i] = 0;
   }
   for (int len=2; len<=n; len++){
      for (int i=0; i<n-len+1; i++){//find all substrings of length len
      int j = i+len-1; // Set ending index
      if (len == 2) //for two character string
         pal[i][j] = (str[i] == str[j]);
      else //for string of more than two characters
         pal[i][j] = (str[i] == str[j]) && pal[i+1][j-1];
      if (pal[i][j] == true)
         cut[i][j] = 0;
      else{
         cut[i][j] = INT_MAX; //initially set as infinity
         for (int k=i; k<=j-1; k++)
            cut[i][j] = min(cut[i][j], cut[i][k] + cut[k+1][j]+1);
         }
      }
   }
   return cut[0][n-1];
}
int main(){
   string str= "ababbbabbababa";
   cout << "Min cuts for Palindrome Partitioning is: "<<minPalPartion(str);
}
