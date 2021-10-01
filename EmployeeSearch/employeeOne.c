#include <string.h>
#include "employee.h"
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (ptr->number == targetNumber)
        {
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->name, targetName) == 0)
        {
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char *phoneNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->phone, phoneNumber) == 0)
        {
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double salary)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (ptr->salary - salary < 0.00001)
        {
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}