#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n, ind = 0;
    cin >> n;
    vector<int> arr(n);
    vector<int> cnt(n, 0);
    stack<int> sta;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        while(!sta.empty() && arr[i] > arr[sta.top()])
            sta.pop();
        if(!sta.empty()) cnt[sta.top()]++;
        sta.push(i);
    }
    for(int i=1; i<n; i++)
        if(cnt[i] > cnt[ind]) ind = i;
    cout << arr[ind] << endl;
    return 0;
}