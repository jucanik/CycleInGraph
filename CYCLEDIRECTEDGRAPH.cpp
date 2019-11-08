// CYCLEDIRECTEDGRAPH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include<list>
struct Edge {
	int src;
	int dest;
};
void addedge(list<int>* adj, int v1, int v2) {
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}
bool cycle(list<int>*adj,int colour[], int j,int p) {
	colour[j] = 1;
	for (auto it = adj[j].begin(); it != adj[j].end(); it++) {
		if (*it == p)
			continue;
		if (colour[*it] == 1)
			return true;
		if (colour[*it] == 0 && cycle(adj, colour, *it,j))
			return true;
	}
	colour[j] = 2;
	return false;
}
bool iscycle(list<int>* adj,int vertex) {
	int* colour = new int[vertex * sizeof(int)];
	for (int i = 0; i < vertex; i++)
		colour[i] = 0;
	int p = 0;
	for (int j = 0; j < vertex; j++) {
		if (colour[j] == 0 && cycle(adj, colour, j,p))
			return true;
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
	struct Edge* E = new Edge[edge * sizeof(Edge)];
	for (int i = 0; i < edge; i++){
		cin >> v1;
		cin >> v2;
		addedge(adj, v1, v2);
		E[i].src = v1;
		E[i].dest = v2;
	}
	if (iscycle(adj,vertex))
		cout << 1;
	else
		cout << 0;
}

