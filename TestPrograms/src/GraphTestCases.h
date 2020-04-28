#pragma once

//testcase-one
#define testcase_one(graph){\
graph->AddNewEdge(0, 1);\
graph->AddNewEdge(1, 2);\
graph->AddNewEdge(2, 2);\
graph->AddNewEdge(1, 4);\
graph->AddNewEdge(3, 1);\
graph->AddNewEdge(4, 3);\
graph->AddNewEdge(4, 0);\
graph->AddNewEdge(3, 6);\
graph->AddNewEdge(6, 4);\
graph->AddNewEdge(2, 5);\
graph->AddNewEdge(5, 7);\
graph->AddNewEdge(7, 8);\
graph->AddNewEdge(8, 5);\
}  

//testcase-two
#define testcase_two(graph){\
graph->AddNewEdge(1, 0); \
graph->AddNewEdge(0, 3); \
graph->AddNewEdge(3, 4); \
graph->AddNewEdge(0, 2); \
}


//weighted testcase-one
#define w_testcase_one(graph){\
graph->AddNewEdge(0, 1, 2);\
graph->AddNewEdge(1, 2, 4);\
graph->AddNewEdge(2, 2, 3);\
graph->AddNewEdge(1, 4, 5);\
graph->AddNewEdge(3, 1, 2);\
graph->AddNewEdge(4, 3, 7);\
graph->AddNewEdge(4, 0, 3);\
graph->AddNewEdge(3, 6, 9);\
graph->AddNewEdge(6, 4, 1);\
graph->AddNewEdge(2, 5, 10);\
graph->AddNewEdge(5, 7, 1);\
graph->AddNewEdge(7, 8, 4);\
graph->AddNewEdge(8, 5, 6);\
}  

//weighted testcase-two
#define w_testcase_two(graph){\
graph->AddNewEdge(1, 0, 1); \
graph->AddNewEdge(0, 3, 4); \
graph->AddNewEdge(3, 4, 2); \
graph->AddNewEdge(0, 2, 3); \
}

//weighted testcase-three
#define w_testcase_three(graph){\
graph->AddNewEdge(0, 1, 1); \
graph->AddNewEdge(0, 4, 3); \
graph->AddNewEdge(1, 2, 2); \
graph->AddNewEdge(1, 3, 5); \
graph->AddNewEdge(1, 4, 2); \
graph->AddNewEdge(2, 3, 4); \
graph->AddNewEdge(3, 4, 1); \
}