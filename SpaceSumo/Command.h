#pragma once
class Command
{
public:
	virtual ~Command();

	virtual void Execute() = 0;
private:
	Command();
};

