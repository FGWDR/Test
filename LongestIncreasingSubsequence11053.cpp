#include <iostream>
using namespace std;

int arrMax(int *arr,int arrSize);

int main(void){
    int arrLength;
    cin>>arrLength;

    int arr[arrLength];
    int DP_Table[arrLength];
    for(int i=0;i<arrLength;i++){
        cin>>arr[i];
    }

    for(int i=0;i<arrLength;i++){
        DP_Table[i]=1;  //자기 자신으로 LIS를 이루는 경우
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){  //i보다 작은 j에 대해 j번째 수보다 i번째 수가 크다면
                DP_Table[i]=max(DP_Table[i],DP_Table[j]+1);  //(j번째 LIS + 1)과 i번째 LIS의 크기를 비교한 뒤 값을 업데이트
            }
        }
    }

    int answer=arrMax(DP_Table,arrLength);  //DP테이블에서 가장 큰 값==해당 수열의 최장 증가 부수열
    
    cout<<answer<<endl;

    return 0;
}

int arrMax(int *arr,int arrSize){
    int maxNum=arr[0];

    for(int i=1;i<arrSize;i++){
        if(maxNum<=arr[i]){
            maxNum=arr[i];
        }
    }

    return maxNum;
}