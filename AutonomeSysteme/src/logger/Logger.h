/*
 * Logger.h
 *
 *  Created on: 18.05.2017
 *      Author: alex
 */

#ifndef LOGGER_LOGGER_H_
#define LOGGER_LOGGER_H_
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "ostream"
#include <stdexcept>

#define LOG_DEBUG \
    if(Logger::getLogger().getLoggingLevel() < DEBUG); \
	else Logger::getLogger().log("DEBUG:::")
#define LOG_WARNING \
	if(Logger::getLogger().getLoggingLevel() < WARNING); \
	else Logger::getLogger().log("WARNING:")
#define LOG_ERROR \
	if(Logger::getLogger().getLoggingLevel() < ERROR); \
	else Logger::getLogger().log("ERROR:::")

#define ENDL std::endl;
#define COUT std::cout

#define LOG_SET_LEVEL(value) Logger::getLogger().setLoggingLevel(value);
#define LOG_SCOPE LogScope logscope(__FUNCTION__);

using namespace std;
enum LEVEL {ERROR,WARNING,DEBUG};

class Logger {
public:
	static Logger& getLogger(void);
	ofstream& log(string str);
	void setLoggingLever(LEVEL level);
	LEVEL getLoggingLevel(void);
private:
	Logger();
	~Logger();
	Logger(const Logger& other);
	Logger &operator=(const Logger& other);
private:
	string getTime(void);
	LEVEL logginglevel_;
	ofstream logfile_;
};

class LogScope {
public:
	LogScope(const string& str);
	virtual ~LogScope();
private:
	Logger& logger_;
	string functionname_;
};

#endif /* LOGGER_LOGGER_H_ */
