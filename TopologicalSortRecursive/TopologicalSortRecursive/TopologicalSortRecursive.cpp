// TopologicalSortRecursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

enum colors {
	VISITING, VISITED, NOT_VISITED
};


vector<vector<int>> graph;
vector<int> result;
vector<colors> verticesColors;
bool isOk = true;

void dfs(int v) {
	if (verticesColors[v] == VISITED) {
		return;
	}

	if (verticesColors[v] == VISITING) {
		isOk = false;
		return;
	}

	//verticesColors[v] == NOT_VISITED

	verticesColors[v] = VISITING;
	for (int i = 0; i < graph[v].size(); i++) {
		dfs(graph[v][i]);
	}
	result.push_back(v);
	verticesColors[v] = VISITED;
 }


int main()
{
	int n, m, x, y;
	cin >> n >> m;
	graph.resize(n);
	verticesColors.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		graph[x].push_back(y);
	}
	for (int i = 0; i < n; i++) {
		verticesColors[i] = NOT_VISITED;
	}
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	
	if (isOk) {
		reverse(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << ++result[i] << " ";
		}
	}
	else {
		cout << "Detected cycles";
	}
	cout << endl;

    return 0;
}

