#include <iostream>

using namespace std;

int main() {

    int n = 7;
    int arr[n]{1,2,3,2,3,1,2};


    int freq[106]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    int max_count =0 ;
    int max_num=0;
    for(int i=0;i<106;i++){
        if(freq[i]>max_count || (freq[i]==max_count && i < max_num)){
        max_count = freq[i];
        max_num = i;
    }}

    int idx = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=max_num){
            arr[idx++]=arr[i];
        }
    }

    for(int i=0;i<max_count;i++){
        arr[idx++]=max_num;
    }


    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}
