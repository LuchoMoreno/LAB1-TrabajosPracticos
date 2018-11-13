/** \brief Load the data from the file data.csv (text mode).
 *
 * \param path char*                                - Direction / Name where the data is load.
 * \param pArrayListEmployee LinkedList*            - List where data is load.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Load the data from the file data.csv (bin mode).
 *
 * \param path char*                                - Direction / Name where the data is load.
 * \param pArrayListEmployee LinkedList*            - List where data is load.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee is.
 * \return int                                      - (-1) NULL // (X) Next ID.
 *
 */
int controller_nextID(LinkedList* pArrayListEmployee);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be add.
 * \return int                                      - (-1) NULL // (0) Employee added.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be edited.
 * \return int                                      - (-1) NULL // (0) Employee edited.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be removed.
 * \return int                                      - (-1) NULL // (0) Employee removed. // (-2) Canceled.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be list.
 * \return int                                      - (-1) NULL // (0) Employee listed.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be sorted.
 * \return int                                      - (-1) NULL // (0) Employee sorted.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Save the data into the file data.csv (text mode).
 *
 * \param path char*                                - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*            - List where data is save.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Save the data into the file data.bin (bin mode).
 *
 * \param path char*                                - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*            - List where data is save.
 * \return int                                      - (-1) NULL // (1) Everything works.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Show message
 *
 * \param                                           -void.
 * \return                                          -void.
 *
 */
void controller_firstMessage (void);
