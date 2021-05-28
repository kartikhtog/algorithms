#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#ifndef GRAPH_CPP
#define GRAPH_CPP

using namespace std;

class Graph
{
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;
    
        /// function to add an edge to graph
        void addEdge(int v, int w) {
            adj[v].push_back(w);
        }
    
        // DFS traversal of the vertices
        // reachable from v
        void DFS(int v) {

        }
        void BFS(int v) {

        }
        void print(){
            for (auto it = adj.begin(); it != adj.end(); it++){
                auto  intsList= (*it).second;
                std::cout << "From " << (*it).first << " to "; 
                for (auto listIt = intsList.begin(); listIt != intsList.end(); listIt++) {
                    std::cout << *listIt << " ";
                }
                std::cout << std::endl;
            }
        }
        // graph with circles
        void addNodesToGraph(){
            addEdge(0, 1);
            addEdge(0, 9);
            addEdge(1, 2);
            addEdge(2, 0);
            addEdge(2, 3);
            addEdge(9, 3);
        }
        // graph without circles... so a tree
        void addNodesToGraph2(){
            addEdge(0, 1);
            addEdge(0, 9);
            addEdge(1, 2);
            addEdge(2, 4);
            addEdge(2, 3);
            addEdge(9, 8);
            addEdge(9, 10);
            addEdge(10, 12);
        }
};
#endif