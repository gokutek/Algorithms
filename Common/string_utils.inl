inline bool StringUtils::IsEmpty(const std::string& str)
{
	return str.empty();
}


inline bool StringUtils::IsNotEmpty(const std::string& str)
{
	return !str.empty();
}


inline std::string StringUtils::Trim(const std::string& str)
{
	std::string res;
	size_t begin = 0, end = str.size();
	while (str[begin] == ' ' && begin < end) {
		++begin;
	}
	while (str[end - 1] == ' ' && end > begin) {
		--end;
	} 
	return str.substr(begin, end - begin);
}


inline std::vector<std::string> StringUtils::Split(const std::string& str)
{
	return Split(str, ' ');
}


inline std::vector<std::string> StringUtils::Split(const std::string& str, char delimiter)
{
	std::vector<std::string> res;
	size_t begin = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == delimiter) {
			if (begin < i) {
				res.push_back(str.substr(begin, i - begin));
			}
			begin = i + 1;
		}
	}
	if (begin < str.size()) {
		res.push_back(str.substr(begin, str.size() - begin));
	}
	return res;
}
