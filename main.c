#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "functions.h"

int main()
{   stack_ptr = allocat_stack(stack_size); // allocate stack in memory
     /*for(int i=1; i<=10; i++) // push data into stack
     {
         push(i);
     }
     for(int i=1; i<=10; i++) // pop data from stack
     {
         pop();
     }
     printStack(); // debug stack*/
    uint8_t* str;
    get_expression(&str);
    uint8_t* result = balanced_parentheses(&str);
    printf("\n%s",result);
    return exit;
}
struct stack* allocat_stack(uint32_t allocation_size) // function to allocate stack in the memory with the given size
{   struct stack* ptr = (struct stack*)malloc(sizeof(struct stack)); //allocate memory for new stack type
    ptr->size = allocation_size;                                        //specify size of stack
    ptr->top = initial_position;                                                      // initialize top of stack
    ptr->arr = (ptrInt_t)calloc(allocation_size, sizeof(uint8_t));      // allocate memory for stack array
    return ptr;
}

void push(uint8_t data)
{   if(stack_ptr->top == (stack_ptr->size)-1)   //check if the stack is full
    {   printf("Overflow Stack is full\n\n");
    }
    else
    {   ++(stack_ptr->top); // increment the top first then allocate new data
        stack_ptr->arr[stack_ptr->top] = data;
    }
}
uint8_t pop()
{   if(stack_ptr->top == initial_position)   //check if the stack is empty
    {   printf("Stack is empty\n\n");
    }
    else
    {   return stack_ptr->arr[(stack_ptr->top)--] = clear; //read the stored data first then decrease top and finally clear the location
    }
}
void printStack() //function to monitor stack
{   for (int iterator=0; iterator<stack_ptr->size; iterator++)
    {   printf("location[%d]-> %d\n\n",iterator,stack_ptr->arr[iterator]);
    }
}
uint8_t* balanced_parentheses(uint8_t* str) // function to check validity of parentheses
{
    for(uint32_t char_index =0; char_index < strlen(str); char_index++) //parse string
    {   if(str[char_index]=='{' || str[char_index]=='[' || str[char_index]=='(') //if string contains any opening parentheses
        {   push(str[char_index]);                              //push them into stack otherwise skip this iteration
            continue;
        }

        switch(str[char_index])
        {
            case'}':
                if(stack_ptr->arr[stack_ptr->top] == '{')
                {   pop();
                }
                else
                {
                    return "Unbalanced";
                }
                break;
            case')':
                if(stack_ptr->arr[stack_ptr->top] == '(')
                {   pop();
                }
                else
                {
                    return "Unbalanced";
                }
                break;
        }

    }
    return "Balanced";
}
void get_expression(uint8_t* str)
{
    // taking expression from user
    scanf("%s",str);
}
