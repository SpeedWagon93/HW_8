#include <stdio.h>
#include <stdarg.h>

char* stroka(char first, ...)
{
    char *result = new char[256];
    va_list args;
    va_start(args, first); 
    char simb = first;
    for(int i = 0; simb != ';'; i++)
    {
        result[i] = simb;
        simb = va_arg(args, int);
    }
    va_end(args); 
    return result;
}
int main(void)
{
    printf("%s \n", stroka('H', 'e', 'l', 'l', 'o', ';'));
    printf("%s \n", stroka('H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', ';'));
    return 0;
}