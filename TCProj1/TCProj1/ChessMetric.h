//ChessMetric.h
#include<string>
#include<vector>
using namespace std;

#ifndef __CHESSMETRIC_H_INCLUDED__   // if x.h hasn't been included yet...
#define __CHESSMETRIC_H_INCLUDED__   //   #define this so the compiler knows it has been included

class ChessMetric {
public:
	long long howMany(int size, int start[], int end[], int numMoves);
	bool onTable(pair<int, int> p, int size);
};

#endif 