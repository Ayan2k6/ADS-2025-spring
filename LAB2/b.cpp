#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    string words[n];

    for (int i = 0; i < n; i++){
        cin >> words[i];
    }

    for (int i = k; i < n; i++){
        cout << words[i] << " ";
    }

    for (int i = 0; i < k; i++){
        cout << words[i] << " ";
    }

    cout << endl;

    return 0;
}
