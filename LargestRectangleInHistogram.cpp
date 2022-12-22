#include <bits/stdc++.h>
using namespace std;

class largestRectangleArea {
public:
    int largestAreaInHistogram(vector<int>& histogram) {
        int n = histogram.size(); 
        if(n == 0) return 0;
       
        stack<int> st;
        st.push(-1);
        int maxarea=0;
        
        for(int i=0;i<n;i++){
            while(st.size()!=1 && histogram[st.top()]>=histogram[i]){
                int len = histogram[st.top()];
                st.pop();
                int width = i-st.top()-1;
                maxarea=max(maxarea,len*width);
            }
            st.push(i);
        }
        while(st.size()!=1){
            int in=st.top();
            st.pop();
            int w = n-st.top() -1;
            int h = histogram[in];
            maxarea = max(maxarea,w*h);
        }
        return maxarea;
    }
};

int main()
{
    vector<int>hist{5, 6, 4, 3, 7, 5};
    largestRectangleArea ob;
    cout << "Maximum area is " << ob.largestAreaInHistogram(hist);
    return 0;
}
