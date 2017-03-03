#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <assert.h>
#include <iterator>
#include "Graph.h"
using namespace std;

    template <typename T>
	bool Graph<T> :: containsVertex(const T& v) const {
		for (vector<T> adj : g) {
			if (adj.front() == v) return true;
		}
		return false;
	}

	template <typename T>
	bool Graph<T> :: containsEdge(const T& startV, const T& endV) const {
		if (containsVertex(startV) && containsVertex(endV)) {
			for (vector<T> adj : g) {
				if (adj.front() == startV) {
					for (vector<T> ::iterator i = adj.begin() + 1; i != adj.end(); ++i) {
						if ((*i) == endV) {
							return true;
						}
					}
					return false;
				}
			}
		}
		else return false;
	}

	template <typename T>
	bool Graph<T> :: isEmpty() const {
		return g.size() == 0;
	}

	template <typename T>
	list<T> Graph<T> :: vertices() const {
		list<T> allVert;
		for (vector<T> adj : g) {
			allVert.push_back(adj.front());
		}

		return allVert;
	}

	template <typename T>
	list<T> Graph<T> :: neighbours(const T& vert) const {
		assert(containsVertex(vert));
		list<T> neigh;
		for (vector<T> adj : g) {
			if (adj.front() == vert) {
				int i = 1;
				while (i < adj.size()) {
					neigh.push_back(adj[i]);
					++i;
				}
				return neigh;
			}
		}
	}
	
	template <typename T>
	void Graph<T> :: addVertex(const T& v) {
		assert(!containsVertex(v));
		vector<T> newVertex;
		newVertex.push_back(v);
		g.push_back(newVertex);
	}

	template <typename T>
	void Graph<T> :: addEdge(const T& startV, const T& endV) {
		assert(containsVertex(startV) && containsVertex(endV));
		for (vector<vector<T>> :: iterator i = g.begin(); i != g.end(); ++i) {
			if ((*i).front() == startV) {
				(*i).push_back(endV);
				break;
			}
		}
	}

	template <typename T>
	void Graph<T> :: removeVertex(const T& v) {
		assert(containsVertex(v));
		for (vector<vector<T>> ::iterator i = g.begin(); i != g.end();) {
			if ((*i).front() == v) {
				i = g.erase(i);
			}
			else {
				for (vector<T> ::iterator j = (*i).begin() + 1; j != (*i).end();) {
					if ((*j) == v) {
						j = (*i).erase(j);
					}
					else {
						++j;
					}
				}
				++i;
			}
			}
		}
	
	template <typename T>
	void Graph<T> :: removeEdge(const T& start, const T& end) {
		assert(containsVertex(start) && containsVertex(end));
		for (vector < vector<T>> ::iterator i = g.begin(); i != g.end(); ++i) {
			if ((*i).front() == start) {
				for (vector<T> :: iterator j = (*i).begin() + 1; j != (*i).end();) {
					if ((*j) == end) {
						j = (*i).erase(j);
					}
					else {
						++j;
					}
				}
			}
		}
	}

	template <typename T>
	int Graph<T> :: countParents(const T& vert) const {
		assert(containsVertex(vert));
		int countPar = 0;
		for (vector<T> adj : g) {
			if (containsEdge(adj.front(), vert)) ++countPar;
		}
		return countPar;
	}

	template <typename T>
	bool Graph<T> :: hasPath(const T& startV, const T& endV) const {
		list<T> q = neighbours(startV);
		while (!q.empty()) {
			if (q.front() == endV) return true;
			else {
				list<T> tmp = neighbours(q.front());
				q.pop_front();
				q.splice(q.begin(), tmp);
			}

		}
		return false;
	}
	
	template <typename T>
	void Graph<T> :: print() const {
		
			for (std :: vector<vector<T>> :: iterator i = g.begin(); i != g.end(); ++i) {
				for (std::vector<T> ::iterator j = (*i).begin(); j != (*i).end();++j){
					cout << (*j) << " ";
			    }
				cout << endl;
		    }
	}




