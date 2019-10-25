// Program Calculator
// Program language C
// Author Hudoits Dzianis
// Sorry for my english:)

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float Plus(float a, float b) {
	return a + b;
}

float Minus(float a, float b) {
	return a - b;
}

float Divide(float a, float b) {
	return a / b;
}

float Mult(float a, float b) {
	return a * b;
}

int main(void) {
  // left and right operands
	float number1 = 0, number2 = 0;
  // pointer to a calculate function (and pointer to a previous calculate function)
	float (*ptr) (float,float) = NULL, (*ptr_prev) (float,float) = NULL;
  // pointer to a array type char
	char *num = NULL;
  
  // write buffers
	char num1[32],num2[32];
	
  
  // main loop
	while(1) {
  
		int b = 0, i = 0;
		
		if(num == NULL) num = num1;
		

		while( 1 ) {
      // getting symbol from console
			b = getchar();
       
       
      // symbol 'q' mean exit from program
			if ((char) b == 'q') exit(0);
      
      // parsing a math operation
			if(b == '+' )  {
				ptr = Plus;
				break;
			} 
			if(b == '-' ) {
				ptr = Minus;
				break;
			}
			if(b == '/') {
				ptr = Divide;
				break;
			}
			if(b == '*') {
				ptr = Mult;
				break;
			}
			if(b == '=') {
				break;
			}
      
      // going beyond
			if(i >= 30) { printf("Stack overflow!\n"); exit(-1);}
      
      
      // put char in array
			num[i] = (char)b;
			i++;
		}

		num[i] = '\0';
    
    // swap buffers
		if(b == '+' || b == '-' || b == '*' || b == '/') {
			if (num == num1) {
				ptr_prev = ptr; // getting previous operation
				number1 = atof(num); // getting left operand
				
				num = num2;
			} else if (num == num2) {
				number2 = atof(num); // getting right operand
				number1 = ptr_prev(number1,number2); // calculate
				ptr_prev = ptr;
				
			}
		}
    
    // calculate and showing
		if((char)b == '=') {
			number2 = atof(num);
			number1 = ptr(number1,number2);
			ptr = NULL; num = num1;

			printf("Answer: %.2f\n",number1);
		} 
	}
	
}
