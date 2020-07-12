project_test_target =[ 
         [ 'BST', 'src/test_bst.cpp',[] ],
         [ 'Linked_List', 'src/test_linked_list.cpp',[] ],
         [ 'Max_Heap', 'src/test_maxheap.cpp',[] ],
         [ 'Min_Heap', 'src/test_minheap.cpp',[] ],
         [ 'Sorting', 'src/test_sorting.cpp', [] ],
         [ 'Stack', 'src/test_stack.cpp',[] ],
         [ 'Queue', 'src/test_queue.cpp', [] ] 
        ]

foreach test : project_test_target 
        test( test[0] ,
              executable( test[0], test[1],
                          c_args: build_args,
                          dependencies: test[2] + [DSA_dep] )  )

endforeach
