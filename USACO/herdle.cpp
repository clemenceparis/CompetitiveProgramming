#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    vector<string> answer; vector<string> guess;
    unordered_map<char, int> m1; unordered_map<char, int> m2;
    for(int i=0; i<6; i++) {
        string a; cin >> a;
        if(i<3){
            answer.push_back(a); m1[a[0]]++; m1[a[1]]++; m1[a[2]]++;
        } else {
            guess.push_back(a); m2[a[0]]++; m2[a[1]]++; m2[a[2]]++;
        }
    }
    int yellow = 0, green = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(answer[i][j] == guess[i][j]) {
                green++; m1[answer[i][j]]--; m2[guess[i][j]]--;
            } else if(m1[guess[i][j]] > 0 && m2[guess[i][j]] <= m1[guess[i][j]]) yellow++;
        }
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(m1[answer[i][j]] < m2[answer[i][j]]) {
                yellow += m1[answer[i][j]];
                m1[answer[i][j]] = 0; m2[answer[i][j]] = 0;
            }
        }
    }
    
    cout << green << endl << yellow;
    return 0;
}

