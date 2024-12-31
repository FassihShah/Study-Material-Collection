#ifndef ADJLIST_MAP_H
#define ADJLIST_MAP_H
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class AdjList
{
    const bool isDirected;
    unordered_map<T, list<T>> adj;
    void dfs(T node, vector<T>& res, unordered_map<T, bool>& visited);  /// DFS helping function
public:
    AdjList(bool dir = false);
    void addEdge(T key, T val);
    void print();
    vector<T> breadthFirstSearch(T start);   // using queue
    vector<T> depthFirstSearch(T start);     // recursively
};
template class AdjList<int>;
#endif