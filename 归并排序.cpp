#include<iostream>
using namespace std;
void emerge(int arr[],int left,int right,int mid) {
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for (int i=0;i<n1;i++) {
        L[i]=arr[left+i];
    }
    for (int j=0;j<n2;j++) {
        R[j]=arr[mid+1+j];
    }

        int i=0, j=0, k=left;
        while(i< n1 && j < n2)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while(i< n1)
            arr[k++] = L[i++];
        while(j < n2)
            arr[k++] = R[j++];


};
void emergeSort(int arr[],int left ,int right) {
    if (left<right) {
        int mid =(right+left)/2;
        emergeSort(arr,left,mid);
        emergeSort(arr,mid+1,right);
        emerge(arr,left,right,mid);

    }

};

int main () {
    int arr[14]{4,2,9,6,23,12,34,0,1,5,7,8,10,11};
    emergeSort(arr,0,13);
    for (int i=0;i<14;i++) {
        cout << arr[i] << " ";
    }

}