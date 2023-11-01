#include <stdio.h>
#include <stdlib.h>
#include <string>


int arraySize = 0;

int* Read(char* fname, int* array);
int* Sort(int arraySize, int* array);
int Write(char* fname, int* array, int arraySize);

int main()
{
    char filename[256];
    int* array; 
    array = new int[256];

    printf("Введите имя файла, из которого хотите считать и отсортировать массив: ");
    scanf("%s", filename);
    array = Sort(arraySize-1, Read(filename, array));
    arraySize--;
    printf("Введите имя нового файла, в который вы хотите записать отсортированный массив: ");
    scanf("%s", filename);
    Write(filename, array, arraySize);

}

int* Read(char* fname, int* array)
{
    char buffer[256];
    //int* array;
    int number = 0;

    FILE *fp = fopen(fname, "r");
    if(fp == NULL)
    {
        printf("Не удалось считать файл\n");
        return 0;
    }
    while((fgets(buffer, 256, fp)) != NULL)
    {
        for(int i = 0; buffer[i] != '\0'; i++)
        {
            if(buffer[i] >= '0' && buffer[i] <= '9')
            {
                number = number*10 + (buffer[i] - '0');
            }
            else
            {
                array[arraySize] = number;
                arraySize++;
                number = 0;
            }
        }
    }
    fclose(fp);
    return array;
}

int* Sort( int arraySize, int* array)
{
    int* sortArray = new int[arraySize];
    sortArray = array;
    for(int i = 1; i < arraySize; i++)
    {
        for(int j = 0; j < arraySize - i; j++)
        {
            if(sortArray[j] < sortArray[j+1])
            {
                int buffer = sortArray[j];
                sortArray[j] = sortArray[j+1];
                sortArray[j+1] = buffer;
            }
        }
    }
    return sortArray;
}

int Write(char* fname, int* array, int arraySize)
{
    char* newArray = new char[arraySize];
    std::string result;
    for(int i = 0; i < arraySize; i++)
    {
        result += std::to_string(array[i]);
        if(i != arraySize-1)
        {
            result += " ";
        }
    }
    for(int i = 0; i < size(result); i++)
    {
        newArray[i] = result [i];
    }
    newArray[size(result)] = '\0';
    
    FILE *fp = fopen(fname, "w");
    if(fp)
    {
        fputs(newArray, fp);
        fclose(fp);
        printf("Файл записан\n");
    }
    return 0;
}