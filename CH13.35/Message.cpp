#include "stdafx.h"
#include "Message.h"

CMessage::CMessage(const string& m = "") :contents(m)
{

}


CMessage::~CMessage()
{
	remove_from_folders();
}

CMessage::CMessage(const CMessage& rhs) :contents(rhs.contents), folders(rhs.folders)
{
	//将本条message添加到相应的folders
	add_to_folders(*this);
}

CMessage& CMessage::operator=(const CMessage& rhs) 
{
	remove_from_folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_folders(*this);
	return *this;
}

void CMessage::save(CFolder& f)
{

}

void CMessage::remove(CFolder& f)
{

}

void swap(CMessage& lhs, CMessage& rhs)
{
	using std::swap;
	for (auto item : lhs.folders)
		item->rmvMsg(&lhs);
	for (auto item : rhs.folders)
		item->rmvMsg(&rhs);
	swap(lhs.contents,rhs.contents);
	swap(lhs.folders,rhs.folders);
	for (auto item : lhs.folders)
		item->addMsg(&lhs);
	for (auto item : rhs.folders)
		item->addMsg(&rhs);
}

void CMessage::add_to_folders(const CMessage& m)
{

}

void CMessage::remove_from_folders()
{

}
