#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> k;

    int min_distance = 2e9;
    int result;


    for(int i = 0; i < n; i++){
        int distance = abs(arr[i] - k);
        if (distance < min_distance){
            min_distance = distance;
            result = i;
        }

    }

    cout << result << endl;

    return 0;
}