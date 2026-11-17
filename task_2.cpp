#include <iostream>

using namespace std;
int main() {
    //Создаем переменные
    int N = 10;
    int arr[32],size=0,t=0;
    
    //Разлагаем N на 9 и 2 множители чтоб получить минимальный Q
    for(int b=9;b>=2;--b){
        while(N%b==0){
            arr[size++]=b;
            N=N/b;  
        }
    }

    //Сортируем найденные цифры
    for(int i=0;i<size-1;++i){
        for(int j=0;j<size-i-1;++j){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    //Условия на вторую пример резултата
    t==0 && N>0 && N<=109?  cout << "Result = -1" : cout << "Result = ";
    
    for(int i=0;i<size;++i)
        cout << arr[i] << "";

    cout << endl;

    return 0;
}
