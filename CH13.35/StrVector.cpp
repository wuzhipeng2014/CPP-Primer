


#include "stdafx.h"
#include "StrVector.h"

#define noexcept _NOEXCEPT 

StrVector::StrVector() :elements(nullptr), first_free(nullptr), cap(nullptr)
{
}


StrVector::~StrVector()
{
	free();
}


StrVector::StrVector(const StrVector& rhs)
{
	auto newData = alloc_n_copy(rhs.begin(),rhs.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVector& StrVector::operator=(const StrVector& rhs)
{
	auto data = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

//移动构造函数
StrVector::StrVector(StrVector&& rhs) noexcept
:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	 rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

//移动赋值运算符
StrVector& StrVector::operator=(StrVector && rhs) noexcept
{
	if (&rhs!=this)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVector::push_back(const string& str)
{
	chk_n_alloc();
	alloc.construct(first_free++,str);
}

void StrVector::push_back(string && rhs)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(rhs));
}

pair<string*, string*> StrVector::alloc_n_copy(const string* b, const string* e)
{
	elements = alloc.allocate(e-b);
	return{ elements, uninitialized_copy(b, e, elements) };
}

void StrVector::free()
{
	if (elements)
	{
		for (auto item = elements; item != first_free;item++)
		{
			alloc.destroy(item);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

//怎么调用移动构造函数
void StrVector::reallocate()
{
	auto newCapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newCapacity);
	auto dest = newData;
	auto elem = elements;


	//for (size_t i = 0; i < size(); i++)
	//{
	//	alloc.construct(dest++, std::move(*elem++));
	//}
	auto last = uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),dest);

	free();
	elements = newData;
	first_free = last;
	cap = elements + newCapacity;

}

allocator<string> StrVector::alloc;