#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
vector<int> INPUT,LIST;
vector<bool> checkList;
int NUM[20];
int sum;

void comb(int n, int a)
{
    int i;
    static int c;
    if (n==N) {
		sum = 0;
		for(i=0;i<N;i++)
			sum += NUM[i];
		for(i=0;i<checkList.size();i++){
			if(LIST[i]==sum)
				checkList[i] = true;
		}
        return;
    }
	
    for (i=a+1;i<=INPUT.size();i++) {
        NUM[n] = INPUT[i-1];
        comb(n+1,i);
    }
}

int main()
{
	int i,j;
	int n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> j;
		INPUT.push_back(j);
	}
	int q;
	cin >> q;
	for(i=0;i<q;i++){
		cin >> j;
		LIST.push_back(j);
		checkList.push_back(false);
	}
	
	N = 1;
	for(i=0;i<n;i++){
		comb(0,0);
		N++;
	}
	
	for(i=0;i<checkList.size();i++){
		if(checkList[i])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
    return 0;
}
