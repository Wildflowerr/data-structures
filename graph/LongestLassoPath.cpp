#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;

template<typename T> //problem 1b
list<list<T>> allLassoPaths(Graph<T>& g) {
	T startV = g.vertices().front();
	list<list<T>> generator = { { startV } };
	list<list<T>> all;
	while (!generator.empty()) {
		list<T> crr = generator.front();
		generator.pop_front();
		list<T> neigh = g.neighbours(crr.back());
		while (!neigh.empty()) {

			if (find(crr.begin(), crr.end(), neigh.front()) != crr.end()) {
				crr.push_back(neigh.front());
				all.push_back(crr);

			}
			else {
				crr.push_back(neigh.front());
				if (crr.front() != crr.back()) generator.push_back(crr);

			}
			crr.pop_back();
			neigh.pop_front();
		}

	}
	return all;
}

template <typename T> // problem 1b
list<T> longestLasso(Graph<T>& g) {
	list<list<T>> all = allLassoPaths(g);
	int maxSize = all.front().size();
	list<T> maxi = all.front();
	for (list<list<T>> ::iterator i = all.begin(); i != all.end(); ++i) {
		if (maxSize < (*i).size()) {
			maxSize = (*i).size();
			maxi = *i;
		}
	}

	return maxi;
}