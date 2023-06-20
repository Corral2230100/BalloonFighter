#pragma once
#include "ILogger.h"


namespace Engine2
{
	class Console : public ILogger
	{
	public:
		virtual void Init() override;

		virtual void Print(const std::string Message) override;

		virtual void PrintError(const std::string Message) override;

		virtual void PrintWarning(const std::string Message) override;

		virtual void Close() override;



		

	};
}