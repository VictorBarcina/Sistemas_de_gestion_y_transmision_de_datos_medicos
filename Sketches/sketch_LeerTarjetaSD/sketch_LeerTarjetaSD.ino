//Autor: Víctor Barcina Muñoz
//Se importa la biblioteca para la comunicación SPI
#include <SPI.h> 
//Se importa la biblioteca para trabajar con tarjetas SD
#include <SD.h>
//Definimos una constante denominada Shield con el pin 4 para realizar la comunicación con la placa arduino 
const int Shield = 4;

void mostrarContenido(const char* directorio_raiz, int nivel = 0) {
  /* 
   Esta función muestra el contenido de la tarjeta SD de manera estructurada. Permite conocer al usuario
   la estructura de carpetas, subcarpetas y archivos que hay en la tarjeta SD. 
   Parámetros: 
   --------------------
   directorio_raiz(const char*): Consiste en la ruta del directorio raíz de la tarjeta SD que se desea explorar
   nivel(int): Nivel de jerarquía de las carpetas y archivos.

   Return
   --------------------
   Esta función devuelve la estructura de carpetas y archivos de la tarjeta SD.
*/
  //Se abre el directorio raiz para ver lo que contiene dentro
  File carpeta_raiz = SD.open(directorio_raiz);
  //en caso de que no se pueda leer el directorio raiz nos indicaría error y volvería al inicio
  if (!carpeta_raiz) {
    Serial.println("Error al abrir el directorio");
    return;
  }
  //recorremos todas las carpetas y archivos que hay dentro de la raíz de la SD
  while (true) {
    File archivo = carpeta_raiz.openNextFile();
    // si no  se detectan más archivos dentro de la carpeta se detiene el proceso 
    if (!archivo) {
      break;
    }
    //creamos un bucle para crear espacios en blanco en función de la jerarquía de las carpetas que hay en la tarjeta SD
    for (int i = 0; i < nivel; i++) {
      Serial.print("  ");
    }
    //si el archivo es una carpeta se muestra el nombre y se vuelve a llamar a la función para que muestre el contenido que tiene 
    if (archivo.isDirectory()) {
      Serial.print("Carpeta: ");
      
      Serial.println(archivo.name());
      
      //Creamos una variable denominada rutaCompleta que concatene la ruta del directorio raíz con "/" y el nombre del archivo para obtener la ruta completa de la carpeta actual

      String rutaCompleta = String(directorio_raiz) + "/" + archivo.name();
      // Para explorar y mostrar el contenido de la carpeta actual se llama recursivamente a la función. Le pasamos la ruta completa del archivo convertido en una cadena de caracteres y aumentando el nivel para que aparezca correctamente estructurado
      mostrarContenido(rutaCompleta.c_str(), nivel + 1);
    } else {
      Serial.print("Archivo: ");
      Serial.println(archivo.name());
    }
    //cerramos el archivo actual
    archivo.close();
  }
  //se cierra el directorio raiz
  carpeta_raiz.close();
}

void setup() {
  //Se inicializa la comunicación en serie
  Serial.begin(9600);
  //Si no se puede inicializar la tarjeta SD imprimimos error por pantalla

  if (!SD.begin(Shield)) {
    Serial.println("Error al iniciar la tarjeta SD");
    return;
  }
  Serial.println("Tarjeta SD inicializada correctamente");
  //Indicamos la ruta del directorio raiz de la tarjeta SD para emplearlo en otras funciones.
  mostrarContenido("/");
}

void loop() {
  // Para mostrar por el monitor serial las carpetas y archivos que hay en la tarjeta SD no es necesario incluir nada aquí
}
