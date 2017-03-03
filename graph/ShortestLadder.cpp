#include <iostream>
#include <list>
#include "Graph.h"

using namespace std;

//problem 2b
list<list<int>> allLadders(Graph<int>& g) {
	list<int> allVert = g.vertices();
	while (!allVert.empty()) {
		int startV = allVert.front();
		allVert.pop_front();

		list<list<int>> generator = { { startV } };
		list<list<int>> all;

		while (!generator.empty()) {
			list<int> crr = generator.front();


			generator.pop_front();
			list<int> neigh = g.neighbours(crr.back());
			while (!neigh.empty()) {
				if (neigh.front() != crr.back() + 1) {
					neigh.pop_front();
					continue;
				}
				else {

					if (neigh.front() == crr.back() + 1) {
						crr.push_back(neigh.front());
						if (neigh.front() == 2 * crr.front()) {

							all.push_back(crr);
						}
						else {
							if (crr.front() != crr.back()) generator.push_back(crr);
						}
					}
					neigh.pop_front();
					crr.pop_back();
				}
			}
		}
		if (!all.empty()) return all;
	}

	return{};
}
//problem 2b
list<int> shortestLadder(Graph<int>& g) {
	list<list<int>> all = allLadders(g);
	int minSize = all.front().size();
	list<int> mini = all.front();
	for (list<list<int>> :: iterator i = all.begin(); i != all.end(); ++i) {
		if (minSize > (*i).size()) {
			minSize = (*i).size();
			mini = *i;
		}
	}

	return mini;
}

