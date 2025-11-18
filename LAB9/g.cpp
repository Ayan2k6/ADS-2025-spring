#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_fun(const string &s) {
    int n = (int)s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

void problemG(const string &pattern, const vector<string> &arr){
    int maxv = -1;
    vector<int> res;

    for (size_t i = 0; i < arr.size(); ++i){
        string s = arr[i] + "#" + pattern;
        int length_word = (int)arr[i].size();
        int start = length_word + 1;
        int coincidence = 0;
        vector<int> p = prefix_fun(s);
        int last = p.back();
        (void)coincidence; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    if (!(cin >> str)) return 0;

    vector<int> p = prefix_fun(str);
    cout << (int)str.size() - p[str.size() - 1] << "\n";

    return 0;
}