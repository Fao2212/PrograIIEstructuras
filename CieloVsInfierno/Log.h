#ifndef LOG_H
#define LOG_H
#include "includes.h"

struct Log{

    static void createlog(QString logname);
    static void saveLog();
    static void addToLog(QString msg);
    static QString createPath();
    static QString timeStamp();

};

static QString log = "";
static QString logName = "";
static QString path = "";


#endif // LOG_H
