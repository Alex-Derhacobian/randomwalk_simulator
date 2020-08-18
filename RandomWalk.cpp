#include <string>
#include <iostream>
#include "RandomWalk.h"
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;



RandomWalk1D walk(double probleft, double probright,
		int startingPoint, std::vector<int> absorbingBarriers, int numSteps) {
	RandomWalk1D walk1;
	walk1.currentPos = startingPoint;
	walk1.probLeft = probleft;
	walk1.probRight = probright;
	walk1. startPoint = startingPoint;
	walk1.absorbing = absorbingBarriers;
	srand((unsigned) time(NULL));
	for (int i = 0; i<numSteps; i++)  {
		double randSeed = (double) rand()/RAND_MAX;
		if (randSeed <= walk1.probLeft) {
			walk1.currentPos--;
		}
		else {
			walk1.currentPos++;
		}
		if(std::find(walk1.absorbing.begin(), walk1.absorbing.end(), walk1.currentPos)
		!= walk1.absorbing.end()) {
			cout << "absorbed" << endl;
			break;
		}
	}

	return walk1;
}

RandomWalk2D walk2D(pair <int,int> currentPos, pair <int,int> startPoint, double probYpos,
		double probYneg, double probXpos, double probXneg,  std::vector<pair <int,int> > absorbingBarriers,
		int numSteps) {
	RandomWalk2D walk;
	walk.currentPos = currentPos;
	walk.probXneg = probXneg;
	walk.probXpos = probXpos;
	walk.probYneg = probYneg;
	walk.probYpos = probYpos;
	walk.startPoint = startPoint;
	walk.absorbingBar = absorbingBarriers;
	srand((unsigned) time(NULL));
	for (int i = 0; i < numSteps; i++) {
		double randSeedY = (double) rand()/RAND_MAX;
		double randSeedX = (double) rand()/RAND_MAX;
		if (randSeedY <= probYpos) {
			walk.currentPos.second++;
		}
		else {
			walk.currentPos.second--;
		}
		if (randSeedX <= probXpos) {
			walk.currentPos.first++;
		}
		else {
			walk.currentPos.first--;
		}
//		if(std::find(walk.absorbingBar.begin(), walk.absorbingBar.end(), walk.currentPos)
//				!= walk.absorbingBar.end()) {
//					cout << "absorbed" << endl;
//					break;
//				}
		cout << "(" + to_string(walk.currentPos.first) + ","+
				to_string(walk.currentPos.second) + ")"<< endl;

	}
	return walk;
}
