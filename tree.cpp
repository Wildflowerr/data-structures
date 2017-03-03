#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <assert.h>
using namespace std;

struct Node
{
	Node* left, *right;
	string data;
	Node(string _data, Node* _left = NULL, Node* _right = NULL) : data(_data), left(_left), right(_right) {}
};

class Tree
{
	Node* root;

	Node* copy(Node* other);

	void deletee(Node* Subtreeroot);

	void bfsADD(Node*& SubTreeRoot, string _data);

	void printScheme(Node* SubTreeRoot) const;
	
	bool isLeaf(Node* SubTreeRoot) const;

	vector<string> bfsNumbersOnLayers(Node* SubtreeRoot) const;

	void dfsNumbersOnBranches(Node* SubtreeRoot, vector<string>& all, string path) const;
public:
	Tree();

	Tree(const Tree& other);

	Tree& operator=(const Tree& other);

	~Tree();

	void add(string _data);

	void printScheme();

	vector<string> dfsNumbersOnBranches() const;

	vector<string> bfsNumbersOnLayers();
};

Node* Tree :: copy(Node* other) {
	if (other == NULL) return NULL;
	else return new Node(other->data, copy(other->left), copy(other->right));
}
void Tree :: deletee(Node* Subtreeroot) {
	if (Subtreeroot == NULL) return;
	deletee(Subtreeroot->left);
	deletee(Subtreeroot->right);
	delete Subtreeroot;
}
void Tree :: bfsADD(Node*& SubTreeRoot, string _data)
{
	queue<Node*> q;
	bool notAdded = true;
	if (SubTreeRoot) q.push(SubTreeRoot);
	else {
		SubTreeRoot = new Node(_data);
		notAdded = false;
	}

	while (notAdded) {
		Node* tmp = q.front();
		q.pop();
		if (tmp->left) q.push(tmp->left);
		else {
			tmp->left = new Node(_data);
			notAdded = false;
			continue;
		}
		if (tmp->right) q.push(tmp->right);
		else {
			tmp->right = new Node(_data);
			notAdded = false;
			continue;
		}
	}

}
void Tree :: printScheme(Node* SubTreeRoot) const {
	if (SubTreeRoot == NULL) {
		cout << "()";
		return;
	}
	else {
		cout << "(" << SubTreeRoot->data;
		printScheme(SubTreeRoot->left);
		printScheme(SubTreeRoot->right);
		cout << ")";
	}
}

bool Tree :: isLeaf(Node* SubTreeRoot) const {
	if (SubTreeRoot != NULL&&SubTreeRoot->left == NULL&&SubTreeRoot->right == NULL) return true;
	else return false;
}

vector<string> Tree :: bfsNumbersOnLayers(Node* SubtreeRoot) const {
	vector<string> all;
	queue<Node*> q;
	q.push(SubtreeRoot);
	int layerSize = q.size();

	while (!q.empty()) {
		string layer;
		while (layerSize) {
			Node* tmp = q.front();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
			q.pop();
			layer += tmp->data;
			--layerSize;
		}
		layerSize = q.size();
		all.push_back(layer);
	}
	return all;
}

void Tree ::dfsNumbersOnBranches(Node* SubtreeRoot, vector<string>& all, string path) const {
	if (SubtreeRoot == NULL) return;
	else {
		path += SubtreeRoot->data;

		if (isLeaf(SubtreeRoot)) {
			all.push_back(path);
		}

		dfsNumbersOnBranches(SubtreeRoot->left, all, path);
		dfsNumbersOnBranches(SubtreeRoot->right, all, path);
	}
}
    Tree::Tree() {
		root = NULL;
	}
	Tree::Tree(const Tree& other) {
		root = copy(other.root);
	}
	Tree& Tree :: operator=(const Tree& other) {
		if (this != &other) {
			deletee(root);
			root = NULL;
			root = copy(other.root);
		}
		return *this;
	}

	Tree::~Tree() {
		deletee(root);
		root = NULL;
	}


	void Tree :: add(string _data) {

		bfsADD(root, _data);
	}

	void Tree :: printScheme()
	{
		printScheme(root);
	}
	vector<string> Tree ::dfsNumbersOnBranches() const {
		vector<string> all;
		string path;
		dfsNumbersOnBranches(root, all, path);
		return all;
	}
	vector<string> Tree :: bfsNumbersOnLayers() {
		return bfsNumbersOnLayers(root);
	}

bool pathEqualToLayer(Tree t) {
	vector<string> inter;
	vector<string> bfs = t.bfsNumbersOnLayers();
	vector<string> dfs = t.dfsNumbersOnBranches();
	sort(bfs.begin(), bfs.end());
	sort(dfs.begin(), dfs.end());
	set_intersection(bfs.begin(), bfs.end(), dfs.begin(), dfs.end(), back_inserter(inter));
	
	return !inter.empty();
}
