#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneNumber);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salary);
   
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;

    printf("###### TESTING SEARCH BY EMPLOYEE NUMBER ######\n");
    long employeeNumber = 1001;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, employeeNumber);
    if (matchPtr != NULL)
    {
        printf("Employee ID %d is in record %d\n", employeeNumber, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID %d is NOT found in the record\n", employeeNumber);
    }
    employeeNumber = 1234;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, employeeNumber);
    if (matchPtr != NULL)
    {
        printf("Employee ID %d is in record %d\n", employeeNumber, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID %d is NOT found in the record\n", employeeNumber);
    }
        
    printf("###### TESTING SEARCH BY EMPLOYEE NAME ######\n");
    char employeeName[] = "Tony Bobcat";
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, employeeName);
    if (matchPtr != NULL)
    {
        printf("Employee %s is in record %d\n", employeeName, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee %s is NOT found in the record\n", employeeName);
    }
    char employeeNameTwo[] = "Bobby Tomcat";
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, employeeNameTwo);
    if (matchPtr != NULL)
    {
        printf("Employee %s is in record %d\n", employeeNameTwo, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee %s is NOT found in the record\n", employeeNameTwo);
    }

    printf("###### TESTING SEARCH BY EMPLOYEE PHONE NUMBER ######\n");
    char employeePhone[] = "714-555-2749";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, employeePhone);
    if (matchPtr != NULL)
    {
        printf("%s is in record %d\n", employeePhone, matchPtr - EmployeeTable);
    }
    else
    {
        printf("%s is NOT found in the record\n", employeePhone);
    }
    char employeePhoneTwo[] = "123-456-7890";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, employeePhoneTwo);
    if (matchPtr != NULL)
    {
        printf("%s is in record %d\n", employeePhoneTwo, matchPtr - EmployeeTable);
    }
    else
    {
        printf("%s is NOT found in the record\n", employeePhoneTwo);
    }

    printf("###### TESTING SEARCH BY EMPLOYEE SALARY ######\n");
    double employeeSalary = 8.32;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, employeeSalary);
    if (matchPtr != NULL)
    {
        printf("Salary %lf is in record %d\n", employeeSalary, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Salary %lf is NOT found in the record\n", employeeSalary);
    }
    employeeSalary = 1.23;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, employeeSalary);
    if (matchPtr != NULL)
    {
        printf("Salary %lf is in record %d\n", employeeSalary, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Salary %lf is NOT found in the record\n", employeeSalary);
    }

    return EXIT_SUCCESS;
}