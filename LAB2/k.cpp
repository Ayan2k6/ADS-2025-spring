#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> freq(26, 0);
        queue<char> q;
        string result = "";

        for(int i = 0; i < n; i++){
            char ch;
            cin >> ch;

            freq[ch - 'a']++;
            q.push(ch);

            while(!q.empty() && freq[q.front() - 'a'] > 1){
                q.pop();
            }
        
            if(!q.empty()){
                result += q.front();
            } else{
                result += "-1";
            }
            result += " ";
        }

        cout << result << endl;
    }

    return 0;
}