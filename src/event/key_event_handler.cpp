#include <event/key_event_handler.h>
#include <std/printf.h>


KeyEventHandler* KeyEventHandler::keyEventHandlers[256];
int KeyEventHandler::keyEventHandlersCount;

KeyEventHandler::KeyEventHandler(){ }

KeyEventHandler::KeyEventHandler(KeyEventHandler* keyEventHandler){
    keyEventHandlers[keyEventHandlersCount] = keyEventHandler;
    keyEventHandlersCount++;
}

void KeyEventHandler::onKeyPress(char* data){ }
void KeyEventHandler::onKeyRelease(char* data){ }

void KeyEventHandler::triggerPressEvent(char* data){
    for(int i = 0; i < keyEventHandlersCount; i++){
	keyEventHandlers[i]->onKeyPress(data);
    }
}

void KeyEventHandler::triggerReleaseEvent(char* data){
    for(int i = 0; i < keyEventHandlersCount; i++){
	keyEventHandlers[i]->onKeyRelease(data);
    }
}