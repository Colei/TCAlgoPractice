#include<iostream>
#include<string>
using namespace std;


int main2() {




	string s = "01234";
	for(int l=1;l<=s.size();l++) {
		for (int i = 0; i <= s.size()-l; i++) {
			int j = i + l;
			cout << s.substr(i, l)<<endl;


			for (int k = i; k <= j; k++) {

			}
		
		
		}
	}
	
	
	cin.get();
	return 0;
}