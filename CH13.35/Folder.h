#pragma once
#include <set>

using std::set;
class CMessage;
class CFolder
{
public:
	CFolder();
	~CFolder();
	void rmvMsg(CMessage* m);
	void addMsg(CMessage* m);

private:
	set<CMessage *> messages;
};

