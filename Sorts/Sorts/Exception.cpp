#include "Exception.h"

//CTOR
Exception::Exception() :m_msg(nullptr)
{
}

//1-ARG CTOR
Exception::Exception(const char * msg) : m_msg(nullptr)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

//COPY CTOR
Exception::Exception(const Exception & copy) : m_msg(nullptr)
{
	*this = copy;
}

//OP=
Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[] m_msg;
		m_msg = new char[strlen(rhs.m_msg) - 1];
		strcpy(m_msg, rhs.m_msg);
	}
	return *this;
}

//OP<<
ostream & operator<<(ostream & stream, const Exception & except)
{
	if (except.m_msg != nullptr)
	{
		stream << except.m_msg << endl;
	}
	return stream;
}

//DTOR
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}


//GETTER-SETTER
const char * Exception::getMessage() const
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	if (m_msg != nullptr)
	{
		m_msg = new char[strlen(msg) - 1];
		strcpy(m_msg, msg);
	}
}