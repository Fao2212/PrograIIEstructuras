#include "Log.h"
#include "FileManager.h"

void Log::createlog(QString logname){
    path = FileManager::setDir().path()+"/CieloVsInfierno/LogFiles/";
    log = "";
    logName = logname;
}

void Log::addToLog(QString msg){
    log+=msg+"\n";
}

void Log::saveLog(){
    FileManager::reescribir(path+logName+".txt",log);
}

QString Log::timeStamp(){
    return QDateTime::currentDateTime().toString("yyyy-MM-ddhh-mm-ss");
}
