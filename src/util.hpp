#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace spark
{
	inline std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim))
		{
			elems.push_back(item);
		}
		return elems;
	}

	inline std::vector<std::string> split(const std::string &s, char delim)
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

	inline std::vector<std::string> split(std::string& s, std::string delim)
	{
		size_t pos = 0;
		std::vector<std::string> token;
		while ((pos = s.find(delim)) != std::string::npos) {
			token.push_back(s.substr(0, pos));
			s.erase(0, pos + delim.length());
		}
		token.push_back(s);
		return token;
	}

	inline bool ends_with(const std::string & value, const std::string & ending)
	{
		if (ending.size() > value.size()) return false;
		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}

	inline bool starts_with(const std::string & value, const std::string & start)
	{
		if (start.size() > value.size()) return false;
		return std::equal(start.begin(), start.end(), value.begin());
	}
}