#include<bits/stdc++.h>
using namespace std;
void permutations(string s, string ans){
    if(s.size() == 0) {
        cout << ans << "\n";
        return ;
    }
    for(int i = 0; i < s.size(); i++){
        permutations(s.substr(1), ans + s[0]);
        rotate(s.begin(), s.begin()+1, s.end());
    }
}
int main(){
    string s = "ADT"; // given string
    permutations(s, "");
    return 0;
}
