#include<iostream>
#include<fstream>
#include <math.h>
using namespace std;

int main() {
    ifstream ifs("cookiesin.txt");
    long d, co, p1, c1, p2, c2;
    ifs >> d >> co >> p1 >> c1 >> p2 >> c2;
    ofstream ofs("cookiesout.txt");
    long long largest = d*co;
    if(p1 < d*co && c1 != 0) {
        long dif = ceil((double)p1 / co);
        long long calculate = (d - dif)*(co + c1) + (dif * co - p1);
        largest = max(largest, calculate);
    }
    if(p2 < d*co && c2 != 0) {
        long dif = ceil((double)p2 / co);
        long long calculate = (d - dif)*(co + c2) + (dif * co - p2);
        largest = max(largest, calculate);
    }
    if(p1 < d*co && c1 != 0) {
        long dif1 = ceil((double)p1 / co);
        long dif2 = ceil((double)(p2 - (dif1*co - p1)) / (co + c1));
        if(d > dif1 +dif2) {
            long long calculate = (d - (dif1 + dif2)) * (co + c1 + c2) + dif2*(co + c1) + dif1 * co - p1 - p2;
            largest = max(largest, calculate);
        }
    }
    if(p2 < d*co && c2 != 0) {
        long dif1 = ceil((double)p2 / co);
        long dif2 = ceil((double)(p1 - (dif1*co - p2)) / (co + c2));
        if(d > dif1 + dif2) {
            long long calculate = (d - (dif1 + dif2)) * (co + c1 + c2) + dif2*(co + c2) + dif1 * co - p1 - p2;
            largest = max(largest, calculate);
        }
    }
    ofs << largest;
    return 0;
}
