#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;


template <typename T> //problem 3
bool pathsFromListExist(Graph<int> g, list<list<int>> l) {
	for (list<int> path : l) {
		while (path.size() != 1) {
			int vert1 = path.front();
			path.pop_front();
			int vert2 = path.front();
			if (!g.containsEdge(vert1, vert2)) return false;
		}
	}
	return true;
}

