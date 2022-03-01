#include <iostream>
#include <fstream>
#include<memory.h>
using namespace std;

int main() {
    ifstream ifs("friday.in");
    int n;
    ifs >> n;
    ofstream ofs("friday.out");
    int cur = 4;
    int arr[7];
    memset(arr, 0, 7*sizeof(arr[0]));
    for(int i=0; i<n; i++) {
        for(int j=0; j<12; j++) {
            if(j == 0 || j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10) {
                cur += 31;
            } else if(j == 4 || j == 6 || j == 9 || j == 11) {
                cur += 30;
            } else if(j == 2 && (((1900+i)%4 == 0 && (1900+i)%100 != 0) || (1900+i)%400 == 0)){
                cur += 29;
            }
            arr[cur%7]++;
            cur= cur%7;
        }
    }
    for(int i=0; i<7; i++) {
        ofs << arr[i];
        if(i!=6) ofs << ' ';
    }
    ofs << endl;
}
