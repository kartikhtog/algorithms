/// what is it :  going through the graph by depth first
/**
 * Depth First Search
 * Keep visiting children first instead of sliblings first
*/
/// When would you uses it:
/// Implementation

#include "Graph.cpp"
#include <Stack>
class OverrideDFS : public Graph {
    public:
        void DFS(int v) {
            if(!visited[v]) {
                std::cout << v << " ";
                visited[v] = true;
                for (std::list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++ ){
                    DFS(*it);
                }
            }
        }
};
int main() {
    OverrideDFS graph = OverrideDFS();
    graph.addNodesToGraph2();   
    graph.print();
    graph.DFS(0);
    return 0;
};