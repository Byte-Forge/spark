/*
************************************
* Copyright (C) 2016 ByteForge
* Scriptengine.hpp
************************************
*/
#pragma once
#include <string>

namespace spark
{
	class IScriptEngine
	{
	public:
		IScriptEngine(const std::string& lang) : m_lang(lang) {};
		virtual void ExecuteString(const std::string& script) = 0;
		virtual void ExecuteFile(const std::string& file) = 0;
		inline const std::string GetLang() {return m_lang;}
	private:
		const std::string m_lang;
		
	};
}