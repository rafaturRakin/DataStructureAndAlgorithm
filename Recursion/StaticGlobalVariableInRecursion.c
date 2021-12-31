#include<stdio.h>

/*
    Author: Rakin
    Date:  31-12-2021
    Language: C
    Content: Static Variable, Global Variable, Recursive Function
*/

int globalVariable = 0;


int normalRecursiveFunction(int number)
{
    if(number > 0)
        return normalRecursiveFunction(number - 1) + number;
    else
        return 0;
}


int staticVariableRecursiveFunction(int number)
{
    static int x = 0;
    if(number > 0)
    {
        x++;
        return staticVariableRecursiveFunction(number - 1) + x;
    }
    else
        return 0;
}


int globalVariableRecursiveFunction(int number)
{
    if(number > 0)
    {
        globalVariable += 5;
        return globalVariableRecursiveFunction(number - 1) + globalVariable;
    }
    else
        return 0;
}


int main()
{
    printf("\t***** An Example of Static and Global Variable in Recursive Function *****\n\n");

    int localVariableValue, staticVariableValue, globalVariableValue;

    localVariableValue = normalRecursiveFunction(5);
    staticVariableValue = staticVariableRecursiveFunction(5);
    globalVariableValue = globalVariableRecursiveFunction(5);

    printf("Local Variable Value for 5 = %d\n", localVariableValue);
    printf("Static Variable Value for 5 = %d\n", staticVariableValue);
    printf("Global Variable Value for 5 = %d\n", globalVariableValue);

    return 0;
}

