#include <iostream>
using namespace std;

class Solution{
    public:
    int getSum(int a[], int n) {
        int answer ;
        int length = *(&a + 1) - a;
        if (n==0)
        {
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            if(i==length){
                break;
            }
            answer+=a[i];
        }
        return answer;
        // Your code goes here
    }   
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.getSum(a, n) << endl;
    }

    return 0;
}