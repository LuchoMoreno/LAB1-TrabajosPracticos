/** \brief Solicita un numero - devuelve el resultado
 *
 * \param mensaje - EL mensaje que será mostrado al usuario
 * \return Es el numero ingresado.
 */
int getInt (char mensaje[]);



/** \brief Solicita un numero - devuelve el resultado
 *
 * \param mensaje - El mensaje que será mostrado al usuario
 * \return Es el numero ingresado.
 */
float getFloat (char mensaje[]);



/** \brief Solicita un caracter - devuelve el resultado
 *
 * \param mensaje - El mensaje que será mostrado al usuario
 * \return Es el caracter ingresado.
 */
char getChar(char mensaje[]);



/** \brief Hace mayusculas la primer letra del dato ingresado.
 *
 * \param caracter[] char string que sera modificado.
 * \return void
 */
void stringToUpper(char caracter[]);



/** \brief Verifica si el valor ingresado es numerico.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si es numero - 0 si no lo es .
 */
int isNumeric (char str[]);



/** \brief Verifica si el valor ingresado contiene solamente numeros.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si es numero, con espacios y guion - 0 si no lo es.
 */
int isPhone (char str[]);



/** \brief Verifica si el valor ingresado contiene solamente letras.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacios y letras - 0 si contiene numero, etc.
 */
int isOnlyLetters (char str[]);



/** \brief Verifica si el valor ingresado contiene solo letras y numeros.
 *
 * \param str Array con la cadena que sera analizada.
 * \return 1 si contiene solo espacio o letras y numeros - 0 si no.
 */
int isAlphaNumeric (char str[]);

