
   
#include<iostream>
using namespace std;

string x, y;

int cost(int a, int b) {
    return (x[a] == y[b] ? 0 : 1);
}

int distance(int a, int b) {
    if(a == 0 && b == 0) return cost(a, b);
    else if(a == 0) return distance(a, b-1)+1;
    else if(b == 0) return distance(a-1, b)+1;
    return min(distance(a, b-1)+1, min(distance(a-1, b)+1, distance(a-1, b-1)+cost(a, b)));
}

int main() {
    cin >> x >> y;
    cout << distance(x.length()-1, y.length()-1);
    return 0;
}
