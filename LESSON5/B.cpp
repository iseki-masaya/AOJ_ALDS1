#include <iostream>
#define MAX 10e9

using namespace std;

class MergeSort{
public:
	int count;
	
	MergeSort(){count=0;};
	~MergeSort(){};
	
	void merge(int a[],int left,int mid,int right);
	void mergeSort(int a[],int left,int right);
};

void MergeSort::merge(int a[],int left,int mid,int right){
	int i,j,k;
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1],R[n2+1];
	for(i=0;i<n1;++i){
		L[i] = a[left + i];
	}
	for(i=0;i<n2;++i){
		R[i] = a[mid + i];
	}
	i=0;
	j=0;
	L[n1] = MAX;
	R[n2] = MAX;
	
	for(k=left;k<right;++k){
		if(L[i] <= R[j]){
			a[k] = L[i];
			++i;
			++MergeSort::count;
		}
		else {
			a[k] = R[j];
			++j;
			++MergeSort::count;
		}
	}
}

void MergeSort::mergeSort(int a[],int left,int right){
	if(left+1 < right){
		int mid = (1 + left + right)/2;
		mergeSort(a, left, mid);	//分割
		mergeSort(a, mid, right);	//分割
		merge(a, left, mid, right);
	}
}

int main(int argc, const char * argv[])
{
	MergeSort ms;
	
	int n,i;
	cin >> n;
	int a[n];
	for(i=0;i<n;++i){
		cin >> a[i];
	}
	ms.mergeSort(a, 0, n);
	for(i=0;i<n;++i){
		if(i==n-1){
			cout << a[i] << endl;
		}
		else {
			cout << a[i] << " ";
		}
	}
	cout << ms.count << endl;
    return 0;
}

