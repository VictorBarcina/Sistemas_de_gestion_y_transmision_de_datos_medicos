//Autor: Víctor Barcina Muñoz
//importamos la librería SPI para la comunicación SPI
#include <SPI.h>
//importamos la librería SdFat para manipular los archivos de la tarjeta SD. 
#include <SdFat.h>

//declaramos el objeto sd de tipo SdFat para interactuar con la tarjeta SD. 
SdFat sd;
//indicamos el pin de la tarjeta SD como 4. 
const int tarjeta = 4;
//declaramos la variable ruta_carpeta como una cadena de caracteres de manera que podemos indicar la ruta
//donde se desea guardar el nuevo archivo. 
const char ruta_carpeta[] = "/apneaCAP/paciente1";
//creamos la variable nombre_archivocomo una cadena de caracteres de manera que podemos seleccionar el nombre
//que queremos que tenga el archivo
const char nombre_archivo[] = "prueba.txt";
//creamos la variable contenido_archivo de manera que en función de lo que escribamos, se guardará
//dentro de la variable creada. 
const char contenido_archivo[] = "Patient: INS1.\nEvents Included: MCAP-A1,MCAP-A2,MCAP-A3,SLEEP-REM,SLEEP-S0,SLEEP-S1,SLEEP-S2,SLEEP-S3,SLEEP-S4,SLEEP-UNSCORED.";

void setup() {
  //inicializamos la comunicación Serial
  Serial.begin(9600);
  //creamos un bucle para esperar a que se produzca la comunicación serial. 
  while (!Serial) {
    ; 
  }
  
  Serial.print("Inicializando tarjeta SD...");
  //inicializamos la tarjeta SD con el método begin de la librería SdFat. 
  //indicamos el número de pin de la tarjeta y especificamos la máxima velocidad de transferencia de datos.
  if (!sd.begin(tarjeta, SPI_FULL_SPEED)) {
    //Si falla la inicialización imprime por pantalla el mensaje
    Serial.println("Fallo al inicializar la tarjeta SD, revise si está insertada correctamente");
    return;
  }
  //en caso contrario imprimimos que la tarjeta se ha inicializado de manera correcta. 
  Serial.println("Tarjeta SD inicializada correctamente");

  //creamos una cadena de caracteres denominada ruta_completa de manera que se concatena la ruta de la 
  //carpeta con el nombre del archivo
  String ruta_completa = String(ruta_carpeta) + "/" + String(nombre_archivo);
  

  //abrimos el archivo en modo escritura y creamos el archivo
  File archivo = sd.open(ruta_completa.c_str(), FILE_WRITE);
  //si el archivo se ha abierto de manera correcta escribimos el contenido, y lo cerramos. 
  if (archivo) {
    archivo.println(contenido_archivo);
    archivo.close();
    Serial.println("Archivo creado exitosamente en la ruta indicada");
  } else {
    Serial.println("Error al crear el archivo en la ruta indicada");
  }
}

void loop() {
  //No se ha añadido nada en el void loop()
}
