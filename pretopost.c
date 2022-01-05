/*  C Program to convert prefix to postfix using stack */

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char *pop();
char prefix[MAX];
char stack[MAX][MAX];
void push(char *str);
int isempty();
int white_space(char symbol);
void prefix_to_postfix();
int top;

int main()
{
        top = -1;
        printf("Enter Prefix Expression : ");
        gets(prefix);
        printf("\nThe string being passed to prefix_to_postfix is : %s\n",prefix);
        prefix_to_postfix();

}/*End of main()*/

void prefix_to_postfix()
{
        int i;
        char operand1[MAX], operand2[MAX];
        char symbol;
        char temp[2];
        char strin[MAX];
        for(i=strlen(prefix)-1;i>=0;i--)
        {
                symbol=prefix[i];
                printf("\nFor %d iteration symbol is : %c\n",i,symbol);
                temp[0]=symbol;
                temp[1]='\0';
                                
                if(!white_space(symbol))
                {
                        switch(symbol)
                        {
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                strcpy(operand1,pop());
                                strcpy(operand2,pop());
                                strcpy(strin,operand1);
                                strcat(strin,operand2);
                                strcat(strin,temp);             
                                push(strin);
                                printf("In %d iteration the string being pushed is :%s and the scanned symbol is operator \n",i,strin);
                                break;
                        default: /*if an operand comes*/
                             printf("In %d iteration the string being pushed is :%s and operand is scanned\n",i,strin);
                             push(temp);
                        }
                }
        }
        printf("\nPostfix Expression :: ");
        puts(stack[0]);
}/*End of prefix_to_postfix()*/


void push(char *str)
{
        if(top > MAX)
        {
                printf("\nStack overflow\n");
                exit(1);
        }
        else
        {
                top=top+1;
                strcpy( stack[top], str); 
        }
}/*End of push()*/

char *pop()
{
        if(top == -1 )
        {
                printf("\nStack underflow \n");
                exit(2);
        }
        else
                return (stack[top--]);
}/*End of pop()*/
int isempty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}
int white_space(char symbol)
{
        if(symbol==BLANK || symbol==TAB || symbol=='\0')
                return 1;
        else
                return 0;
}/*End of white_space()*/
