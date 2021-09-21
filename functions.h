#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define stack_size 10
#define exit 0
#define initial_position -1
#define clear 0
#define step 1
/************************************************ Global Variables ************************************************/
struct stack   //define stack with it's important characteristics Top, size and array
{   uint32_t size;
    ptrChar_t arr;
    uint32_t top;
};
struct stack* stack_ptr;
/******************************************************************************************************************/

/************************************************* Function Delaration *****************************************/
/*******
	Function Description: this function gets the expression from user
	parameter: str: the entered expression
	return: none
*/
void get_expression(uint8_t* str);

/*******
	Function Description: this function checks if the expression is balanced or not
	parameter: str: the entered expression
	return: "balanced" or "unbalanced"
*/
uint8_t* balanced_parentheses(uint8_t* str);

/*******
	Function Description: this function allocates a memory for the implemented stack
	parameter: allocation_size: the desired size of the stack
	return: none
*/
struct stack* allocat_stack(uint32_t allocation_size);

/*******
	Function Description: this function removes a data from stack then decrease the stack pointer
	parameter: allocation_size: the desired size of the stack
	return: the stored data before clearing
*/
uint8_t pop();

/*******
	Function Description: this function inserts data into stack
	parameter: data: is the data we want to push in stack
	return: none
*/
void push(uint8_t data);

/*******
	Function Description: this function prints stack contents
	parameter: none
	return: none
*/
void printStack();



#endif // FUNCTIONS_H_INCLUDED
