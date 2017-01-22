#include <apps/app.h>

App::App(char *name){
    appName = name;
}

void App::run(){
    
}

char* App::getAppName(){
    return appName;
}

char* App::getDescription(){
    return "";
}