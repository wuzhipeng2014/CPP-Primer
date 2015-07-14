#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <string>
#include <memory>

using namespace std;



class StrVector
{
public:
	StrVector();
	~StrVector();

	StrVector(const StrVector &);
	StrVector& operator=(const StrVector &);
	void push_back(const string &);

	size_t size() const
	{
		return first_free - elements;
	}

	size_t capacity() const
	{
		return cap - elements;
	}

	string * begin() const
	{
		return elements;
	}

	string *end() const
	{
		return first_free;
	}
private:
	static allocator<string> alloc;
	void chk_n_alloc()
	{
		if (size()==capacity())
		{
			reallocate();
		}
	}

	//���ٸ���Ŀռ䣬
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();			//����Ԫ�ز��ͷ��ڴ�
	void reallocate();     //��ȡ����Ŀռ䣬���������е�Ԫ��
	string * elements;    //ָ��strVector����Ԫ��
	string * first_free;  //ָ��strvector��һ�����е�λ��
	string * cap;         //ָ�������ڴ�֮���λ��
};

