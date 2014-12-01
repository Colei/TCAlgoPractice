#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "QuickSums.h"
#define oo 1000000
using namespace std;

int QuickSums::minSums(string numbers, int sum) {
		int V[10][10][101];
		for (int i = 0; i<10; i++)
			for (int j = 0; j<10; j++)
				for (int k = 0; k<101; k++)
					V[i][j][k] = 100000;
		int N = numbers.size();
		for (int q = 0; q<N; q++) {
			for (int i = 0; i<N - q; i++) {
				string st = numbers.substr(i, q + 1);
				if (atoi(st.c_str())<101)
					V[i][i + q][atoi(st.c_str())] = 0;
			}
		}
		for (int l = 1; l<N; l++) {
			for (int i = 0; i<N - l; i++) {
				int j = i + l;
				for (int k = i; k<j; k++)
					for (int q1 = 0; q1<100; q1++)
						for (int q2 = 0; q2 + q1 <= 100; q2++)
							if (V[i][k][q1]<100000 && V[k + 1][j][q2] < 100000)
								V[i][j][q1 + q2] = min(V[i][j][q1 + q2], V[i][k][q1] + V[k + 1][j][q2] + 1);
			}
		}
		if (V[0][N - 1][sum]<100000)
			return V[0][N - 1][sum];
		return -1;
	}