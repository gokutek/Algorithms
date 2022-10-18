#include <algorithm>
#include <iostream>
#include "DepthFirstDirectedPaths.h"
#include "data_file.h"

int main()
{
	Digraph DG(get_data_file_path("tinyDG.txt"));
	size_t const source = 9;
	DepthFirstDirectedPaths path(DG, source);
	for (size_t i = 0; i < DG.V(); ++i)
	{
		bool const marked = path.HasPathTo(i);
		if (marked) {
			auto vec = path.PathTo(i);
			std::cout << "Path to " << i << ": ";
			std::for_each(vec.begin(), vec.end(), [](size_t v) {
				std::cout << v << " ";
			});
			std::cout << std::endl;
		} else {
			std::cout << "No path to " << i << std::endl;
		}
	}
	return 0;
}
