#include <iostream>
#include <list>
#include "Graph.h"

using namespace std; 

template <typename T> // problem 4
list<list<T>> allPaths(Graph<T>& g, const T& startV, const T& endV) {
	assert(g.containsVertex(startV) && g.containsVertex(endV));
	list<list<T>> generator = { { startV } }; //generates paths
	list<list<T>> all;

	while (!generator.empty()) {
		list<T> crr = generator.front();
		generator.pop_front();
		list<T> neigh = g.neighbours(crr.back());
		while (!neigh.empty()) {

			crr.push_back(neigh.front());
			if (neigh.front() == endV) {
				all.push_back(crr);

			}
			else {

				if (crr.front() != crr.back()) generator.push_back(crr);

			}
			crr.pop_back();
			neigh.pop_front();
		}

	}

	return all;
}

template <typename T> //problem 4
list<T> findAcyclicPath(Graph<T>& g, T a, T b) {
	list<T> p;

	list<list<T>> allAB = allPaths(g, a, b);

	while (!allAB.empty()) {
		p = allAB.front();
		allAB.pop_front();
		list<T> tmp = p;
		tmp.pop_front();
		tmp.pop_back();
		vector<T> path{ begin(tmp), end(tmp) };
		if (g.containsEdge(b, a)) return{ b,a }; //when empty set is subset of path
		while (path.size() > 1) {
			list<T> adj = g.neighbours(b);
			vector<T> adj1{ begin(adj), end(adj) };

			vector<T> inter;
			sort(adj1.begin(), adj1.end());
			sort(path.begin(), path.end());
			set_intersection(path.begin(), path.end(), adj1.begin(), adj1.end(), back_inserter(inter));

			path.erase(find(path.begin(), path.end(), inter.front()));

			b = inter.front();


		}

		if (g.containsEdge(path.front(), a)) return p;
	}
	return{};
}

