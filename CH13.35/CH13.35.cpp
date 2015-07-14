// CH13.35.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "StrVector.h"
#include <iostream>
#include <time.h>

using namespace std;

void printVector(StrVector s)
{
	auto item = s.begin();
	while (item!=s.end())
	{
		cout << *item << " ";
		item++;
	}
	cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	clock_t start, end;
	StrVector sv;
	string s("hello");
	sv.push_back(s);
	string * iter = sv.begin();
	cout << *iter << endl;
	sv.push_back("test");
	sv.push_back("test2");
	start = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		sv.push_back("�Ϸ�����");
	}
	end = clock();
	cout << "����ʱ��Ϊ" << endl;
	cout << end - start << endl;
	cout << sv.size() << endl;
	cout << sv.capacity() << endl;

	//printVector(sv);
	return 0;
}

