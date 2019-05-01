#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Exception
{
public:
	Exception();
	Exception(const char  * msg);
	Exception(const Exception & copy);

	Exception & operator=(const Exception & rhs);
	friend ostream & operator<<(ostream & stream, const Exception & except);

	~Exception();

	const char * getMessage() const;
	void setMessage(char * msg);

private:
	char * m_msg;

};
#endif // !EXCEPTION_H