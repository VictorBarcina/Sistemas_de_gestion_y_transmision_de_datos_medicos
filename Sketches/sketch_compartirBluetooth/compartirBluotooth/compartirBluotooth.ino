//Autor: Víctor Barcina Muñoz
//Se importa la librería para la comunicación SPI
#include <SPI.h> 
//Se importa la librería para trabajar con tarjetas SD
#include <SD.h>
// Incluimos la librería SoftwareSerial  
#include <SoftwareSerial.h>   
// Definimos los pines TX y RX del Arduino conectados al Bluetooth
SoftwareSerial miBT(8, 9);    
// inicializamos la bandera para determinar si el contenido se ha mostrado o no y que no se duplique
bool contenidoMostrado= false; 

void mostrarContenido(const char* directorio_raiz, int nivel = 0) {
   /* 
   Esta función muestra el contenido de la tarjeta SD de manera estructurada a través del terminal Bluetooth.
   Permite conocer al usuario la estructura de carpetas, subcarpetas y archivos que hay en la tarjeta SD. 
   Parámetros: 
   --------------------
   directorio_raiz(const char*): Consiste en la ruta del directorio raíz de la tarjeta SD que se desea explorar
   nivel(int): Nivel de jerarquía de las carpetas y archivos.

   Return
   --------------------
   Esta función devuelve la estructura de carpetas y archivos de la tarjeta SD
  */
  //Abrimos el directorio raiz y lo guardamos en la variable carpeta_raiz
  File carpeta_raiz = SD.open(directorio_raiz);
  // En caso de que no se pueda leer el directorio raiz, muestra un error y vuelve al inicio
  if (!carpeta_raiz) {
    miBT.println("Error al abrir el directorio");
    return;
  }

  //recorremos todas las carpetas y archivos que hay dentro de la raíz de la SD
  while (true) {
    File archivo = carpeta_raiz.openNextFile();
    // si no  se detectan más archivos dentro de la carpeta detiene el proceso 
    if (!archivo) {
      break;
    }
    //creamos un bucle para que cree espacios en blanco en función de la jerarquía de las carpetas que hay en la tarjeta SD
    for (int i = 0; i < nivel; i++) {
      miBT.print("  ");
    }
    //si el archivo es una carpeta se muestra el nombre y se vuelve a llamar a la función para que muestre el contenido que tiene 
    if (archivo.isDirectory()) {
      miBT.print("Carpeta: ");
      miBT.println(archivo.name());
      
      //Creamos una variable denominada rutaCompleta que concatene la ruta del directorio raiz con "/" y el nombre del archivo para obtener la ruta completa de la carpeta actual
      String rutaCompleta = String(directorio_raiz) + "/" + archivo.name();
      // Para explorar y mostrar el contenido de la carpeta actual se llama recursivamente a la función. Le pasamos la ruta completa del archivo convertido en una cadena de caracteres y aumentando el nivel para que aparezca correctamente estructurado
      mostrarContenido(rutaCompleta.c_str(), nivel + 1);
    } else {
      miBT.print("Archivo: ");
      miBT.println(archivo.name());
    }
    //cerramos el archivo actual
    archivo.close();
  }
  //se cierra el directorio raiz
  carpeta_raiz.close();
}

void setup() {
  SPI.begin();  // Inicializamos la comunicación SPI
  SD.begin(4);  // Inicializamos la tarjeta SD en el pin 4
  miBT.begin(9600);  // Inicializamos el puerto serie BT que hemos creado
  //imprimimos diferentes mensajes por el terminal del bluetooth
  miBT.println("HOLA"); 
  miBT.println("Las carpetas y archivos que hay en el directorio de la tarjeta SD son:");
  Serial.begin(9600);  // Inicializamos la comunicación en serie
  contenidoMostrado = false; //reiniciamos la bandera a false
}

 void loop() {
  if (miBT.available()) {
    Serial.write(miBT.read());
  }
  if (Serial.available()) {
    miBT.write(Serial.read());
  }
  // Verificamos si el contenido ya ha sido mostrado en el setup()
  // si la bandera es false se llama a la función para mostrar el contenido
  if (!contenidoMostrado) {
    mostrarContenido("/");// Llamamos a la función para mostrar el contenido del directorio raíz de la tarjeta SD
    contenidoMostrado = true; // Marcamos que el contenido ha sido mostrado actualizando la bandera
  }
}
