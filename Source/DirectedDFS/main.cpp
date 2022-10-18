#include <iostream>
#include "DirectedDFS.h"
#include "data_file.h"

int main(int argc, char *argv[])
{
	Digraph DG(get_data_file_path("tinyDG.txt"));
	size_t const source = 9;
	DirectedDFS dfs(DG, source);
	for (size_t i = 0; i < DG.V(); ++i) {
		bool const marked = dfs.Marked(i);
		std::cout << source << " -> " << i << "： " << marked << std::endl;
	}
	return 0;
}
