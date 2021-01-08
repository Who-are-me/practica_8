#pragma once

#include <string>

class MyException {
private:
	std::string path;
	std::string msg;
public:
	MyException(std::string msg) {
		this->msg = msg;
	}

	MyException(std::string msg, std::string path) {
		this->path = path;
		this->msg = msg;
	}

	std::string what() {
		return msg;
	}

	std::string what_is_path() {
		return msg + " " + path;
	}
};

