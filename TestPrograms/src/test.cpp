#include"Algos.h"
#include"GraphTestCases.h"
#include<memory>

using namespace std;


int main() {
 	/*unique_ptr<UGraph> graph = make_unique<UGraph>(5);*/
    /*UGraph* graph = new UGraph(5);*/
    /*std::shared_ptr<UGraph> graph = make_shared<UGraph>(5);*/
    DWGraph* graph = new DWGraph(9);

    w_testcase_two(graph);
   
    graph->Display();

    /*BFS(graph, 0);
    DFS(graph, 0);*/
    
    /*if (IsCycle(graph)) {
        std::cout << "\nThere is a cycle in graph!!";
    }
    else {
        std::cout << "\nThere is no cycle!!";
    }

    TopologicalSort(graph);*/
    //StronglyConnected(graph);

    delete graph;
}