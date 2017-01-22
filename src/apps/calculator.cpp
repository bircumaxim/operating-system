#include <apps/calculator.h>
#include <std/printf.h>

Calculator::Calculator() : App("calculator"), KeyEventHandler(this) {
    expression = "";
    expressionIndex = 0;
}

void Calculator::run(){
    printf("Calculator.\n");
}

void Calculator::onKeyPress(char* data){
    if(!isRunning)
	return;
    
    if(data[0] == '\n'){
	if(expressionIndex > 0){
	    if(parseExpression()){
		solve();
	    } else {
		printf("Error");
	    }
	}
	expression = "";
	expressionIndex = 0;
    } else {
	updateExpression(data);
    }	
    
    printf(data);
}

void Calculator::updateExpression(char* data){
    if(data[0] == 0x08 && expressionIndex > 0){
	expression[expressionIndex] = '\0';
	expressionIndex--;    
    } else {
	expression[expressionIndex] = data[0];
	expression[expressionIndex+1] = '\0';
	expressionIndex++;    
    }
}

bool Calculator::parseExpression(){
    char* str;
    int strIndex = 0;
    bool operationWasSet = false;
    for(int i = 0; i < expressionIndex+1; i++){
	if(isNumber(expression[i])){
	    str[strIndex] = expression[i];
	    str[strIndex+1] = '\0';
	    strIndex++;
	} else if(!operationWasSet){
	    operation = expression[i];
	    operationWasSet = true;
	    firstOperand = atoi(str);
	    str = "";
	    strIndex = 0;
	} else {
	    secondOperand = atoi(str);
	    return true;
	}    
    }
    return false;
}

bool Calculator::isSign(char sign){
    return sign >= '*' && sign <= '-';
}

void Calculator::solve(){
    clear();
    char* result;
    char str[100];
    switch(operation){
	case '+':
	    result = itoa(firstOperand + secondOperand, str, 10);
	    break;
	case '-':
	    result = itoa(firstOperand - secondOperand, str, 10);
	    break;    
	case '/':
	    result = itoa(firstOperand / secondOperand, str, 10);;
	    break;
	case '*':
	    result = itoa(firstOperand * secondOperand, str, 10);;
	    break;
    }
    printf(result);
}


char* Calculator::getDescription(){
    return "description";
}

