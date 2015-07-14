#pragma once
#include <string>
#include <set>
#include "Folder.h"
using std::string;
using std::set;


class CMessage
{

public:
	friend void swap(CMessage& lhs, CMessage& rhs);

	//拷贝控制成员
	CMessage(const string & m);    //默认构造函数
	
	CMessage(const CMessage & rhs);        //拷贝构造函数
	
	CMessage& operator = (const CMessage& rhs); //拷贝赋值运算符

	~CMessage();                           //析构函数

	void save(CFolder &f);                 //将消息添加到目录
	void remove(CFolder &f);               //从目录中移除消息


private:
	string contents;                       //记录消息内容
	set<CFolder *> folders;                  //记录消息所在目录
	void add_to_folders(const CMessage &);
	void remove_from_folders();
};

