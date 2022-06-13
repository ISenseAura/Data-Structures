/****************************************************************************
  *  SELF WRITTEN                                                           *
  *                                                                         *
  *  @desc Stack implementation in C using structure.                       *
  *        Tried using the concept of constructors from OOP                 *
  *  @author Mayur (mayurhiwale2451982@gmail.com)                           *
  *  @required include required header files                                *
  *  @license MIT license                                                   *
  *  @git https://github.com/Zerapium/Data-Structures                       *
  *                                                                         *
  **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define DEBUG "\n [DEBUGGING] --- "

extern int errno;

void n()
{
    printf("\n");
}

typedef struct Stack
{
    int size;
    int data[100];
    int first;

    void (*pop)();
    void (*push)();
    int (*isFull)();
    int (*isEmpty)();
    void (*display)();

} Stack;

int isFull(Stack *stack)
{
    if (errno)
        perror("Somethings wrong : ");

    if (stack->first == 100)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Stack *stack)
{
    if (stack->first == -1)
    {
        return 1;
    }
    return 0;
}

void display(Stack *stack)
{
    if (stack->isEmpty())
    {
        printf("The stack is empty ");
    }
    else
    {
        int pos = 1;
        printf("\n -----Displaying Stack------- \n");
        printf("         ______    \n");
        for (int i = stack->first; i > -1; i--)
        {

            printf("        |__%d__|    \n", stack->data[i]);

            pos++;
        }
    }
}

void push(int ele, Stack *stack)
{
    if (stack->isFull(stack))
    {
        printf("Stack overflow!");
    }

    else
    {

        stack->first = stack->first + 1;
        stack->data[stack->first] = ele;
    }
}

void pop(Stack *stack)
{
    if (stack->isEmpty(stack))
    {
        n();
        printf("Stack underflow!");
        n();
    }
    else
    {
        printf("\n Popped : %d \n", stack->data[stack->first]);

        stack->first = stack->first - 1;
        int nD[100];
        /*    if (stack->first > -1)
            {
                for (int i = 0; i <= stack->first; i++)
                {
                    nD[i] = stack->data[i];
                }
            }
            stack->data[100] = nD[100]; */
    }
}

Stack newStack()
{
    Stack stack;
    stack.push = &push;
    stack.pop = &pop;
    stack.isEmpty = &isEmpty;
    stack.isFull = &isFull;
    stack.first = -1;
    stack.display = &display;
    return stack;
}

void main()
{
    Stack st = newStack();

    while (1)
    {
        n();
        int input;
        printf("Choose Operation \n");
        printf("  1. Push \n  2. Pop \n  3. Display \n  4. Exit \n  ");
        printf("Operation : ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
        {
            int ele;
            printf("Enter an element to push \n");
            scanf("%d", &ele);
            st.push(ele, &st);
        }
        break;
        case 2:
        {
            st.pop(&st);
        }
        break;
        case 3:
        {
            st.display(&st);
        }
        break;
        case 4:
        {
            exit(0);
        }
        break;
        default:
        {
            printf("Invalid choice dude \n");
        }
        }
    }
}
