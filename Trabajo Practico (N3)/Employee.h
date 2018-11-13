#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define TAMNOMBRE 100

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int isEmpty;
}Employee;


/** \brief Function that build a new employee.
 * \param   void
 * \return  (NULL) not enough memory to create the new employee.
 *          Employee* - Everything has worked.
 */
Employee* employee_new();



/** \brief Function that creates a new employee with parameters in.
 *
 * \param idStr char*               Contains id.
 * \param nombreStr char*           Contains name.
 * \param horasTrabajadasStr char*  Contains work hours.
 * \param sueldoStr char*           Contains salary.
 * \return Employee*                NULL - Not enough memory / Parameters are void.
 *                                  0    - Everything has worked.
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);




/** \brief Function that delete an employee.
 *
 * \param this Employee*            - Employee that will be deleted.
 * \return void                     - VOID.
 *
 */
void employee_delete(Employee* this);




/** \brief Function that set ID.
 *
 * \param this Employee*            - Employee that will set the ID.
 * \param id int                    - New ID.
  * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_setId(Employee* this,int id);




/** \brief Function that get ID.
 *
 * \param this Employee*            - Employee where the function get the ID
 * \param id int*                   - Current ID.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_getId(Employee* this,int* id);




/** \brief Function that set name.
 *
 * \param this Employee*            - Employee that will set the name.
 * \param nombre char*              - New name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_setNombre(Employee* this,char* nombre);




/** \brief Function that get name.
 *
 * \param this Employee*            - Employee where the function get the name.
 * \param nombre char*              - Current name.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_getNombre(Employee* this,char* nombre);




/** \brief Function that set work hours.
 *
 * \param this Employee*            - Employee that will set the work hours.
 * \param horasTrabajadas int       - New work hours.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);




/** \brief Function that get work hours.
 *
 * \param this Employee*            - Employee where the function get the work hours.
 * \param horasTrabajadas int*      - Current salary.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);




/** \brief Function that set salary.
 *
 * \param this Employee*            - Employee that will set the salary.
 * \param sueldo int                - New salary.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_setSueldo(Employee* this,int sueldo);




/** \brief Function that get salary.
 *
 * \param this Employee*            - Employee where the function get the salary.
 * \param sueldo int*               - Current salary.
 * \return int                      - (0) - Work everything // (-1) - NULL
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);




/** \brief Function that sort the employee list.
 *
 * \param pArrayListEmployee LinkedList*    -List will be sorted.
 * \return int                              - (0) - Work everything // (-1) - NULL
 *
 */
int employee_sortEmployee(LinkedList* pArrayListEmployee);




/** \brief Function that sort by salary.
 *
 * \param variableA void*                   - Variable A to be compared.
 * \param variableB void*                   - Variable B to be compared.
 * \return int                              (1) / (-1) Compared // (0) - NULL
 *
 */
int employee_ordenarPorSueldo(void* variableA, void* variableB);




/** \brief Function that sort by name.
 *
 * \param variableA void*                   - Variable A to be compared.
 * \param variableB void*                   - Variable B to be compared.
 * \return int                              (1) / (-1) Compared // (0) - NULL
 *
 */
int employee_ordenarPorNombre(void* variableA, void* variableB);




/** \brief Function that sort by hours.
 *
 * \param variableA void*                   - Variable A to be compared.
 * \param variableB void*                   - Variable B to be compared.
 * \return int                              (1) / (-1) Compared // (0) - NULL
 *
 */
int employee_ordenarPorHoras(void* variableA, void* variableB);

#endif // employee_H_INCLUDED
