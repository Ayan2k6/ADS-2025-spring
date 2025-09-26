#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    map<int, int> freq;
    for (int num : nums){
        freq[num]++;
    }

    int max = 0;
    for (auto& p : freq){
        if (p.second > max){
            max = p.second;
        }
    }

    vector<int> modes;

    for (auto& p : freq){
        if (p.second == max){
            modes.push_back(p.first);
        }
    }
    sort(modes.rbegin(), modes.rend());

    for (int i = 0; i < modes.size(); i++){
        cout << modes[i] << " ";
    }

    cout << endl;
   
    return 0;
}