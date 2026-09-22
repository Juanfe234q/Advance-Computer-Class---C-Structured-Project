# Advance-Computer-Class---C-Structured-Project
Este repositorio da lugar al Proyecto de Programación Avanzada en C++ para la materia de Programación Avanzada 

- Este es el primer proyecto para la primera parte del curso donde apoyados en conceptos tales cómo la memoria dinámica, apuntadores, archivos binarios, de texto, entre otras temáticas relevantes a la clase de Programación Avanzada.
  
- A continuación exponemos nuestro proyecto, una explicación breve de cada una de las funciones y su lógica estructural, además de ejemplos de funcionamiento correcto del codigo.

# Nombre de Nuestro Proyecto: LabManager :D
# Autores:
* **Maria Lucía Ortega Figueroa** 
* **Santiago Moreno** 
* **Juan Felipe Quintero Vargas**

# 1. Estructuras Principales: 
- Equipo --> Guarda la info técnica de cada máquina es decir: El código, nombre, laboratorio, tipo, costo estimado, estado operativo, semestre mínimo y descripción técnica.
- Usuario --> Almacena los datos de los estudiantes es decir:  El código institucional, nombre, carrera y semestre.
- Sesión de uso --> Lleva el control de quién usó qué, cuándo, cuánto duró, las observaciones y si hubo o no alguna penalización

| Estructura | Código en C++ | Descripción |
| :--- | :--- | :--- |
| **`Equipo`** | `struct Equipo {`<br>`    int codigo;`<br>`    char *nombre;`<br>`    char *laboratorio;`<br>`    char *tipo;`<br>`    int costoEstimado;`<br>`    char *operativo;`<br>`    int semestreMin;`<br>`    char *descripcionTecnica;`<br>`};` | Utilizamos Apuntadores y Memoria Dinámica para no usar arreglos de tamaño fijo (Que era un condicional del Proyecto) |
| **`Usuario`** | `struct Usuario {`<br>`   int codigoInst;`<br>`   char *nombrest;`<br>`   char *carrera;`<br>`   int semestre;`<br>`};` | Utilizamos Apuntadores y Memoria Dinámica para no usar arreglos de tamaño fijo (Que era un condicional del Proyecto) |
| **`SesionUso`** | `struct SesionUso {`<br>`    int codigoSesion;`<br>`    int codigoEquipo;`<br>`    int codigoUsuario;`<br>`    char fecha[30];`<br>`    int duracion;`<br>`    char observaciones[100];`<br>`    float penalizacion;`<br>`};` | La estructura que usamos para llevar el control de los prestamos en el archivo binario |

# 2. Funcion 1: Cargar Equipos desde el Archivo
- Nota: Aqui pedimos el nombre del archivo 
```text
  [ Inicio: cargarEquipos ]
             │
             ▼
  ┌──────────────────────┐
  │ ¿Existe equipos.txt? │ ──( No )──> [ Retornar 0 ]
  └──────────────────────┘
             │ ( Sí )
             ▼
  [ Leer archivo línea por línea ]
             │
             ▼
  [ Copiar línea (strcpy) y contar campos con strtok ]
             │
             ▼
  ┌──────────────────────┐
  │ ¿Son 8 campos exactos?│ ──( No )──> [ Error de formato y saltar (continue) ]
  └──────────────────────┘
             │ ( Sí )
             ▼
  [ Usamos aritmética de punteros: (equipos + numEquipos) ]
             │
             ▼
  [ atoi() para números y new char[...] con strlen()+1 para textos ]
             │
             ▼
  [ numEquipos++ y repetir hasta acabar el archivo ]
             │
             ▼
  [ Cerrar archivo y retornar numEquipos total :D ]
```
# 2. Funcion 2: Cargar Usuarios desde el Archivo
```text
[ Inicio: consultarEstadoOperativo ]
             │
             ▼
  [ Pedir el nombre del laboratorio a buscar (cin.getline) ]
             │
             ▼
  [ Recorrer el arreglo dinámico de equipos con un ciclo for ]
             │
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El laboratorio del equipo coincide (strcmp)?│ ──( No )──> [ Siguiente equipo ]
  └──────────────────────────────────────────────┘
             │ ( Sí )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El estado operativo es "operativo"?         │ ──( Sí )──> [ Imprimir info completa de Equipo Operativo = 0]
  └──────────────────────────────────────────────┘
             │ ( No )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El estado operativo es "mantenimiento"?     │ ──( Sí )──> [ Imprimir info de Equipo en Mantenimiento = 0]
  └──────────────────────────────────────────────┘
             │ ( No )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El semestre mínimo requerido es mayor a 1?  │ ──( Sí )──> [ Advertir equipo con restricciones de semestre ]
  └──────────────────────────────────────────────┘
             │
             ▼
  [ Terminar recorrido del arreglo y mostrar resultados :D ]
```
# 2. Funcion 3: Consultar Estado Operativo :D
```text
[ Inicio: consultarEstadoOperativo ]
             │
             ▼
  [ Pedir el nombre del laboratorio a buscar (cin.getline) ]
             │
             ▼
  [ Recorrer el arreglo dinámico de equipos con un ciclo for ]
             │
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El laboratorio del equipo coincide (strcmp)?│ ──( No )──> [ Siguiente equipo ]
  └──────────────────────────────────────────────┘
             │ ( Sí )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El estado operativo es "operativo"?         │ ──( Sí )──> [ Imprimir info completa de Equipo Operativo ]
  └──────────────────────────────────────────────┘
             │ ( No )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El estado operativo es "mantenimiento"?     │ ──( Sí )──> [ Imprimir info de Equipo en Mantenimiento ]
  └──────────────────────────────────────────────┘
             │ ( No )
             ▼
  ┌──────────────────────────────────────────────┐
  │ ¿El semestre mínimo requerido es mayor a 1?  │ ──( Sí )──> [ Advertir equipo con restricciones de semestre ]
  └──────────────────────────────────────────────┘
             │
             ▼
  [ Terminar recorrido del arreglo y mostrar resultados :D ]
```
# 2. Funcion 4: Programar una Sesión de Uso 
```text
[ Inicio: programarSesionUso ]
             │
             ▼
  [ Pedir por consola: código de usuario, código de equipo y duración ]
             │
             ▼
  [ Buscar al usuario en el arreglo usando el apuntador buscarusuario ]
             │
             ▼
  ┌──────────────────────────────┐
  │ ¿El usuario existe (!= nullptr)?│ ──( No )──> [ Imprimir "El usuario no existe" y retornar :( ]
  └──────────────────────────────┘
             │ ( Sí )
             ▼
  [ Buscar el equipo en el arreglo usando el apuntador buscarequipo ]
             │
             ▼
  ┌──────────────────────────────┐
  │ ¿El equipo existe (!= nullptr)?│ ──( Si No )──> [ Imprimir "El equipo no existe" y retornar ]
  └──────────────────────────────┘
             │ ( Sí )
             ▼
  ┌────────────────────────────────────────────────────────┐
  │ ¿El equipo está operativo (strcmp con "operativo" == 0)?│ ──( Si No )──> [ Imprimir "El equipo no está operativo" y retornar ]
  └──────────────────────────────────────────────┘
             │ ( Sí )
             ▼
  ┌────────────────────────────────────────────────────────┐
  │ ¿El semestre del usuario >= semestre mínimo del equipo?│ ──( Si No )──> [ Imprimir "No cumple con el mínimo de semestres" y retornar ]
  └──────────────────────────────────────────────┘
             │ ( Sí )
             ▼
  [ Pedir la fecha de la sesión por consola (cin.getline) ]
             │
             ▼
  [ Calcular el código de sesión abriendo "sesiones.bin", moviendo seekg al final y dividiendo entre sizeof(SesionUso) ]
             │
             ▼
  [ Crear una nueva sesión con memoria dinámica (new SesionUso) y rellenarla ]
             │
             ▼
  [ Guardar la sesión al final del archivo binario (write) y liberar memoria (delete) :D ]
```
# 2. Funcion5: Cerrar una Sesión de Uso :O
```text
[ Inicio: registrarCierreSesion ]
             │
             ▼
  [ Pedir por consola el código de la sesión que se quiere cerrar ]
             │
             ▼
  [ Abrir "sesiones.bin" en modo binario (in, out, binary) ]
             │
             ▼
  [ Calcular total de sesiones midiendo bytes con seekg al final / sizeof(SesionUso) ]
             │
             ▼
  [ Recorrer las sesiones con un ciclo for y leer cada una con archivo.read() ]
             │
             ▼
  ┌──────────────────────────────┐
  │ ¿El código de sesión coincide?│ ──( No )──> [ Continuar buscando / Si no existe, mostrar "No encontrada" ]
  └──────────────────────────────┘
             │ ( Sí )
             ▼
  [ Pedir por consola las observaciones y la duración real de la sesión ]
             │
             ▼
  [ Buscar el equipo asociado en el arreglo para obtener su costoEstimado ]
             │
             ▼
  ┌────────────────────────────────────────────────────────┐
  │ ¿Duración real > Duración programada (horas extras)?   │
  └────────────────────────────────────────────────────────┘
         │ ( Sí )                                      │ ( No )
         ▼                                             ▼
  [ Calcular penalización:                     [ Penalización = 0 ]
    horasAdicionales * (0.03 * costo) ]                │
         └──────────────────────┬──────────────────────┘
                                │
                                ▼
  ┌────────────────────────────────────────────────────────┐
  │ ¿Hubo algún daño en el equipo? (Respuesta: s o n)      │
  └────────────────────────────────────────────────────────┘
         │ ( Sí )                                      │ ( No )
         ▼                                             ▼
  [ Cambiar estado operativo a "mantenimiento" ]       [ Mantener estado actual ]
         └──────────────────────┬──────────────────────┘
                                │
                                ▼
  [ Posicionar puntero de archivo con seekg() y sobrescribir la sesión actualizada con write() ]
             │
             ▼
  [ Cerrar archivo binario y finalizar con éxito :D ]
```
# 2. Funcion 6: Uso Intensivo :O
```text
[ Inicio: Uso_Intensivo ]
             │
             ▼
  ┌──────────────────────────────┐
  │ ¿Hay equipos y sesiones?     │ ──( No )──> [ Avisar que no hay registros y retornar :D ]
  └──────────────────────────────┘
             │ ( Sí )
             ▼
  [ Calcular total de sesiones midiendo bytes del archivo binario ]
             │
             ▼
  [ Crear arreglo dinámico de horas acumuladas inicializado en 0: new int[numEquipos]() ]
             │
             ▼
  [ Recorrer cada sesión del archivo binario con un ciclo for y archivoBin.read() ]
             │
             ▼
  [ Usar punteros auxiliares (pEquipo, ultEquipo) para buscar a qué equipo pertenece la sesión ]
             │
             ▼
  [ Sumar la duración de la sesión al acumulador usando aritmética de punteros: *(horasAcumuladas + indice) += duracion ]
             │
             ▼
  [ Cerrar archivo binario y filtrar laboratorios únicos para evitar repetir informes ]
             │
             ▼
  [ Por cada laboratorio único, recorrer sus equipos y buscar el que tenga el maxHoras ]
             │
             ▼
  [ Imprimir el equipo ganador con su total de horas y liberar memoria con delete[] :D ]
  ```
# 2. Funcion 7: Usuarios Criticos (Generamos el top 3)
```text
[ Inicio: UsuariosCriticos ]
             │
             ▼
  ┌──────────────────────────────┐
  │ ¿Hay usuarios registrados?   │ ──( No )──> [ Avisar que no hay usuarios y retornar :D ]
  └──────────────────────────────┘
             │ ( Sí )
             ▼
  [ Abrir "sesiones.bin" y calcular la cantidad total de sesiones ]
             │
             ▼
  [ Creamos arreglos dinámicos auxiliares para penalizaciones y total de sesiones por usuario (inicializados en 0) ]
             │
             ▼
  [ Leer cada sesión del archivo binario y acumular penalizaciones/sesiones al usuario correspondiente usando punteros ]
             │
             ▼
  [ Cerrar archivo binario ]
             │
             ▼
  [ Crear un arreglo de dobles punteros (Usuario**) para el ranking y calcular el índice de criticidad: penalizaciones / sesiones ]
             │
             ▼
  [ Aplicamos el método de ordenamiento de burbuja sobre los índices y las direcciones de los usuarios ]
             │
             ▼
  [ Determinar cuántos puestos mostrar (máximo 3 o los que haya si no son 3) ]
             │
             ▼
  [ Imprimir el ranking final de usuarios críticos y liberar todos los arreglos dinámicos con delete[] :D ]
```
# 2. Main: Logica Básica.
- El main lo desarrollamos implementando en un menu switch (Ante un do-while) donde hacemos en bucle hasta que el usuario lo desee la implementación del codigo.

# 3. EJEMPLOS DE IMPLEMENTACIÓN DEL CODIGO: (TERMINAL)





# GRACIAS!
<img src="https://github.com/user-attachments/assets/982b502a-97bb-4725-ae98-bffc39ae787b" width="290" style="height: auto;">
<img src= "https://github.com/user-attachments/assets/87aa3c95-f7cb-4e9b-86ec-b595b16fa4cc" width="290" style="height: auto;">

Att: Malu, Santi y Juanfe





