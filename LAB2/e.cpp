#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> names;
    string name;
    cin.ignore();

    for (int i = 0; i < n; i++){
        cin >> name;

        if(names.empty() || name != names.back()){
            names.push_back(name);
        }
    }

    cout << "All in all: " << names.size() << endl;
    cout << "Students:" << endl;

    for (int i = names.size() - 1; i >= 0; i--){
        cout << names[i] << endl;
    }

    return 0;
}