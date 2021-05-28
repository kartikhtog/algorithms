/// what is it :  going through all the element by layer
/**
 * Breadth First Search (BFS)

There are many ways to traverse graphs. BFS is the most commonly used approach.

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and 
traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). 
You must then move towards the next-level neighbour nodes.

As the name BFS suggests, you are required to traverse the graph breadthwise
*/
/// When would you uses it:
/// Implementation

#include "Graph.cpp"
#include <Queue>
class OverrideBFS : public Graph {
    public:
        std::queue<int> queue;
        void BFS(int v) {
            if(!visited[v]) {
                std::cout << v << " ";
                visited[v] = true;
                for (std::list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++ ){
                    // int var1 = (*it);
                    // if (!visited[*it]) {
                        queue.push(*it);
                    // }
                    // BFS(*it);
                }
                while(!queue.empty()){
                    int nextElement = queue.front();
                    queue.pop();
                    BFS(nextElement);
                }
            }
        }
};
int main() {
    // std::cout << "something is happening";
    OverrideBFS graph = OverrideBFS();
    graph.addNodesToGraph2();   
    graph.print();
    /// start from node 2
    graph.BFS(0);
    return 0;
};