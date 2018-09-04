//************GETS****************//


/** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
int getInt (char mensaje[]);



/** \brief Solicita un numero al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
float getFloat (char mensaje[]);



/** \brief Solicita un caracter al usuario y devuelve el resultado
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el caracter ingresado por el usuario.
 */
char getChar(char mensaje[]);




//************VALIDACIONES****************//


/** \brief Verifica si el valor recibido es numerico.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero // 0 si no es numero.
 */
int esNumerico (char str[]);



/** \brief Verifica si el valor recibido contiene solamente numeros, + y -.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero, con espacios y guion // 0 si no es numero.
 */
int esTelefono (char str[]);



/** \brief Verifica si el valor recibido contiene solamente letras.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacios y letras // 0 si contiene numero, etc.
 */
int esSoloLetras (char str[]);



/** \brief Verifica si el valor recibido contiene solo letras y numeros.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacio o letras y numeros // 0 si no.
 */
int esAlfaNumerico (char str[]);

//************FUNCIONES SOBRE CALCULAR****************//


/** \brief Funcion que devuelve una suma de 2 variables numericas..
 *
 * \param float Pide el primer valor numerico.
 * \param float Pide el segundo valor numerico.
 * \return Retorna la suma de los dos valores ingresados.
 *
 */
float funcionSumar (float , float);

/** \brief Funcion que devuelve una resta de 2 variables numericas.
 *
 * \param float Pide el primer valor numerico.
 * \param float Pide el segundo valor numerico.
 * \return Retorna la resta de los dos valores ingresados.
 *
 */
float funcionRestar (float , float);


/** \brief Funcion que devuelve una division de 2 variables numericas. Siempre y cuando la segunda no sea 0.
 *
 * \param float Pide el primer valor numerico.
 * \param float Pide el segundo valor numerico (Distinto de 0).
 * \return Retorna la división de los dos valores ingresados.
 *
 */
float funcionDividir (float , float);


/** \brief Funcion que devuelve una multiplicacion de 2 variables numericas.
 *
 * \param float Pide el primer valor numerico.
 * \param float Pide el segundo valor numerico.
 * \return Retorna la multiplicacion de los dos valores ingresados.
 *
 */
float funcionMultiplicar (float , float);


/** \brief Funcion de devuelve el factorial de una variable numerica.
 *
 * \param float Pide el primer valor numerico.
 * \return float Retorna el factorial del valor numérico ingresado.
 *
 */
float funcionFactorial (float);
