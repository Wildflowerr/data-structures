#ifndef __GRAPH_H_INCLUDED__   
#define __GRAPH_H_INCLUDED__


#include <vector>
#include <list>

using std::list;
using std::vector;

template <typename T>
class Graph {
private:
	vector<vector<T>> g;
public:
	bool containsVertex(const T& v) const;

	bool containsEdge(const T& startV, const T& endV) const;

	bool isEmpty() const;

	list<T> vertices() const;

	list<T> neighbours(const T& vert) const;

	void addVertex(const T& v);

	void addEdge(const T& startV, const T& endV);

	void removeVertex(const T& v);

	void removeEdge(const T& start, const T& end);

	int countParents(const T& vert) const;

	bool hasPath(const T& startV, const T& endV) const;

	void print() const;
};
#include "Graph.cpp"
#endif