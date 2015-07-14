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

	//开辟更多的空间，
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();			//销毁元素并释放内存
	void reallocate();     //获取更多的空间，并拷贝已有的元素
	string * elements;    //指向strVector的首元素
	string * first_free;  //指向strvector第一个空闲的位置
	string * cap;         //指向分配的内存之后的位置
};

