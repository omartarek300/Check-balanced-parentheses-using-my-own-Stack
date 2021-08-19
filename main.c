#include <stdio.h>
#include <stdlib.h>
#include "types.h"
/********************Functions Deceleration ************************/
struct stack* allocat_stack(uint32_t allocation_size);
uint8_t pop();
void push(uint8_t x);
void printStack();
uint8_t balanced_parentheses();
/*******************************************************************/
/*****************************Global variables *********************/
struct stack   //define stack with it's important characteristics Top, size and array
{   uint32_t size;
    ptrChar_t arr;
    uint32_t top;
};
struct stack* stack_ptr;
/*******************************************************************/
int main()
{   stack_ptr = allocat_stack(10); // allocate stack in memory
     /*for(int i=1; i<=10; i++) // push data into stack
     {
         push(i);
     }
     for(int i=1; i<=10; i++) // pop data from stack
     {
         pop();
     }
     printStack(); // debug stack*/
    balanced_parentheses();
    return 0;
}
struct stack* allocat_stack(uint32_t allocation_size) // function to allocate stack in the memory with the given size
{   struct stack* ptr = (struct stack*)calloc(1,sizeof(struct stack)); //allocate memory for new stack type
    ptr->size = allocation_size;                                        //specify size of stack
    ptr->top = -1;                                                      // initialize top of stack
    ptr->arr = (ptrInt_t)calloc(allocation_size, sizeof(uint8_t));      // allocate memory for stack array
    return ptr;
}

void push(uint8_t x)
{   if(stack_ptr->top == (stack_ptr->size)-1)   //check if the stack is full
    {   printf("Overflow Stack is full\n\n");
    }
    else
    {   ++(stack_ptr->top); // increment the top first then allocate new data
        stack_ptr->arr[stack_ptr->top] = x;
    }
}
uint8_t pop()
{   if(stack_ptr->top == -1)   //check if the stack is empty
    {   printf("Stack is empty\n\n");
    }
    else
    {   return stack_ptr->arr[(stack_ptr->top)--] = 0; //read the stored data first then decrease top and finally clear the location
    }
}
void printStack() //function to monitor stack
{   for (int i=0; i<stack_ptr->size; i++)
    {   printf("location[%d]-> %d\n\n",i,stack_ptr->arr[i]);
    }
}
uint8_t balanced_parentheses() // function to check validity of parentheses
{   uint8_t str[100];           // taking expression from user
    scanf("%s",str);
    for(uint32_t i=0; i< strlen(str); i++) //parse string
    {   if(str[i]=='{' || str[i]=='[' || str[i]=='(') //if string contains any opening parentheses
        {   push(str[i]);                              //push them into stack otherwise skip this iteration
            continue;
        }

        switch(str[i])
        {   case ']':
                if(stack_ptr->arr[stack_ptr->top] == '[')   // if string contains any closing parentheses
                {   pop();                                  //check if the first closing bracket is matched with the last opening
                }                                           // if so pop it from the stack
                else                                        // else then the parentheses are unbalanced
                {   printf("Unbalanced\n\n");
                    return 0;
                }
                break;
            case'}':
                if(stack_ptr->arr[stack_ptr->top] == '{')
                {   pop();
                }
                else
                {   printf("Unbalanced\n\n");
                    return 0;
                }
                break;
            case')':
                if(stack_ptr->arr[stack_ptr->top] == '(')
                {   pop();
                }
                else
                {   printf("Unbalanced\n\n");
                    return 0;
                }
                break;
        }

    }
    printf("Balanced\n\n");
}
