// CYCLEGRAPH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
using namespace std;
struct Edge {
	int src;
	int dest;
};
void addedge(list<int>* adj,int v1,int v2) {
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}
int find(int parent[], int i) {
	if (parent[i]== -1)
		return i;
	return find(parent, parent[i]);
}
void unionfind(int parent[], int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset)
		parent[xset] = yset;
}
bool iscycle(list<int>* adj, struct Edge* e,int v) {
	int* parent = new int[v * sizeof(int)];
	for (int i = 0; i < v; i++)
		parent[i] = -1;
	for (int j = 0; j < sizeof(e); j++) {
		int x = find(parent, e[j].src);
		int y = find(parent, e[j].dest);
		if (x == y)
			return true;
		unionfind(parent, x, y);
	}
	return false;
}
int main()
{
	int vertex;
	int edge;
	cin >> vertex;
	cin >> edge;
	int v1, v2;
	list<int>* adj = new list<int>[vertex * sizeof(int)];
	int countedge = 0;
	struct Edge *E = new Edge[edge * sizeof(Edge)];
	for (int i = 0; i < vertex; i++)
	{
		cin >> v1;
		cin >> v2;
		addedge(adj, v1,v2);
		E[i].src = v1;
		E[i].dest = v2;
	}
	if (iscycle(adj, E,vertex))
		cout << 1;
	else
		cout << 0;
}

