#include <bits/stdc++.h>
using namespace std;


string pangrams(string s) {
    vector<int> hash(26,-1);
    for(int i = 0; i  < 26; i++){
        if(s[i] != ' ') 
        hash[tolower(s[i]) - 'a'] = 1;
    }
    for(int i = 0;i < 26; i++){
        cout<<hash[i]<<" ";
        if(hash[i] == -1);
    }
    return "pangram";
}

int main(){
    string s = "We promptly judged antique ivory buckles for the next prize";
    cout<<pangrams(s);
    return 0;
}