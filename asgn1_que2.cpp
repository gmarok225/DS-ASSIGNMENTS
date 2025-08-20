#include<iostream>
using namespace std;
int main(){
	int arr[100],n;
	cout<<"enter number of elements:";
	cin>>n;
	cout<<"enter "<<n<<" elements:";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;){
			if(arr[i]==arr[j]){
				for(int k=j;k<n-1;k++)
				arr[k]=arr[k+1];
				n--;
			}
			else{
				j++;
			}
		}
	}
	cout<<"array after removing duplicate elements:";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
