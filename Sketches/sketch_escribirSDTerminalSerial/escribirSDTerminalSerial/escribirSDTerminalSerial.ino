//Autor: Víctor Barcina Muñoz
//añadimos la librería SPI
#include <SPI.h>
//añadimos la librería SD
#include <SD.h>
 //creamos una variable denominada tarjeta, a la que se le asigna el pin 4 para la comunicación SPI con la tarjeta SD.
const int tarjeta = 4;

void setup() {
  //inicializamos la comunicación serial
  Serial.begin(9600);
  //esperamos a que se inicialice la comunicación antes de seguir con el resto del código
  while (!Serial) {
    ; 
  }

  Serial.print("Inicializando tarjeta SD...");
// si no reconoce la tarjeta imprimimos error
  if (!SD.begin(tarjeta)) {
    Serial.println("Fallo al inicializar la tarjeta SD");
    return;
  }
//en caso contrario imprimimos que la incialización es correcta
  Serial.println("Tarjeta SD inicializada correctamente");
//solicitamos introducir el nombre del archivo nuevo
  Serial.println("Introduzca el nombre del archivo nuevo:");
}

void loop() {
  //creamos una variable que controla si se ha ingresado el nombre del archivo o no
  static bool nombreArchivoIngresado = false;
  //creamos una variable que consiste en el nombre del archivo
  static String nombre_archivo;
  //creamos una variable que almacena el contenido a escribir en el archivo
  static String contenido_archivo;
//si el nombre del archivo aún no ha sido ingresado y hay datos disponibles en la comunicación serial
  if (!nombreArchivoIngresado && Serial.available()) {
    //lee la cadena de caracteres del nombre del archivo hasta encontrar salto de linea
    nombre_archivo = Serial.readStringUntil('\n');
    //eliminamos los espacios en blanco al incio y al final
    nombre_archivo.trim();
    //si el archivo ya existe le indicamos que no se creará de nuevo
    if (SD.exists(nombre_archivo)) {
      Serial.println("El archivo ya existe, no se creará nuevamente");
    } else {
      //en caso contario solicitamos que se escriba lo que se desea en el archivo
      Serial.println("Indique el contenido del archivo:");
      //cambiamos la bandera a true para indicar que ya se ha ingresado el nombre
      nombreArchivoIngresado = true;
    }
  }
  //si el nombre ha sido ingresado y hay datos en la comunicación serial
  if (nombreArchivoIngresado && Serial.available()) {
    //leemos el contenido del archivo hasta encontrar un salto de línea
    contenido_archivo = Serial.readStringUntil('\n');
    //eliminamos los espacios en blanco al incio y al final
    contenido_archivo.trim();
    //abrimos el archivo en modo escritura
    File archivo = SD.open(nombre_archivo, FILE_WRITE);
    //si se ha abierto el archivo escribimos el contenido y lo cerramos
    if (archivo) {
      archivo.println(contenido_archivo);
      archivo.close();
      Serial.println("Archivo creado exitosamente");
    } else {
      Serial.println("Error al crear el archivo");
    }
  //reestablecemos la bandera a false para indicar un nuevo nombre
    nombreArchivoIngresado = false;
    Serial.println("Introduzca el nombre del archivo:");
  }
}
