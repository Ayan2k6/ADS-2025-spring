#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int currentMax = arr[0];
    int finalMax = arr[0];

    for (int i = 1; i < n; i++){
        currentMax = max(arr[i], currentMax + arr[i]);
        finalMax = max(finalMax, currentMax);
    }

    cout << finalMax << endl;

    return 0;
}
