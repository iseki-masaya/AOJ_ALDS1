#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
//	std::ios::sync_with_stdio(false);
//    std::cin.tie(0);
	
	int i;
	int tmp;
	int count = 0;
	int firstNum,secondNum;
	vector<int> firstInput,secondInput;
	
	//データの入力
	cin >> firstNum;
	for(i=0;i<firstNum;++i){
		cin >> tmp;
		firstInput.push_back(tmp);
	}
	cin >> secondNum;
	for(i=0;i<secondNum;++i){
		cin >> tmp;
		secondInput.push_back(tmp);
	}
	
	//重複している部分をまとめる。
	sort(firstInput.begin(),firstInput.end());
	firstInput.erase(unique(firstInput.begin(),firstInput.end()),firstInput.end());
	sort(secondInput.begin(), secondInput.end());
	secondInput.erase(unique(secondInput.begin(), secondInput.end()),secondInput.end());
	
	int a,b,k;
	int h;
	vector<int>::iterator it = secondInput.begin();
	while(it!=secondInput.end()){
		a = 0;
		b = firstNum-1;
		while(a<=b){
			k = (a+b)/2;
			h = firstInput[k];
			if(h==*it){
				++count;
				break;
			}
			else if(h>*it)
				b = k-1;
			else
				a = k+1;
		}
		++it;
	}
	
	cout << count << endl;
    return 0;
}

