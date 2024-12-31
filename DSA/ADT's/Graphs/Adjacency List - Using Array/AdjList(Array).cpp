#include<iostream>
#include"AdjList(Array).h"
#include<queue>
#include<stack>
using namespace std;
AdjList::AdjList(int v, bool d)
{
	vertices = v;
	graph.reSize(v);
	isDirected = d;
}
void AdjList::addEdge(int a, int b)
{
	graph[a].pushBack(b);
	if (!isDirected)
		graph[b].pushBack(a);
}
void AdjList::print()
{
	for (int i = 0; i < vertices; i++)
	{
		cout << i << "->";
		for (int j = 0; j < graph[i].getSize(); j++)
		{
			cout << graph[i][j] << ",";
		}
		cout << endl;
	}
}
Array<int> AdjList::breadthFirstSearch()
{
	Array<int> result(vertices);
	Array<bool> visited(vertices);
	for (int i = 0; i < vertices; i++)   /// At start, no vertex is visited
		visited[i] = false;

	for (int i = 0; i < vertices; i++)   /// For disconnected vertices
	{
		if (!visited[i])
		{
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty())
			{
				int top = q.front();
				q.pop();
				result.pushBack(top);
				for (int j = 0; j < graph[top].getSize(); j++)
				{
					if (!visited[graph[top][j]])
					{
						q.push(graph[top][j]);
						visited[graph[top][j]] = true;
					}
				}
			}
		}
	}
	return result;
}
Array<int> AdjList::depthFirstSearch()
{
	Array<int> result(vertices);
	Array<bool> visited(vertices);
	for (int i = 0; i < vertices; i++)  /// At start, no vertex is visited
		visited[i] = false;

	for (int i = 0; i < vertices; i++)  /// For disconnected vertices
	{
		if (!visited[i])
		{
			stack<int> s;
			s.push(i);
			while (!s.empty())
			{
				int top = s.top();
				s.pop();
				if (!visited[top])
				{
					result.pushBack(top);
					visited[top] = true;
				}
				for (int j = graph[top].getSize() - 1; j >= 0; j--)
				{
					if (!visited[graph[top][j]])
					{
						s.push(graph[top][j]);
					}
				}
			}
		}
	}
	return result;
}