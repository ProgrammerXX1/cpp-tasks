#include <iostream>

using namespace std;
int main() {
    int k = 4,
        current_sum=0;
        height=0;
    while(current_sum+(height+1)<=k){
        height++;
        current_sum+=height;
    }
    cout << "K = " << height;
    return 0;
}
