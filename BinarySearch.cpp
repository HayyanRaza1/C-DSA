#include<iostream>
using namespace std;


void BinarySearch(int arr[], int size, int target, int high, int low){
    while(low <= high){
        int mid = (high + low)/2;

        if(target == arr[mid]){
            cout<<"Element Found At :"<<mid<<endl;
            return;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
            
    }
    cout<<"Element Not Found "<<endl;
        
}


int main(){
    int arr[7] = {2 , 4, 6, 8, 10, 13, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    BinarySearch(arr , size, target , arr[6] , arr[0]);

    return 0;
}
