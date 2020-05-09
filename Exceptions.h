#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <SFML/Graphics.hpp>


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
	file_not_found_error(std::string& _fileName) : Exception("Couldn't find "), fileName(_fileName) {}
	const char* what() const throw() {
		std::string aux = msg + fileName;
		//std::cout << msg.c_str() << '\n' << fileName.c_str() << '\n' << (aux).c_str() << '\n';
		return aux.c_str();
	}
};

#endif