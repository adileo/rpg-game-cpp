/*
 * Coord.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */

#ifndef COORD_HPP_
#define COORD_HPP_
#include <iostream>
using namespace std;


enum Directions {North,East,West,South};

struct Coord {
	int x;
	int y;
};
//ostream& operator<<( ostream &output, const Coord &C );


#endif /* COORD_HPP_ */
