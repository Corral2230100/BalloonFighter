#pragma once
#include <string>
namespace Engine
{
	class ILogger
	{
	public:
		virtual void Init() = 0;
		virtual void Print(const std::string Message) = 0;
		virtual void PrintError(const std::string Message) = 0;
		virtual void PrintWarning(const std::string Message) = 0;
		virtual void Close() = 0;
	};

}