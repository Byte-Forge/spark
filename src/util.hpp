#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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

	inline void split(std::string s, std::string delim, std::vector<std::string>& v) 
	{
		size_t pos = 0;
		std::string token;
		while ((pos = s.find(delim)) != std::string::npos) {
			token = s.substr(0, pos);
			v.push_back(token);
			s.erase(0, pos + delim.length());
		}
		v.push_back(s);
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