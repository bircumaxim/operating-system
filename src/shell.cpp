#include <shell.h>

Shell::Shell(): KeyEventHandler(this){ 
    printf("command$ ");
    runningApp = 0;
}

Shell::~Shell(){ }

void Shell::addApp(App* app){
    apps[appsCount] = app;
    appsCount++;
}

void Shell::runCommand(char* command){
    if(strcmp(command, "clear")){
	clear();
	printf("command$ ");    
    } else if(strcmp(command, "man")){
	printf("\n\n");
	for(int i = 0; i < appsCount; i++){
	    printf(" '");
	    printf(apps[i]->getAppName());
	    printf("' ");
	    printf(apps[i]->getDescription());
	    printf("\n");
	}
	printf(" 'clear'      command to clear screen\n\n"); 
	printf("command$ ");    
    } else {
	 for(int i = 0; i < appsCount; i++){
	    if(strcmp(command,apps[i]->getAppName())){
		clear();
		apps[i]->isRunning = true;
		apps[i]->run();
		runningApp = apps[i];
		return;
	    } 
	}
	printf("\n\ncommand not found !\n\n");    
	printf(" 'man'   command to learn more\n");    
	printf(" 'clear' command to clear screen\n\n");    
	printf("command$ ");    
    }
}
	
void Shell::onKeyPress(char* data){
    static char *command;
    static int commandIndex = 0;
    
    if(runningApp == 0){
	if(data[0] == '\n'){
	    if(commandIndex > 0){
		runCommand(command);
	    } else {
		printf("\ncommand$ ");    
	    }
	    commandIndex = 0;
	    command = "";
	} else {
	    if(cursor.getCursorX() > 9){
		printf(data);
	    } else if(data[0] != 0x08){
		printf(data);
	    } 
	    
	    if(data[0] == 0x08 && commandIndex > 0){
		command[commandIndex] = '\0';
		commandIndex--;    
	    } else {
		command[commandIndex] = data[0];
		command[commandIndex+1] = '\0';
		commandIndex++;    
	    }
	}
    } else {
	if(data[0] == 0x01){
	    clear();
	    printf("command$ "); 
	    runningApp->isRunning = false;
	    runningApp = 0;
	}
    }
}

