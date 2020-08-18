/*
 * RandomWalk.h
 *
 *  Created on: Jun 13, 2020
 *      Author: AlexDerhacobian
 */

#ifndef RANDOMWALK_H_
#define RANDOMWALK_H_

#include <ostream>
#include <string>
#include <vector>
#include <utility>

struct RandomWalk1D {
	int currentPos;
	int startPoint;
	double probRight;
	double probLeft;
	std::vector<int> absorbing;
};

struct RandomWalk2D {
	std::pair <int,int> currentPos;
	std::pair <int,int> startPoint;
	double probYpos;
	double probYneg;
	double probXpos;
	double probXneg;
	std::vector<std::pair <int,int> > absorbingBar;
};


#endif /* RANDOMWALK_H_ */
