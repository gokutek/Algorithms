inline SymbolDigraph::SymbolDigraph(const std::string& filename, char delimiter)
{
	// First pass builds the index by reading strings to associate distinct strings with an index
	std::ifstream fs(filename);
	assert(fs.is_open());
	char buffer[256];
	while (fs.getline(buffer, sizeof(buffer))) {
		std::vector<std::string> vec = StringUtils::Split(buffer, delimiter);
		for (auto str : vec) {
			if (st_.find(str) == st_.end()) {
				st_.insert(std::make_pair(str, st_.size()));
			}
		}
	}

	// inverted index to get string keys in an aray
	keys_.resize(st_.size());
	for (auto& iter : st_) {
		keys_[iter.second] = iter.first;
	}

	// second pass builds the graph by connecting first vertex on each line to all others
	fs.clear();
	fs.seekg(0);
	digraph_.reset(new Digraph(st_.size()));
	while (fs.getline(buffer, sizeof(buffer))) {
		std::vector<std::string> vec = StringUtils::Split(buffer, delimiter);
		const size_t v = st_[vec[0]];
		for (size_t i = 1; i < vec.size(); ++i) {
			const size_t w = st_[vec[i]];
			digraph_->AddEdge(v, w);
		}
	}
}


inline bool SymbolDigraph::Contains(const std::string& s)
{
	return st_.find(s) != st_.end();
}


inline size_t SymbolDigraph::IndexOf(const std::string& s)
{
	assert(Contains(s));
	return st_[s];
}


inline std::string SymbolDigraph::NameOf(size_t v)
{
	assert(v < keys_.size());
	return keys_[v];
}


inline Digraph const & SymbolDigraph::GetGraph()
{
	return *digraph_.get();
}
