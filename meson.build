project( 'DSA', 'cpp', 
         version: '1.0.0' )

project_description = 'A library for all Algos and Data Structures in C++ programming language'

project_headers = [ 'include/BinarySearchTree.h',
                    'include/graph.h',
                    'include/Heap.h',
                    'include/LinkedList.h',
                    'include/Node.h',
                    'include/Queue.h',
                    'include/Stack.h',
                    'include/SwapFunctions.h ' ]

project_sources = [ 'src/Algos/BFS.cpp',
                    'src/Algos/BubbleSort.cpp',
                    'src/Algos/DFS.cpp',
                    'src/Algos/Dijkstra.cpp',
                    'src/Algos/IsCycle.cpp',
                    'src/Algos/SelectionSort.cpp',
                    'src/Algos/StronglyConnected.cpp',
                    'src/Algos/TopologicalSort.cpp',
                    'src/DataStructures/BinarySearchTree.cpp',
                    'src/DataStructures/graph.cpp',
                    'src/DataStructures/Heap.cpp',
                    'src/DataStructures/Queue.cpp',
                    'src/DataStructures/LinkedList.cpp',
                    'src/DataStructures/Stack.cpp',
                    'tests/include/GraphTestCases.h' ]

project_test_headers = [ 'tests/include/GraphTestCases.h' ]

project_test_sources = ['test/src3Dmatrix.cpp',
                        'test/srctest.cpp',
                        'test/srctest_BST.cpp',
                        'test/srctest_LinkedList.cpp',
                        'test/srctest_minheap.cpp',
                        'test/srctestqueue.cpp',
                        'test/srctest_maxheap.cpp',
                        'test/srctest_sorting.cpp',
                        'test/srctest_Stack.cpp' ]   

build_args = []


# ===========================================================================
# TARGET
# ===========================================================================

public_headers = include_directories( 'include' )

build_args += ['-DPROJECT_NAME=' + meson.project_name(),
               '-DPROJECT_VERSION=' + meson.project_version() ]


libs = shared_library(
  meson.project_name(),
  project_sources,
  install : true,
  c_args : build_args,
  gnu_symbol_visibility : 'hidden',
  include_directories : public_headers,
)

DSA_dep = declare_dependency( include_directories: [public_headers],
                              link_with: libs,
                              sources: project_sources )

project_test_target = get_option( 'test_programs' )
if project_test_target
  subdir( 'tests' )
endif

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  subdirs : meson.project_name(),
  libraries : libs
)
