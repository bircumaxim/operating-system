#include <event/mouse_event_handler.h>
#include <std/printf.h>

MouseEventHandler* MouseEventHandler::mouseEventHandlers[256];
int MouseEventHandler::mouseEventHandlersCount;

MouseEventHandler::MouseEventHandler(){ }

MouseEventHandler::MouseEventHandler(MouseEventHandler* mouseEventHandler){
    mouseEventHandlers[mouseEventHandlersCount] = mouseEventHandler;
    mouseEventHandlersCount++;
}

void MouseEventHandler::onMouseMove(int8_t x, int8_t y){ }
void MouseEventHandler::onMouseButtonUp(uint8_t button){ }
void MouseEventHandler::onMouseButtonDown(uint8_t button){ }

void MouseEventHandler::triggerMouseMoveEvent(int8_t x, int8_t y){
    for(int i = 0; i < mouseEventHandlersCount; i++){
	mouseEventHandlers[i]->onMouseMove(x,y);
    }
}

void MouseEventHandler::triggerMouseButtonUpEvent(uint8_t button){
    for(int i = 0; i < mouseEventHandlersCount; i++){
	mouseEventHandlers[i]->onMouseButtonUp(button);
    }
}
void MouseEventHandler::triggerMouseButtonDownEvent(uint8_t button){
    for(int i = 0; i < mouseEventHandlersCount; i++){
	mouseEventHandlers[i]->onMouseButtonDown(button);
    }
}

