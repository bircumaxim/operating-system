#ifndef __OPERATING_SYSTEM__APPS__CALCULATOR_H
#define __OPERATING_SYSTEM__APPS__CALCULATOR_H

#include <event/key_event_handler.h>
#include <apps/app.h>

class Calculator : public App, KeyEventHandler{
    private:
	char* expression;
	int expressionIndex;
    
	int32_t firstOperand;
	int32_t secondOperand;
	char operation;
	
	
	bool isSign(char sign);
	bool parseExpression();
	void updateExpression(char* data);
	
	void solve();
    protected:
	virtual void onKeyPress(char* data);    
    public:
	virtual void run();
	virtual char* getDescription();
	Calculator();
};

#endif