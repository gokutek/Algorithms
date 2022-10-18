#ifndef COMMON_STRING_UTILS_H
#define COMMON_STRING_UTILS_H

#include <string>
#include <vector>

class StringUtils
{
public:
	// 是否为空，空格字符为false
	static bool IsEmpty(const std::string& str);

	// 是否为非空，空格字符为true
	static bool IsNotEmpty(const std::string& str);
	
	// 去除字符串两端的控制符，空字符串、null 返回 null
	static std::string Trim(const std::string& str);
	
	// 把字符串拆分成一个字符串数组，用空白符作为分隔符，字符串为空时返回空数组
	static std::vector<std::string> Split(const std::string& str);

	// 按照字符delimiter拆分字符串
	static std::vector<std::string> Split(const std::string& str, char delimiter);
};


#include "string_utils.inl"

#endif // COMMON_STRING_UTILS_H
