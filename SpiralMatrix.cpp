#include <iostream>

using namespace std;

int main()
{   int n=4,m=4;
    int arr[m][n]={{1,2,3,8},{4,5,6,2},{7,8,9,5},{0,2,5,8}};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }   
    int rs=0,re=m;
    int cs=0,ce=n;
    while(rs<re && cs<ce){
       // for first column
        for(int i=rs;i<re;i++){
            cout<<arr[i][cs]<<" ";
        }
        cs++;
        // for last row
        for(int i=cs;i<ce;i++){
           
            cout<<arr[re-1][i]<<" ";
        }
        re--;
        //for last column
        for(int i=re-1;i>=rs;i--){
            cout<<arr[i][ce-1]<<" ";
        }
        ce--;
        //for first row
        for(int i=ce-1;i>=cs;i--){
            cout<<arr[rs][i]<<" ";
        }
        rs++;
    
    
    }
    
    
    return 0;
}
