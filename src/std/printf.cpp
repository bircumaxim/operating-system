#include <std/printf.h>
#include <cursor.h>

void printf(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        switch(str[i]){
            case '\n':
		cursor.setCursor(0, cursor.getCursorY()+1);
                break;
	    case 0x08:
               if(cursor.getCursorX() != 0){
		    cursor.setCursorX(cursor.getCursorX() - 1);    
		} else if(cursor.getCursorY() != 0) {
		    cursor.setCursor(79, cursor.getCursorY() - 1);
		}
		setBit(80 * cursor.getCursorY() + cursor.getCursorX(), ' ');   
                break;
            default:
		setBit(80 * cursor.getCursorY() + cursor.getCursorX(), str[i]);
                cursor.setCursorX(cursor.getCursorX()+1);
                break;
        }

        if(cursor.getCursorX() >= 80){
            cursor.setCursorX(0);
	    cursor.setCursorY(cursor.getCursorY()+1);
        }

        if(cursor.getCursorY() >= 25){
            clear();
        }
    }
}

void clear(){
    int cursorY = cursor.getCursorY();
    int cursorX = cursor.getCursorX();
    
    for(cursorY = 0; cursorY < 25; cursorY++){
	for(cursorX = 0; cursorX < 80; cursorX++){
	    setBit(80 * cursorY + cursorX, ' ');   
	}
    }
    cursor.setCursor(0,0);
    invertBitColor(0);
}

void printfHex8(uint8_t key){
    char* str = "0x00";
    char* hex = "0123456789ABCDEF";
    str[2] = hex[(key >> 4) & 0xF];
    str[3] = hex[key & 0xF];
    printf(str);
}

void printfHex16(uint16_t key){
    printfHex8((key >> 8) & 0xFF);
    printfHex8( key & 0xFF);
}

void printfHex32(int32_t key){
    printfHex8((key >> 24) & 0xFF);
    printfHex8((key >> 16) & 0xFF);
    printfHex8((key >> 8) & 0xFF);
    printfHex8( key & 0xFF);
}

bool strcmp(char* str1, char* str2){
    for(int i = 0; str1[i] != '\0'; i++){
	if(str1[i] != str2[i]){
	    return false;
	}
    }
    return true;
}

int32_t atoi(char *str){
	int32_t res = 0; // Initialize result
	int8_t negative = 0;

    // Iterate through all characters of input string and update result
    for (int32_t i = 0; str[i] != '\0'; ++i){
    	if(i == 0 && str[i] == '-')
    		negative = -1;
    	else
    		res = res*10 + str[i] - '0';
    }

    if (negative){
    	res *= -1;
    }

    // return result.
    return res;
}

int32_t strlen(char *str){
	int32_t length = -1;
	while(str[++length] != '\0');

	return length;
}

void reverse(char* str){
    int start = 0;
    int end = strlen(str)-1;
    while (start < end){
		char a = *(str+start);
		*(str+start) = *(str+end);
		*(str+end) = a;
			start++;
			end--;
    }
}


char* itoa(int num, char* str, int base){
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10){
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0){
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str);
 
    return str;
}


bool isNumber(char character){
    return character >= '0' && character <= '9';
}