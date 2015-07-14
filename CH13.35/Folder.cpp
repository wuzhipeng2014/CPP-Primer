#include "stdafx.h"
#include "Folder.h"


CFolder::CFolder()
{
}


CFolder::~CFolder()
{
}



void CFolder::addMsg(CMessage* m)
{
	messages.insert(m);
}

void CFolder::rmvMsg(CMessage* m)
{
	messages.erase(m);
}