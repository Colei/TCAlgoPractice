#include<string>
#include<iostream>
#include<algorithm>
#include "FriendScore.h"
#define oo 1<<31
using namespace std;

int FriendScore::score(vector<string> net) {
	int n = net.size();
	int M[20][20];
	int people[20];
	for (int i = 0; i < n; i++) {
		M[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			M[i][j] = 100000;
			if (net[i][j] == 'Y') M[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) people[i] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!(i==j) && M[i][j] > 0 && M[i][j] <= 2) {
				people[i]++;
			}
		}
	}
	int max2f = 0;
	for (int i = 0; i < n; i++) max2f = max(max2f, people[i]);
	return max2f;
}



