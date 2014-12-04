#include<iostream>
#include<string>
#include<algorithm>

#define oo 1 << 31

using namespace std;


class QuickSums2 {
public:

	int getResult(string s, int i) {

		int N = s.size();
		int M[10][10][100];
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 100; k++) {
					M[i][j][k] = 1<<31;
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			M[i][i][atoi(s.substr(i,1).c_str())] = 0;
		}

		for (int l = 1; l <= N; l++) {
			for (int i = 0; i <= N-l; i++) {
				int j = i + l;
				string string_ij = s.substr(i, l);
				int temp = oo;
				for (int k = i; k <= j; k++) {
					for (int p = 0; p <= i; p++) {
						if (M[i][k][p] < oo && M[k+1][j][i-p] < oo) {
							temp = min(temp, M[i][k][p] + M[k + 1][j][i - p]);
						}
					}
				}
			}
		}
		return M[0][N - 1][i];
	}


	int main() {

		string st = "111";
		int total = 3;

		cout<<getResult(st, total);
		cin.get();
		return 9;
	}
};