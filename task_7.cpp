#include <iostream>

using namespace std;

int main() {
    int n = 27;
    int res =0,pow10=1;
    while(n/pow10>0){
        int current = (n/pow10)%10;
        int left = n/(pow10*10);
        int right=n%pow10;

        if(current>5)
            res+=(left+1)*pow10;
        else if(current==5)
            res+=left*pow10+right+1;
        else
            res += left * pow10;
        pow10*=10;
    }

    cout << "Result : " << res;

    return 0;
}
