#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int a[n]{-1,4,-1,6,-7};
    int maxsum=0,currsum=0,currstart=0;

    int length=1,startidx=0,endix=0;

    for(int i=0;i<n;++i){
        currsum+=a[i];

        if(abs(currsum)>maxsum){
            maxsum=abs(currsum);
            startidx=currstart;
            endix=i;
            length=endix-startidx+1;
        }
        if(abs(currsum+a[i+1<n ? i + 1 : i]) < abs(a[i+1 < n ? i + 1 : i])){
            currsum=0;
            currstart=i+1;
        }
    }

    cout << "Lenght-> " << length << " Full -> "<< startidx << " "<< endix;
    return 0;
}
