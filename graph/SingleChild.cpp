#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;

template <typename T> //problem 1a
bool singleChild(Graph<T>& g, const T& a) {
	list<T> vertic = g.vertices();
	for (T v : vertic) {
		if (g.containsEdge(v, a)) {
			if (g.neighbours(v).size() > 1) return false;
		}
	}

	return true;
}