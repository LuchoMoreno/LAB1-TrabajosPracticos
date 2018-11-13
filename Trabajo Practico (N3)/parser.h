
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList*                -List.
 * \return int                                          NULL - Not enough memory. // (-1) NULL // (0) Everything works.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pArrayListEmployee LinkedList*                -List.
 * \return int                                          NULL - Not enough memory. // (-1) NULL // (0) Everything works.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
