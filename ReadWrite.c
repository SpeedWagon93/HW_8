#include <stdio.h>
#include <stdlib.h>

char Write(char* fname, char* finput) 
{

    FILE *fp = fopen(fname, "w");
    if (fp == NULL) 
    {
        printf("Не удалось создать файл\n");
        return 0;
    }

    fputs(finput, fp);
    fclose(fp);

    printf("Строка успешно записана в файл\n");

    return 0;
}

char Read(char* fname)
{
    char buffer[256];

    FILE *fp = fopen(fname, "r");
    if(fp == NULL)
    {
        printf("Не удалось считать файл\n");
        return 0;
    }
    while((fgets(buffer, 256, fp)) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}

int main()
{
    char filename[100];
    char input[100];

    printf("Введите имя файла: ");
    scanf("%s", filename);
    printf("Введите строку для записи в файл: ");
    scanf(" %[^\n]", input);

    Write(filename, input);
    printf("Имеющиеся в директории файлы: ");
    fflush(stdout);
    system("ls");
    printf("Введите имя файла, который хотите прочитать: ");
    scanf("%s", filename);
    Read(filename);
}
