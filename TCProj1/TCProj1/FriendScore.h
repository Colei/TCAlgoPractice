//FriendScore.h
#include<string>
#include<vector>
using namespace std;

#ifndef __FRIENDSCORE_H_INCLUDED__   // if x.h hasn't been included yet...
#define __FRIENDSCORE_H_INCLUDED__   //   #define this so the compiler knows it has been included

class FriendScore {
public:
	int score(vector<string> network);
};

#endif 