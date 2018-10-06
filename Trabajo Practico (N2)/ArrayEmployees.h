typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee*, int); // FUNCION DE TP2



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
//int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) // FUNCION DE TP2



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void inicializarEmployeesConDatos (Employee*, int);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarEspacio (Employee* listaEmployee, int tam);



/** \brief Funcion que muestra un solo empleado.
 *
 * \param Employee Estructura de la cual se mostrara un solo empleado.
 * \return void.
 *
 */
void printOneEmployee (Employee);



/** \brief print the content of employees array
 *
 * \param list Employee* Puntero que apunta a la estructura de empleados
 * \param length int limite del puntero.
 * \return int
 *
 */
int printEmployees(Employee* list, int length);



/** \brief Funcion que hace que el ID sea autoincremental.
 *
 * \param Employee* Puntero que apunta a la estructura de empleados.
 * \param int limite del puntero.
 * \return int Devuelve el id incrementado en 1 si se pudo y 0 si no se pudo.
 *
 */
int idAutoIncremental(Employee*, int);



/** \brief
 *
 * \param Employee* Puntero que apunta a la estructura de empleados.
 * \param int limite del puntero.
 * \return int
 *
 */
int addEmployeesModificado(Employee*, int);



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee*, int, int); // FUNCION DE TP2



/** \brief Remove a Employee by Id (put isEmpty Flag in 0)
 *
 * \param list Employee*
 * \param int limite del puntero.
 * \param id int id del empleado.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok - (-2) if you cancel the action.
 *
 */
int removeEmployee(Employee*, int, int); // FUNCION DE TP2



/** \brief Funcion que permite modificar un empleado
 *
 * \param
 * \param int limite del puntero.
 * \return int mayor a 0 si se pudo modificar y -1 si se cancelo la modificacion.
 *
 */
int modificacionDeEmpleado(Employee*, int);



/** \brief Funcion que permite mostrar el menu del dato que se desea modificar.
 *
 * \param * Puntero a modificar datos.
 * \param  limite del puntero.
 * \return int mayor a 0 si se pudo modificar y -1 si se cancelo la modificacion.
 *
 */
int menuModificacion(Employee*, int);



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

