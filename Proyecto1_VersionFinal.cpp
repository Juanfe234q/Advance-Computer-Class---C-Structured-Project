/*Proyecto Progra - Corte 1*/
/*Nombre: LabManager*/
/*Versión Final: 
Por:
Malu Ortega
Santi Moreno
Juanfe Quintero
:D
*/

/*Cada una de las secciones del Codigo estan organizadas y propiamente comentadas
pero también dentro del repositorio de GitHub hemos decidido Incluir un readme por 
lo que también durante la sustentación acompañaremos la sustentación con el readme*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*A continuacion mostramos las Estructuras del codigo según los requerimientos del proyecto*/

/*En ves de utilizarse arreglos de tamaño fijo [] se usa 
memoria dinamica :D*/
/*-EQUIPO-----------------------------------*/
struct Equipo{
    int codigo;
    char *nombre;
    char *laboratorio;
    char *tipo;
    int costoEstimado;
    char *operativo;
    int semestreMin;
    char *descripcionTecnica;
};
/*-USUARIO----------------------------------*/
struct Usuario{
   int codigoInst;
   char *nombrest;
   char *carrera;
   int semestre;
};
/*-SESION DE USO----------------------------*/
struct SesionUso{
    int codigoSesion;
    int codigoEquipo;
    int codigoUsuario;
    char fecha[30]; //YYYY-MM-DD
    int duracion;
    char observaciones[100];
    float penalizacion;
};
/*-----------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Primera Función: Cargar Equipos
¿Qué debe hacer esta función?
- Cargar el archivo de texto correctamente
- Comprobar la existencia correcta de los equipos (En el formato dado)
- Devolver el numero de equipos
*/
int cargarEquipos( Equipo *equipos){
    /*
    - Esta funcion, nos permite cargar la informacion de los equipos 
    del archivo para guardarlo al arreglo de estructuras de equipos.
    
    - Para esto le pasamos de parametro un apuntador a 
    el arreglo de equipos.
    
    - La función nos retorna un entero debido a que queremos 
    retornar la cantidad de equipos registrados.

    -Se vale mencionar que el tipo de archivo utilizado es txt.
    
    */
    int numEquipos=0; 
    /*Con esto podemos ir aumentando +numEquipos cuando estemos 
    guardando la informacion con el apuntador.*/
    int numEspacios=0;
    char linea[300];
    char nomArchivo[50];
    cout<<"Ingrese el nombre del archivo"<<endl;
    cin.getline(nomArchivo,50);
    /*Se toma el nombre de archivo que el usuario digite en la consola, 
    para apartir de esto abrir el archivo.*/
    
    /*-PRIMERA PARTE-------ABRIR EL ARCHIVO DE TEXTO---------------------*/
    ifstream archivo(strcat(nomArchivo,".txt"));
    /*Debemos concatenar el nombre del archivo con el .txt de esta forma 
    el ifstream pueda abrir el archivo de forma correcta.*/

    /*-SEGUNDA PARTE--------LECTURA DEL ARCHIVO E IDENTIFICACIÓN DE EQUIPOS---------*/
    while(archivo.getline(linea,300)){
        //Aqui se hace la lectura del archivo con el while
        
        numEspacios=0;
        /*Creamos un contador el cual nos va a verificar la cantidad de campos por linea esto para saber si el formato del equipo en el archivo esta correcto.

        Si esta correcto deben haber 8 campos

        ¿Cómo se verifica esto?
        Con strtok - Que busca en nuestro caso: (*)
        - Y lo reemplaza con \0 para partir la cadena en pedazos y contarlos
        - Como esto significa un cambio a la cadena es necesario copiarla antes (strcpy)
        */

        char copia[300];
        strcpy(copia,linea);
        
        char *token= strtok(copia,"*");
        /* Definimos nuestro token separador al asterisco * */

        while(token !=nullptr){
            numEspacios++;
            /*Cada vez que encontremos un caracter * aumentamos el contador en 1*/
            token=strtok(NULL,"*");
            /*Aqui decimos, siga leyendo desde donde encontraste el asterisco*/
        }
        /*SE HACE UNA VERIFICACIÓN - SI SON DIFERENTES DE 8 ESPACIOS - SE INFORMA QUE HAY UN ERROR EN EL FORMATO*/
        if(numEspacios !=8){
            cout<<"Hay un error en el formato de Equipos! :("<<endl;
            continue;
        }

        /*ALMACENAMIENTO EN LA MEMORIA DINÁMICA*/
        token= strtok(linea, "*");
        (equipos+numEquipos)->codigo=atoi(token);
        /*
        - Cómo funciona la logica: Vamos pedazo por pedazo guardando 
        con memoria dinámica y aritmetica de apuntadores!

        - Como el contador se actualiza cada vez que guardamos todo un equipo primero
        NumEquipos sera = 0 e ira aumentando hasta 1, 2, etc...

        - El atoi se usa porque tenemos en el archivo el codigo como un char, entonces 
        tenemos que guardarlo en la posición de la estructura como un int
        ----------------------------------------------------------------------------------------
        */
        token=strtok(NULL,"*");
        (equipos+numEquipos)->nombre = new char[strlen(token)+1];
        strcpy((equipos+numEquipos)->nombre,token);
        /*
        #Anotaciones Importantes: 
        - Que hace Srtlen? -> mide  cuantos caracteres tiene el texto
        - Porque +1? -> siempre la cadena char tiene un \0 caracter de mas
        - En memoria dinamica creamos un new!
        - Con la funcion strcpy podemos guardar la informacion leida por token en
         nombre, no podemos igualar como arriba porque es una cadena de caracteres.

        Del resto la lógica es la misma básicamente que la de antes
        -----------------------------------------------------------------------------------------
        */
        token=strtok(NULL,"*");
        (equipos+numEquipos)->laboratorio = new char[strlen(token)+1];
        strcpy((equipos+numEquipos)->laboratorio, token);
        /*LOGICA EQUIVALENTE!---------------------------------------------------------------------*/
        token=strtok(NULL,"*");
        (equipos+numEquipos)->tipo = new char[strlen(token)+1];
        strcpy((equipos+numEquipos)->tipo, token);
        /*LOGICA EQUIVALENTE!---------------------------------------------------------------------*/
        token=strtok(NULL,"*");
        (equipos+numEquipos)->costoEstimado=atoi(token);
        /*LOGICA EQUIVALENTE! (A CODIGO)---------------------------------------------------------------------*/
        token=strtok(NULL,"*");
        (equipos+numEquipos)->operativo = new char[strlen(token)+1];
        strcpy((equipos+numEquipos)->operativo,token);
        /*LOGICA EQUIVALENTE!---------------------------------------------------------------------*/
        token=strtok(NULL,"*");
        (equipos+numEquipos)->semestreMin=atoi(token);
        /*LOGICA EQUIVALENTE! (A CODIGO)---------------------------------------------------------------------*/
        token=strtok(NULL,"*");
        (equipos+numEquipos)->descripcionTecnica = new char[strlen(token)+1];
        strcpy((equipos+numEquipos)->descripcionTecnica,token);

        /*EN RESUMEN:
        Si tenemos un numero debemos usar atoi para convertir su formato de esta forma guardalo 
        de forma correcta en nuestras variables int.
        
        Si es una cadena de caracteres en el arreglo de cada equipo, lo guardamos como una copia de token y 
        pedimos el tamaño de cada arreglo dinamico como la longitud exacta de la cadena de caracteres +1
        */
        
        /* cada vez que guardamos exitosamente un equipo completo aumentamos numEquipos */
        numEquipos++; 
    }
    

    /*Finalmente retornamos el valor final de equipos que se guardaron en el arreglo dinamicos de estructuras*/
    archivo.close();
    return numEquipos;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Segunda Funcion: Cargar Usuarios
¿Que debe hacer la función?
- Con esta funcion, cargamos la informacion del archivo que contiene 
la informacion de los usuarios que utilizan los equipos.

- La funcion devolvera la cantidad de usuarios registrados en el archivo
*/

int cargarUsuarios(Usuario *usuarios){
    int numUsuarios=0;
    int numEspacios=0;
    char linea[200];

    /*PRIMERA PARTE-----------CARGAR EL ARCHIVO EN LECTURA---------*/
    ifstream archivo("usuarios.txt");
    /*Con el While se hace el recorrido del archivo por completo*/
    while(archivo.getline(linea,200)){
        numEspacios=0;
        char copia[200];
        strcpy(copia,linea);
        /*usamos la misma logica que la funcion pasada de crear una copia de la linea para no tener el 
        riesgo que se modifique al usar strtok sobre ella.*/
        
        /*Definimos el separador de informacion del archivo como el caracter (*) */
        char *token= strtok(copia,"*");

        /*contamos los caracteres (*) de cada linea de esta forma podemos asegurarnos 
        que el formato de la linea en el archivo de etexto este correcto.*/
        while(token !=nullptr){
            numEspacios++;
            token=strtok(NULL,"*");
        }
        /*Equivalente a la función pasada: Si el numero de separaciones es diferente de 4*/
        if(numEspacios !=4){
            cout<<"Hay un error en el formato! :("<<endl;
            continue;
        }

        /*
        Logica de Memoria dinamica para partes de tipo entero: (Equivalente a la funcion pasada)
        - Guardamos el codigo del usuario en el arreglo de estructuras en la posicion de este usuario
        - Ademas usamos atoi para cambiar el fomato que viene como un char del archivo a 
        
        ----------------------------------------------------------------------------------------------------
        Logica de Memoria dinamica para partes de cadenas de caracteres:
        - En el arreglo de cada equipo, lo guardamos como una copia de token y pedimos el tamaño 
        de cada arreglo dinamico como la longitud exacta de la cadena de caracteres +1 por el 
        caracter extra que tienen todos los datos tipo char[]

        -----------------------------------------------------------------------------------------------------
        */
        token= strtok(linea, "*");
        (usuarios+numUsuarios)->codigoInst=atoi(token);

        token=strtok(NULL,"*");
        (usuarios+numUsuarios)->nombrest = new char[strlen(token)+1];
        strcpy((usuarios+numUsuarios)->nombrest,token);

        token=strtok(NULL,"*");
        (usuarios+numUsuarios)->carrera = new char[strlen(token)+1];
        strcpy((usuarios+numUsuarios)->carrera, token);

        token=strtok(NULL,"*");
        (usuarios+numUsuarios)->semestre=atoi(token);

        /*cada vez que llenamos la informacion completa de un usuario aumentamos en numUsuarios :D*/
        numUsuarios++;

    }
    /*Cerramos y retornamos el valor final del contador.*/
    archivo.close();
    return numUsuarios;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Tercera Funcion: Consultar el Estado operativo
¿Que debe hacer la función?
(Mostrar en un lab - Equipos operativos, en mantenimiento y con restricciones)
*/

/* Recibimos como parametro el numero total de equipos registrados y el apuntador a al arreglo de equipos.*/
void consultarEstadoOperativo(Equipo *equipos, int numEquipos){
    
    //Esto para guardar el nombre del lab que el usuario quiere buscar (maximo tamaño de 50)
    char labUsuario[50];

    cout<<"Ingrese el laboratorio que busca :D"<<endl;
    cin.ignore();
    cin.getline(labUsuario,50);

    /*
    Ahora recorremos el arreglo dinamico de equipos:
    
    Primero: Comparamos con strcmp los nombres registrados de laboratorios (cuando de 0, hubo coicidencia) 
    Segundo: Ahora vamos con los condicionales: ESTADO OPERATIVO O LAS RESTRICCIONES
    */
    for(int i=0; i<numEquipos; i++){
        /*PRIMERO: COMPARACIÓN*/
       if(strcmp((equipos+i)->laboratorio,labUsuario)==0){
        /*SEGUNDO: LAS RESTRICCIONES: OPERATIVO*/
        if(strcmp((equipos+i)->operativo,"operativo")==0){
            /*Volvemos a usar strcmp comparamos el estado operativo de los equipos:
            Lo comparamos con "operativo" -> si da 0, hubo coincidencia e 
            indicamos que esta operativo con TODA su info!
            */
            cout<<"      Equipo Operativo      "<<endl;
            cout<<"Codigo: "<< (equipos+i)->codigo <<endl;
            cout<<"Nombre: "<< (equipos+i)->nombre <<endl;
            cout<<"Laboratorio: "<< (equipos+i)->laboratorio<<endl;
            cout<<"Tipo: "<< (equipos+i)->tipo<<endl;
            cout<<"Costo estimado: "<< (equipos+i)->costoEstimado<<endl;
            cout<<"Semestre minimo requerido: "<< (equipos+i)->semestreMin<<endl;
            cout<<"Descripcion tecnica: "<< (equipos+i)->descripcionTecnica<<endl;
        }
        /*SEGUNDO: LAS RESTRICCIONES: MANTENIMIENTO - MISMA LOGICA ANTERIOR*/
        if (strcmp((equipos+i)->operativo,"mantenimiento")==0){
            cout<<"       Equipo en Mantenimiento     "<<endl;
            cout<<"Codigo: "<< (equipos+i)->codigo<<endl;
            cout<<"Nombre:"<< (equipos+i)->nombre<<endl;
            cout<<"Laboratorio: "<< (equipos+i)->laboratorio<<endl;
            cout<<"Tipo: "<< (equipos+i)->tipo<<endl;
            cout<<"Costo estimado: "<< (equipos+i)->costoEstimado<<endl;
            cout<<"Semestre minimo requerido: "<< (equipos+i)->semestreMin<<endl;
            cout<<"Descripcion tecnica: "<< (equipos+i)->descripcionTecnica<<endl;
        }
        /*AHORA VAMOS CON LAS RESTRICCIONES POR SEMESTRE*/
        if((equipos+i)->semestreMin>1){
            /*El condicional aqui toma valores mayores a primer semeste, lo que lo convierte un 
            equipo con restricciones*/ 
            cout<<"    Equipo con restriccion de semestre      "<<endl;
            /*Aqui indicamos que tiene restricciones y que su semestre minimo es tal*/
            cout<<"El Semestre minimo requerido es "<< (equipos+i)->semestreMin<<endl;
            /*Imprimos toda la info del equipo*/
            cout<<"Codigo: "<< (equipos+i)->codigo<<endl;
            cout<<"nombre: "<< (equipos+i)->nombre<<endl;
            cout<<"laboratorio: "<< (equipos+i)->laboratorio<<endl;
            cout<<"Tipo: "<< (equipos+i)->tipo<<endl;
            cout<<"Estado operativo: "<< (equipos+i)->operativo<<endl;
            cout<<"Costo estimado: "<< (equipos+i)->costoEstimado<<endl;
            cout<<"Descripcion tecnica: "<<(equipos+i)->descripcionTecnica<<endl;
        }
     }
   }
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Cuarta Función: Programar Sesion de uso
Solicitar el usuario, el equipo y la duración estimada
Se debe validar:
- Que el equipo este operativo 
- Que el usuario cumpla el semestre requerido
*/

/*Los parametros: Necesitamos la info de los equipos y usuarios para poder buscar los datos*/
void programarSesionUso(Equipo* equipos, int numEquipos, Usuario* usuarios, int numUsuarios){
    /*Primero pedimos el codigo del usuario, del equipo y la duracion estimada.*/
    int codigoUsuario;
    int codigoEquipo;
    int duracion;
    char fechausuario[30];
    
    cout<<"Ingrese el codigo del usuario:"<<endl;
    cin>>codigoUsuario;
    
    cout<<"Ingrese el codigo del equipo:"<<endl;
    cin>>codigoEquipo;
    
    cout<<"Ingrese la duracion:"<<endl;
    cin>>duracion;

    /*---PRIMERO-----BUSCAMOS EL USUARIO---------*/

    /*Creamos el apuntador de buscar usuario*/
    Usuario *buscarusuario=nullptr; 
        
    for(int i=0; i<numUsuarios; i++){
        /*Hacemos la busqueda con aritmetica de punteros*/
        if((usuarios+i)->codigoInst == codigoUsuario){
            /*Guardamos en la memoria dinamica a buscarusuario*/
            buscarusuario=usuarios+i;
            break;
        }
    }
        
    /*Si el usuario es inexistente*/
    if(buscarusuario==nullptr){
        cout<<"El usuario no existe :("<<endl;
        return;
    }
    
    /*--SEGUNDO---BUSCAMOS EL EQUIPO----------*/

    /*Siguiendo con la linea de busqueda, ahora buscamos el equipo :)
    practicamente un copypaste en las lineas anteriores 
    */
    
    /*Al igual que antes creamos el apuntador y lo ponemos en nullptr*/
    Equipo *buscarequipo=nullptr; 
        
    for(int i=0; i<numEquipos; i++){
            /*Hacemos la busqueda con aritmetica de punteros*/
            if((equipos+i)->codigo == codigoEquipo){
            /*Guardamos en la memoria dinamica a buscarequipo*/
            buscarequipo=equipos+i; 
            break;
        }
    }

        if(buscarequipo==nullptr){
            cout<<"El equipo no existe"<<endl;
            return;
        }

        /*Como ultimo hacemos una verificación de si esta operativo o No*

        /*Para esto lo más sencillo es hacer un strcmp para ver si 
        esta operativo o no (como en la funcion pasada)*/

    if(strcmp(buscarequipo->operativo, "operativo") != 0 && strcmp(buscarequipo->operativo, "operativa") != 0) {
            cout << "El equipo no esta operativo :(" << endl; 
            return; 
    }
    else{
        cout<<"El equipo esta operativo y listo para su uso!"<<endl;
    }
    /*Listo, ahora falta verificar que el usuario cumpla con el semestre minimo*/
    /*La logica acá: 
    Si comparamos el semestre en la posicion obtenida del usuario con la del equipo, con 
    el semestre min sacado de la posicion del equipo, creo que tendriamos si si o si no cumple
    */
   
    if((buscarusuario)->semestre < (buscarequipo)->semestreMin){
        cout<<"No cumple con el minimo de semestres"<<endl;
        return; 
    }
    else{
        cout<<"El usuario cumple con el minimo de semestres :D"<<endl;
    }
    
    /*Ahora pedimos la fecha de la sesión*/
    cout<<"Ingrese la fecha de la sesion: "<<endl; 
    cin.ignore();
    cin.getline(fechausuario,30);

    /*Ahora la parte mas enredada:
    calculamos el codigo de la sesion
    Como?
    1. Abrimos para lectura el archivo

    2. Con seekg movemos hasta el final del archivo

    3. Y con tellg medimos los bytes del inicio al fin del archivo

    4. con sizeof de una sola sesion dividimos y nos da el 
    # de sesiones guardadas

    5. creamos una nueva sesion con el apuntador 
    y asignamos y rellenamos
    */
    ifstream archivo("sesiones.bin", ios::in | ios::binary);
    int cantidadSesiones = 0;
    if (archivo.is_open()) {
        archivo.seekg(0, ios::end);
        cantidadSesiones = archivo.tellg() / sizeof(SesionUso);
        archivo.close();
    }

    /*Creamos una nueva sesión con el apuntador*/
    SesionUso *nuevaSesion= new SesionUso; 
    
    /*Rellenamos*/
    /*Justo lo primero es el codigo unico*/
    nuevaSesion->codigoSesion= cantidadSesiones+1;
    nuevaSesion->codigoUsuario= buscarusuario->codigoInst;
    nuevaSesion->codigoEquipo= buscarequipo->codigo;
    nuevaSesion->duracion= duracion;
    strcpy(nuevaSesion->fecha, fechausuario);
    strcpy(nuevaSesion->observaciones, "Sin observaciones");
    nuevaSesion->penalizacion = 0;
    
    /*Ahora si nos falta lo ultimo, y es guardar todo en un archivo binario 
    entonces abrimos uno */
    ofstream archivoSalida("sesiones.bin", ios::binary | ios::app);
     archivoSalida.write(reinterpret_cast<char*>(nuevaSesion), sizeof(SesionUso));
     archivoSalida.close();
    
     /*Hacemos delete de nuevasesion*/
     delete nuevaSesion;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Quinta Función: Registrar cierre de Sesión
¿Que debe hacer esta funcion?
Acceder al archivo binario de antes
Mediante el codigo de la sesion que se quiere cerrar
Calcular penalizaciones por cada hora que se demoro
*/
void registrarCierreSesion(Equipo* equipos, int numEquipos){
    /*Primero pedimos el codigo de la sesion*/
    int codigoSesion; 
    cout<<"Ingrese el codigo de la sesion que quiere cerrar:"<<endl;
    cin>>codigoSesion; 
    cin.ignore();
    
    /*Abrimos el archivo*/
    fstream archivo("sesiones.bin", ios::binary | ios::in | ios::out);
    /*Con la logica anterior buscamos el numero de sesiones (tamaño completo/tamaño una sesion) */
    archivo.seekg(0, ios::end);
    int cantidadSesiones= archivo.tellg()/sizeof(SesionUso);
    /*Tenemos que crear una variable de tipo sesion de uso para leer*/
    SesionUso sesion; 
    
    /*Y definimos una variable para ver si la encontramos o no*/
    bool encontrada=false;
    
    /*Ahora vamos a recorrer las sesiones*/
    for(int i=0; i<cantidadSesiones; i++){
        /*movemos el puntero al inicio del archivo y se va moviendo i, por cada sesion que encuentren*/
        archivo.seekg(i*sizeof(SesionUso), ios::beg); 
        /*Leemos la estructura y la metemos a la variable sesion que creamos antes*/
        archivo.read((char*)&sesion, sizeof(SesionUso));    
        /*Y vamos comparando cada sesion su codigo con el que se escribio*/
        if(sesion.codigoSesion==codigoSesion){
            cout<<"Encontramos la sesion"<<endl; 
            encontrada=true;

            /*Ahora calculamos penalizaciones y observaciones se anotan*/     
            cout<<"Escriba las observaciones:"<<endl;
            cin.getline(sesion.observaciones, 100); 

            /*para poder penalizar, primero necesitamos encontrar el equipo que vamos a analizar*/
            for(int j=0; j<numEquipos;j++){
                /*Busqueda del equipo :D*/
                if((equipos+j)->codigo==sesion.codigoEquipo){
                    /*como encontramos el equipo, ahora definimos su costoEstimado*/
                    int costo= (equipos+j)->costoEstimado; 
                    /*Y por fin podemos calcular las penalizaciones
                    Entonces: 
                    Debe,os saber si se excedieron o no, asi que preguntamos cuanto se demoraron*/

                    int duracionActual; 
                    cout<<"Cuanto tiempo duro la sesion?" <<endl;
                    cin>>duracionActual;
                    cin.ignore();
                    
                    if(duracionActual>sesion.duracion){
                        int horasAdicionales= duracionActual-sesion.duracion; 
                        sesion.penalizacion= horasAdicionales*(0.03*costo);
                    }else{
                        sesion.penalizacion=0; 
                    }
                    /*Con esto arreglamos el error donde no muestra la pregunta*/
                    archivo.clear();
                    /*Finalizamos verificando que no hayan daños para ver si cambiamos el estado*/
                    char dano; 
                    cout<<"hubo algun daño? (s o n):"<<endl;
                    cin>>dano; 
                    cin.ignore();

                    if(dano=='s' || dano=='S'){
                        /*Lo mandamos a mantenimiento para que lo arreglen*/    
                        strcpy((equipos+j)->operativo, "mantenimiento");
                        cout<<"El equipo ahora esta en mantenimiento"<<endl; 
                    }
                    break;
                }
            }
             /*Como hubieron daños en el equipo actualizamos la sesion*/
             /*Buscamos la sesion*/
            archivo.seekp(i*sizeof(SesionUso), ios::beg); 
            /*Escribimos (actualización)*/
            archivo.write((char*)&sesion, sizeof(SesionUso));
            break;
        }
    }
    
    if(!encontrada){
            cout<<"Sesion no encontrada :("<<endl;
    }
    
    /*Finalmente cerramos el archivo*/
    archivo.close();
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Sexta Función:  Generar Informe de Uso Intensivo de Equipos
¿Qué debe hacer esta función?
Por cada lab mostrar el equipo con mayor cantidad de uso

Logica a aplicar en la funcion, por cada lab registrado sumar
las horas de duracion de todas las sesiones de uso asociadas a los equipos

Y el que tenga + horas efectivamente sera el de maximo!
*/

void Uso_Intensivo(Equipo* equipos, int numEquipos){
    /*pues si no hay equipos pailas :D*/
    if(numEquipos == 0){
        cout<<"No hay equipos registrados, porfa registe equipos";
        return;
    }
    /*Abrimos el archivo binario :D*/
    ifstream archivoBin("sesiones.bin", ios::in | ios::binary);
    
    /*Si no hay sesiones en el archivo bin pailas*/
    if(!archivoBin){
        cout<<"No hay sesiones registradas, porfa registre sesiones :D";
        return;
    }

    /*Ahora miremos la cantidad de sesiones almacenadas*/
    archivoBin.seekg(0, ios::end);
    /*Al igual que en la funcion anterior mantenemos el calculo de la 
    cantidad de sesiones dividimos (Tamaño Inicio-Fin/tamaño una sesion)*/
    int cantidadSesiones = archivoBin.tellg()/sizeof(SesionUso);

    /*Aqui volvemos a ponerlo en el inicio pa poder hacer bien la funcion*/
    archivoBin.seekg(0, ios::beg);

    /*Ahora creemos un arreglo dinamico para almacenar las horas de cada equipooo*/
    /*Nota se pone el () para inicializar en 0 :D*/
    int* horasAcumuladas = new int[numEquipos]();

    /*Creamos una Variable temporal de tipo sesionUso*/
    SesionUso sesionActual;
    for(int i=0; i<cantidadSesiones; i++){
        /*La funcion de toda la vida pa leer archivos binarios*/
        archivoBin.read(reinterpret_cast<char*>(&sesionActual), sizeof(SesionUso));

        /*Ahora usaremos apuntadores auxiliares*/
        /*Uno que arranque al primer equipo y otro que apunte al ultimo*/
        
        Equipo* pEquipo = equipos;
        Equipo* ultEquipo = equipos + numEquipos;
        int indiceEquipo = 0;

        /*Mientras que el puntero no pase el ultimo buscamos*/
        while(pEquipo < ultEquipo){
            /*Aqui hacemos una compracion con el codigo del equipo
            al que se apunta con el codigo del equipo que viene del archivo
            binario*/

            if(pEquipo->codigo == sesionActual.codigoEquipo){
                /*Aqui la logica de suma es interesante:
                Cómo estoy en un apuntador de datos entero la suma se hace con la sintaxis *()
                Por otro lado vamos sumando sesion por sesion para ese equipo y tener el # de horas 
                acumuladas*/
                *(horasAcumuladas + indiceEquipo) += sesionActual.duracion;
                break;
            }
            /*Una vez terminada para ese equipo vamos al siguiente equipo 
            aumentando el pEquipo y el indice del equipo por consiguiente es el siguiente*/
            pEquipo++;
            indiceEquipo++;
        }
    }
    archivoBin.close();

    /*Ahora simplemente se genera el informe :D*/
    cout<<"Informe de Uso Intensivo de Equipos"<<endl;
    /* Primero evitamos tener labs repetidos */
    Equipo* NoRepetir = equipos;
    /*Cómo es la logica?
    Bueno entonces agarramos el puntero NoRepetir y tomamos
    su laboratorio que es el actual, luego con otro apuntador check
    verificamos todos los equipos antes de donde estamos
    parados, si encontramos el mismo lab pues entonces 
    significa ese lab ya esta.
    */
    while(NoRepetir<equipos+numEquipos){
        char* labActual = NoRepetir->laboratorio;
        /*Se verifica si este laboratorio ya se proceso*/
        bool labYa = false;
        Equipo* check = equipos;
        while(check < NoRepetir){
            /*Si el strcmp identifica que se repiten labYa pasa a ser true*/
            if(strcmp(check->laboratorio, labActual) == 0){
                labYa = true;
                break;
            }
            check++;
        }

        /*Ahora dentro de ese lab buscamos el que tenga mas horas
        
        Empezamos por ver si labYa aun es false, o sea aun no sabemos
        en ese lab cual equipo tiene un max de horas, por ende hacemos la comparación
        */
        if(!labYa){
            /*Aqui hacemos una comparación tipíca donde el equipo Max inicializado en null
            y el max de horas se empieza en -1 (imposible)*/
            Equipo* equipoMax = nullptr;
            int maxHoras = -1;
            Equipo* equipoo = equipos;
            /*Indice del equipo*/
            int idx = 0;
            while(equipoo < equipos + numEquipos){
                /*El equipo pertenece al lab? - si si entonces:
                Con el apuntador equipoo y el indice idx 
                creamos el recorrido con el while
                y con el if (strcmp) verificamos si pertene al lab actual*/
                if(strcmp(equipoo->laboratorio, labActual) == 0){
                    /*Miramos cuantas horas tiene acumuladas*/
                    int horasEquipo = *(horasAcumuladas + idx);
                    /*Y ya si son mayor que el max pues entonces queda
                    el nuevo max a este equipo*/
                    if(horasEquipo > maxHoras){
                        maxHoras = horasEquipo;
                        equipoMax = equipoo;
                    }
                }
                /*Pasamos al siguiente equipo y su siguiente hora (idx)*/
                equipoo++;
                idx++;
            }
            
            /*Y ahora finalmente imprimimosss :D*/
            cout<<"Lab: "<<labActual<<endl;
            if (equipoMax != nullptr && maxHoras>0){
                cout<<equipoMax->nombre<<endl;
                cout<<"Con: "<<maxHoras<<" Horas de uso"<<endl;
            }
            else{
                cout<<"No hay uso registrado :( "<<endl;
            }
        }
        /*Con el NoRepetir++ simplemente seguimos al siguiente laboratorio*/
        NoRepetir++;
    }
    /*Y yap liberamos memoria*/
    delete[] horasAcumuladas;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Séptima Función: Generar un Ranking de Usuarios Criticos
¿Que debe hacer esta funcion?

Calcular un indice de criticidad por usuario, definido como:
(penalizacion acumulada) / (cantidad de sesiones).
Mostrar los tres usuarios con mayor indice :O
*/

void UsuariosCriticos(Usuario* usuarios, int numUsuarios){
    /*Si no hay usuarios pues pailas*/
    if(numUsuarios == 0){
        cout<<"No hay usuarios :O"<<endl;
        return;
    }
    /*Equivalente a la función anterior, se abre el archivo binario*/
    ifstream archivoBin("sesiones.bin", ios::in | ios::binary);
    if(!archivoBin){
        cout<<"No hay registro de sesiones"<<endl;
        return;
    }
    /*Al igual que en las funciones anteriores calculamos la cantidad de sesiones*/
    archivoBin.seekg(0, ios::end);
    int cantidadSesiones = archivoBin.tellg() / sizeof(SesionUso);

    /*Volvemos al inicio para desarrollar la función apropiadamente*/
    archivoBin.seekg(0, ios::beg);

    /*Ahora creamos arreglos dinamicos 
    para acumular penalizaciones y sesiones por usuario
    Recordar: () se pone para inicializar en 0 el arreglo*/
    float* totalPenalizaciones = new float[numUsuarios]();
    int* totalSesiones = new int[numUsuarios]();

    /*
    Ahora leemos el archivo binario sesion x sesion 
    igual que antes con una variable temporal como antes
    */

    SesionUso sesionActual;
    for (int i=0; i<cantidadSesiones; i++){
        /*Funcion de lectura del archivo*/
        archivoBin.read(reinterpret_cast<char*>(&sesionActual), sizeof(SesionUso));

        /*Puntero auxiliar del primer usuario*/
        Usuario* PrimerUsuario = usuarios;
        /*Contador del # del usuario*/
        int numeroUsuario = 0;
        while(PrimerUsuario<usuarios + numUsuarios){
            /*Mientras que el primer usuario no exceda todos los usuarios y el 
            codigo coincida con el de la sesion actual se hace:
            La suma de penalizaciones de esa sesion a ese usuario
            Le suma una sesion mas a ese usuario
            */
            if(PrimerUsuario->codigoInst == sesionActual.codigoUsuario){
                *(totalPenalizaciones + numeroUsuario) += sesionActual.penalizacion;
                *(totalSesiones + numeroUsuario) += 1;
                break;
            }
            /*Si el codigo no coincide vamos al siguiente usuario y avanzamos el indice*/
            PrimerUsuario++;
            numeroUsuario++;
        }
    }
    archivoBin.close();

    /*Ahora vamos con el calculo de criticicidad!*/

    /*Creamos un arreglo dinamico para el indice de criticidad */
    float* indiceCriticicidad = new float[numUsuarios]();
    Usuario** rankingUsuarios = new Usuario*[numUsuarios]();
    /*Ahora para simplificar la logica y el ranking de usuarios
    usamos un doble puntero para usuario donde:
    cada casilla guarda la direccion de memoria del arreglo original
    y cuando se ordenen los numeros de criticicidad no se mezcle
    */

    /*Con el puntero pUsuario y el indice recorremos usuario por usuario*/
    Usuario* pUsuario = usuarios;
    int indiceUsuario = 0;

    /*Ahora con el while calculamos primero las penalizaciones
    y el # de sesiones y lo calculamos mientras se guarda en la 
    casilla de indice de criticicidad*/
    while(pUsuario < usuarios + numUsuarios){
        float penalizaciones = *(totalPenalizaciones + indiceUsuario);
        int sesiones = *(totalSesiones + indiceUsuario);

        if(sesiones > 0){
            /*Aqui es el calculo del indice de criticicad*/
            *(indiceCriticicidad + indiceUsuario) = penalizaciones/sesiones;
        }
        else{
            *(indiceCriticicidad + indiceUsuario) = 0.0;
        }
    /*Ahora guardamos la dirección exacta del usuario (aun no lo ordenamos)*/
    *(rankingUsuarios + indiceUsuario) = pUsuario;

    /*Aumentamos para ir al siguiente usuario junto a su indice*/
    pUsuario++;
    indiceUsuario++;
}
    /*Finalmente hacemos el ordenamiento de los usuarios para poder tener el ranking de los 3*/
    /*Muchachos aqui voy a utilizar el metodo de ordenamiento burbuja*/
    for (int i=0; i<numUsuarios - 1; i++){
        for (int j=i+1; j<numUsuarios; j++){
        /*Aqui es el mismo metodo burbuja si no que accedemos a la dirección de memoria*/
        /*Si el indice de cirticidad siguiente es mayor...*/
        if (*(indiceCriticicidad + j) > *(indiceCriticicidad + i)){
            
            /*PRIMER INTERCAMBIO - DE LOS VALORES DE CRITICIDAD*/

            /*Creamos una variable temporal para el indice de criticidad*/
            /* Y hacemos un intercambio 
            I se guarda en la variable temporal
            J a la posición I 
            Valor guardado a la J*/

            float tempIndice = *(indiceCriticicidad + i);
            *(indiceCriticicidad + i) = *(indiceCriticicidad + j);
            *(indiceCriticicidad + j) = tempIndice;

            /*SEGUNDO INTERCAMBIO - DE LOS USUARIOS*/
            /*Es exactamente el mismo intercambio pero con los usuarios*/
            Usuario* tempUsuario = *(rankingUsuarios + i);
            *(rankingUsuarios + i) = *(rankingUsuarios + j);
            *(rankingUsuarios + j) = tempUsuario;
        }
    }
}
/*Finalmente imprimimos el ranking*/
cout<<"Ranking de Usuarios criticos!"<<endl;
int puestos = 3;
if(numUsuarios < 3){
   puestos=numUsuarios; 
}

/*Volvemos a usar el doble apuntador que ya quedo ordenado*/
Usuario** rankingfinal = rankingUsuarios;
float* rankingIndice = indiceCriticicidad;
int listones = 0;

while(listones < puestos){
    if(*rankingIndice<=0){
        if(listones == 0){
            cout<<"No hay usuarios que tengan penalizaciones! :O"<<endl;
        }
        break;
    }
    /*Accedemos a la informacion y vamos leyendo en el orden que ya quedo ordenado*/
    cout<<"Puesto"<<listones+1<<endl;
    cout<<"Codigo: "<<(*rankingfinal)->codigoInst<<endl;
    cout<<"Nombre:"<<(*rankingfinal)->nombrest<<endl;
    cout<<"Carrera:"<<(*rankingfinal)->carrera<<endl;
    cout<<"Indice Criticicidad:"<<*rankingIndice<<endl;

    /*Al final aumentamos para ir al siguiente usuario del ranking :D*/
    rankingfinal++;
    rankingIndice++;
    listones++;
}
/*Finalmente borramos memoria y queda todo perfect!*/
delete[] totalPenalizaciones;
delete[] totalSesiones;
delete[] indiceCriticicidad;
delete[] rankingUsuarios;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Función 8: Registrar nuevo equipo
¿Qué debe hacer esta función?
Registrar nuevos Equipos :D
*/
void registrarNuevoEquipo(Equipo *equipos, int &numEquipos){
    /*Primero abrimos el archivo */
    ofstream archivo("equipos.txt", ios::app);
    if (!archivo){
        cout<<"No se pudo abrir el archivo equipos.txt :("<<endl;
        return;
    }

    int codigo, costo, semestre;
    char nombre[50], lab[50], tipo[50], operativo[50], desc[100];

    /*
    PRIMERO: Pedimos la Info
    Hacemos el cin.ignore para limpiar el bufer
    y que funcione el cin.getline
    */
    cout<<"Ingrese codigo del equipo: "<<endl;
    cin>>codigo;
    cin.ignore(); 

    cout<<"Ingrese nombre del equipo: "<<endl;
    cin.getline(nombre, 50);

    cout<<"Ingrese laboratorio: "<<endl;
    cin.getline(lab, 50);

    cout<<"Ingrese tipo: "<<endl;
    cin.getline(tipo, 50);

    cout<<"Ingrese costo estimado: "<<endl;
    cin>>costo;
    cin.ignore(); 

    cout<<"Ingrese estado operativo, por ejemplo: operativo/mantenimiento "<<endl;
    cin.getline(operativo, 50);

    cout<<"Ingrese semestre minimo: "<<endl;
    cin>>semestre;
    cin.ignore(); 

    cout<<"Ingrese descripcion tecnica: "<<endl;
    cin.getline(desc, 100);
    
    /*
    - Ahora Generamos y escribimos la información 
    - También es importante que pongamos el salto de linea al final
    */

    archivo<<"\n"<<codigo<<"*"<<nombre<<"*"<<lab<<"*"<<tipo<<"*"<<costo<<"*"<<operativo<<"*"<<semestre<<"*"<<desc<<"\n";

    archivo.close();
    cout<<"Equipo registrado exitosamente! :D"<<endl;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Función 9: Registrar un nuevo Usuario
¿Que debe hacer esta función?
Registrar nuevos usuarios :)
*/

void registrarNuevoUsuario(Usuario *usuarios, int &numUsuarios){
    ofstream archivo("usuarios.txt", ios::app);
    if (!archivo){
        cout<<"No se pudo abrir el archivo usuarios.txt :("<<endl;
        return;
    }
    /*Misma estructura que la logica anterior*/

    int codigo, semestre;
    char nombre[50], carrera[50];

    cout<<"Ingrese codigo institucional del usuario:"<<endl;
    cin>>codigo;
    cin.ignore(); 

    cout<<"Ingrese nombre del usuario: "<<endl;
    cin.getline(nombre, 50);

    cout<<"Ingrese carrera: "<<endl;
    cin.getline(carrera, 50);

    cout<<"Ingrese semestre: " <<endl;
    cin>>semestre;

    archivo<<"\n"<<codigo<<"*"<<nombre<<"*"<<carrera<<"*"<<semestre<<"\n";

    archivo.close();
    cout << "Usuario registrado exitosamente! :D" << endl;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main(){
    Equipo *equipos = nullptr;
    Usuario *usuarios= nullptr; 
    int numEquipos = 0;
    int numUsuarios = 0; 

    char opcion;
    cout<<"Bienvenido al sistema de gestion de equipos de laboratorio"<<endl;

    do{
    cout<<"1. Cargar equipos desde archivo"<<endl;
    cout<<"2. Cargar Usuarios desde archivo"<<endl;
    cout<<"3. Consultar Estado Operativo Lab"<<endl;
    cout<<"4. Programar una sesion de uso de Equipo"<<endl;
    cout<<"5. Registrar cierre de sesion de un Equipo"<<endl;
    cout<<"6. Generar Informe de uso Intensivo"<<endl;
    cout<<"7. Generar Ranking de Usuarios Criticos"<<endl;
    cout<<"8. Cargar nuevo equipo"<<endl;
    cout<<"9. Cargar nuevo usuario"<<endl;
    cout<<"0. Salir :D"<<endl;

    cout<<"Inserte la opcion deseada"<<endl;
    cin>>opcion;
    switch(opcion){
            case '1':
             if(equipos != nullptr){
             cout<<"Los equipos ya fueron cargados."<<endl;
             }
            else{
              cin.ignore();
              equipos = new Equipo[50]; 
              numEquipos = cargarEquipos(equipos);
              cout<<"Se han cargado "<< numEquipos <<" equipos exitosamente."<<endl;
    }
    break;
            case '2': 
                /*Asignamos memoria dinámica previa para los usuarios (por ejemplo, max 50 usuarios)*/ 
                usuarios = new Usuario[50];
                numUsuarios = cargarUsuarios(usuarios);
                cout<<"Se han cargado "<< numUsuarios <<" usuarios exitosamente."<<endl;
                break;
            case '3': 
                if (numEquipos == 0){
                    cout<<"Primero debes cargar los equipos (Opcion 1)." << endl;
                } else{
                    consultarEstadoOperativo(equipos, numEquipos);
                }
                break;
            case '4': 
                if (numEquipos == 0 || numUsuarios == 0) {
                    cout << "Debes cargar primero los equipos y los usuarios (Opciones 1 y 2)."<<endl;
                } else {
                    programarSesionUso(equipos, numEquipos, usuarios, numUsuarios);
                }
                break;
            case '5': 
                if (numEquipos == 0){
                    cout << "Primero debes cargar los equipos (Opcion 1)."<<endl;
                } else {
                    registrarCierreSesion(equipos, numEquipos);
                }
                break;
            case '6': 
                Uso_Intensivo(equipos, numEquipos);
                break;
            case '7': 
                UsuariosCriticos(usuarios, numUsuarios);
                break;
            case '8': 
                registrarNuevoEquipo(equipos, numEquipos);
                break;
            case '9': 
                registrarNuevoUsuario(usuarios, numUsuarios);
                break;
            case '0':
                cout <<"Saliendo del sistema. Hasta luego! :D"<<endl;
                break;
            default: 
                cout<<"Opcion invalida. Intente de nuevo."<<endl;
                break;  
            } 
} while(opcion != '0');
   
    
   for(int i=0; i<numEquipos; i++){
    delete[] (equipos+i)->nombre;
    delete[] (equipos+i)->laboratorio;
    delete[] (equipos+i)->tipo;
    delete[] (equipos+i)->operativo;
    delete[] (equipos+i)->descripcionTecnica;
   }

    delete[] equipos;

    for(int i=0; i<numUsuarios; i++){
    delete[] (usuarios+i)->nombrest;
    delete[] (usuarios+i)->carrera;
   }

   delete[] usuarios;

   return 0;

}

