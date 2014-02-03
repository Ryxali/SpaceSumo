#pragma once
struct Flag
{
public:
	enum Type 
	{
		CAN_MOVE, CAN_ALTER_MOVE // TODO Add more flags
	};

	Flag(Type flagT);
	Flag(Type flagT, int severity, bool status, float extra);
	Flag(const Flag &f);
	Type mFlag;
	int mSeverity;
	bool mStatus;
	float mExtra;
	inline Flag &operator=(const Flag& flag)
	{
		this->mFlag  = flag.mFlag;
		mSeverity = flag.mSeverity;
		mStatus = flag.mStatus;
		return *this;
	}

private:
	Flag();
};

