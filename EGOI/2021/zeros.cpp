#include<iostream>
using namespace std;

long long a, b;

long long multiplicity(int n) {
    long long expon=n, ans=0;
    while(expon <= b) {
        long long cura = (a%expon == 0 ? a : a+expon-a%expon), curb = b-b%expon;
        if(cura > b || curb < a) break;
        expon*=n; ans++;
    }
    return ans;
}

int main() {
    cin >> a >> b;
    cout << min(multiplicity(2), multiplicity(5));
}

