#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;

template <typename T> //problem 2a
int countNodes(Graph<T> g) {
	int countNod = 0;
	list<T> vertic = g.vertices();
	for (T v : vertic) {
		if (g.countParents(v) > g.neighbours(v).size()) ++countNod;
	}

	return countNod;
}