#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Exception : public std::exception
{
protected:
	std::string msg;
public:
	Exception(const char* _msg) : msg(_msg) {}
	Exception(std::string& _msg) : msg(_msg) {}
	virtual const char* what() const throw() { return msg.c_str(); }
	virtual ~Exception() noexcept {}
};

class file_not_found_error : public Exception
{
	std::string fileName;
public:
	file_not_found_error(std::string& _fileName) : Exception("Couldn't find "), fileName(_fileName) { msg += fileName; }
	const char* what() const throw() { return msg.c_str(); }
};

#endif