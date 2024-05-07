#include<bits/stdc++.h>
#include "altitude.h"
using namespace std;

string guess_sequence(int N) {
	string s(N, ' ');
	for(int i=1; i<N; i++) {
		bool c = valid_walk(i-1, i);
		if(c) {
			s[i-1]='U'; s[i]='D';
			int st=i-2, en=i+1;
			while(st >= 0 && s[st] != ' ') st--;
			while(st >= 0 && en < N && valid_walk(st, en)) {
				s[st]='U'; s[en]='D';
				en++;
				while(st >= 0 && s[st] != ' ') st--;
			}
			i=en;
		}
	}
	int ttD=0;
	for(int i=0; i<s.size(); i++) if(s[i] == 'D') ttD++;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == ' ' && ttD < N/2) {
			s[i]='D'; ttD++;
		} else if(s[i] == ' ') s[i]='U';
	}
	return s;
    return "";
}