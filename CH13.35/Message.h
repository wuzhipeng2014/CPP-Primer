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

	//�������Ƴ�Ա
	CMessage(const string & m);    //Ĭ�Ϲ��캯��
	
	CMessage(const CMessage & rhs);        //�������캯��
	
	CMessage& operator = (const CMessage& rhs); //������ֵ�����

	~CMessage();                           //��������

	void save(CFolder &f);                 //����Ϣ��ӵ�Ŀ¼
	void remove(CFolder &f);               //��Ŀ¼���Ƴ���Ϣ


private:
	string contents;                       //��¼��Ϣ����
	set<CFolder *> folders;                  //��¼��Ϣ����Ŀ¼
	void add_to_folders(const CMessage &);
	void remove_from_folders();
};

