//Autor: Víctor Barcina Muñoz
//añadimos la librería SPI
#include <SPI.h>
//Añadimos la librería SdFat
#include <SdFat.h>
//añadimos la librería SoftwareSerial
#include <SoftwareSerial.h>
//Inicializamos los pines TX y RX del Bluetooth
SoftwareSerial miBT(8, 9);
//Creamos un objeto SD
SdFat SD;

void setup() {
  miBT.begin(9600);//inicializamos la comunicación con el bluetooth
  Serial.begin(9600);//inicializamos la comunicación con el serial

  while (!Serial) {
    ; // Esperar a que se establezca la comunicación serial
  }
  //Inicializamos la tarjeta en el pin 4, y si no es exitosa, imprimimos error
  if (!SD.begin(4)) {
    miBT.println("Error al inicializar la tarjeta SD");
    return;
  }
  //en caso contrario mostramos los siguientes mensajes
  miBT.println("Tarjeta SD inicializada correctamente");
  miBT.println("Escribe la ruta del archivo que deseas abrir:");
}

void loop() {
  //si hay datos disponibles para leer desde el modulo bluetooth
  if (miBT.available()) {
    //Creamos la ruta del archivo y la leemos
    String rutaArchivo = miBT.readStringUntil('\n');
    //eliminamos los espacios en blanco al principio y al final
    rutaArchivo.trim();
    //llamamos a la función
    mostrarContenidoArchivo(rutaArchivo);
    //solicitamos que se vuelva a ingresar otra ruta 
    miBT.println("Escribe la ruta del próximo archivo que deseas abrir:");
  }
}

void mostrarContenidoArchivo(String rutaArchivo) {
  /*
   Función que muestra el contenido del archivo indicado por el parámetro a través de la ruta. 
   Parámetro:
   ---------------------
   rutaArchivo(String): ruta del archivo a mostrar.

   Return
   ---------------------
   Devuelve el contenido del archivo indicado
    
    
   */
  //creamos variable archivo de tipo File
  File archivo;
  //si la ruta comienza con / el archivo se abre directamente
  if (rutaArchivo.startsWith("/")) {
    archivo = SD.open(rutaArchivo.c_str());
  } else {
    //sino se concatena para obtener la ruta completa y posteriormente se abre
    String rutaCompleta = String("/") + rutaArchivo;
    archivo = SD.open(rutaCompleta.c_str());
  }
  //si se ha podido abrir el archivo
  if (archivo) {
    miBT.println("Contenido del archivo:");
    //mientras haya datos disponibles en el archivo
    while (archivo.available()) {
      //leemos un byte del archivo y lo enviamos posteriormente
      miBT.write(archivo.read());
    }

    archivo.close();
  } else {
    miBT.println("No se encuentra el archivo. Introduce otro nombre:");
  }
}
