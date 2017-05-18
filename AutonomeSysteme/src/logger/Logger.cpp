/*
 * Logger.cpp
 *
 *  Created on: 18.05.2017
 *      Author: alex
 */

#include "Logger.h"

Logger& Logger::getLogger() {
	static Logger instance;
	return instance;
}

ofstream& Logger::log(string str) {
	logfile_ << getTime() << " " << str << " ";
	return logfile_;
}

void Logger::setLoggingLever(LEVEL level) {
	logfile_ << "setting output level to " << level << endl;
	logginglevel_ = level;
}

LEVEL Logger::getLoggingLevel() {
	return logginglevel_;
}

Logger::Logger() :
		logginglevel_(DEBUG) {
	logfile_.open("logging.txt", ios::trunc);
	logfile_ << "LOGFILE. Build: " << getTime() << endl;
}

Logger::~Logger() {
	logfile_ << "END OF LOGFILE" << endl;
	logfile_.close();
}

LogScope::LogScope(const string& str) :
		logger_(Logger::getLogger()), functionname_(str) {
	logger_.log("SCOPE:::") << "entering " << functionname_ << endl;
}

LogScope::~LogScope() {
	logger_.log("SCOPE:::") << "exiting " << functionname_ << endl;
}

std::string Logger::getTime() {
    char *str = (char *) malloc(sizeof(char) * 26);
    int millisec = 0;
    struct tm* tm_info;
    struct timeval tv;



    gettimeofday(&tv, NULL);

    millisec = lrint(tv.tv_usec/1000.0); // Round to nearest millisec
    if (millisec>=1000) { // Allow for rounding up to nearest second
        millisec -=1000;
        tv.tv_sec++;
    }

    tm_info = localtime(&tv.tv_sec);

    strftime(str, 26, "%Y:%m:%d, %H:%M:%S", tm_info);

    std::string zero;
    if(millisec < 10) {
        zero = "00";
    } else if(millisec < 100) {
        zero = "0";
    } else {
        zero = "";
    }

    std::stringstream ss;
    ss << str << ":" << zero << millisec;

    std::string result = ss.str();
    free(str);

    return result;
}
