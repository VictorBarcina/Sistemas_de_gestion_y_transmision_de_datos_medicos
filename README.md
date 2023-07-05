# Sistemas_de_gestion_y_transmision_de_datos_medicos
El proyecto desarrollado tiene el objetivo de desarrollar programas que permitan el manejo de directorios y archivos almacenados en una memoria microSD, empleando Arduino. Posteriormente, se desarrollaron programas para la visualización de los archivos de la memoria SD empleando un terminal Bluetooth. 

## Telemedicina
La telemedicina ha aparecido durante las últimas décadas como consecuencia del desarrollo de la tecnología. Esta disciplina abarca muchos campos situados en una intersección entre la medicina e informática. Como consecuencia, también ha provocado una nueva forma de pensar y de trabajo , de modo que ocasiona cambios permanentes en el modelo sanitario. 

En términos generales consiste en aplicar servicios de salud empleando nuevas tecnologías en sitios  remotos o donde no esté la medicina tan accesible de manera que permita el diagnóstico, tratamiento y prevención de enfermedades, así como la educación de los proveedores de la salud. Su principal objetico es mejorar la calidad de vida y de salud de las personas y de las comunidades. 

## Arduino 
Sistema de hardware libre empleado para el desarrollo de elementos electrónicos aplicados en diferentes áreas o ingenierías. [2]. Es una plataforma gratuíta que permite diseñar y desarrollar aplicaciones a través de lenguajes de programación similares a C o C++. Es una herramienta ideal para automatizar procesos físicos, monitorizar diferentes sensores analógicps y digitales o desarrollar aplicaciones. [3]

La plataforma empleada en el proyecto ha sido Arduino Uno debido a que proporciona un entorno de programación flexible para el desarrollo del proyecto. 

## Objetivos del proyecto
1. Diseñar el prototipo del dispositivo portátil que permita manejar y
compartir los datos de diferentes orígenes. En este caso se han empleado
datos provenientes de diferentes bases de datos de cardiología.
2. El dispositivo ha de ser capaz de almacenar los datos en una tarjeta
SD de formato FAT 32. Además se debe permitir el manejo de estos
datos, así como poder conocer el contenido de la tarjeta SD, añadir y
almacenar nuevos datos.
3. La comunicación de los datos permite conocer al usuario que se conecte
mediante Android, conocer los datos de la tarjeta SD y poder leer los
archivos a través del terminal del Bluetooth.
4. Realizar diferentes pruebas para verificar el funcionamiento de los
sistemas creados.

## Metodología 
Para el desarrollo de estos programas se ha utilizado el entorno de Arduino, así como los materiales indicados en la memoria del mismo. Los sensores o módulos empleados han sido: 
1. Placa de Arduino UNO
2. Ethernet Shield W5100
3. Memoria microSD
4. HC 05
5. Protoboard y cables puente.

Inicialmente, durante el primer semestre, se establecieron los primeros objetivos a corto plazo y se obtuvo una visión general del proyecto. Sin embargo, debido a los estudios y asignaturas del grado académico, fue necesario esperar a que finalizaran los exámenes para poder dedicar más tiempo a la investigación.

Durante el segundo semestre, con las ideas más claras sobre lo que se pretendía conseguir, se procedió a trabajar personalmente en el desarrollo de los programas. Esta fase implicó una dedicación intensa de aproximadamente 2 meses, durante los cuales se llevó a cabo una exhaustiva búsqueda de información, se desarrollaron los programas necesarios y se diseñaron la
parte electrónica que requiere el proyecto. Una vez finalizados los programas, se realizaron diversas pruebas para garantizar el correcto funcionamiento de los programas y la 
 interoperabilidad de los dispositivos.
 
La elaboración de la memoria se realizó de forma progresiva y en paralelo al avance de la investigación y el desarrollo. A medida que se obtenían resultados y se realizaban nuevos descubrimientos, se documentaba de manera detallada en la memoria. Esta metodología permitió capturar de manera precisa los diferentes aspectos del proyecto, desde el planteamiento
inicial hasta los resultados obtenidos.

Es importante destacar que se dio especial atención a la documentación de los programas y herramientas desarrolladas. Esta documentación se realizó al finalizar el proyecto, una vez que se contaba con una versión final y depurada de los programas. De esta manera, se aseguró que toda la información relevante estuviera disponible para futuras referencias y facilitara la replicabilidad del proyecto.


## Referencias
[1] Prados Castillejo, J. A. (2013). Telemedicina, una herramienta también para el médico de familia. (pp. 129-132). Disponible en: https://www.elsevier.es/es-revista-atencion-primaria-27-articulo-telemedicina-una-herramienta-tambien-el-S0212656712003484 
[2] Jose Carlos Herrero Herranz and Jesús Sánchez Allende. Una mirada al
mundo arduino | herrero herranz | tecnología y desarrollo. Disponible en https:
//revistas.uax.es/index.php/tec_des/article/view/617
[3] Fernando Reyes Cortés and Jaime Cid Monjaraz 2015. Arduino: aplicaciones
en robótica, mecatrónica e ingenierías - fernando reyes cortes, jaime cid
monjaraz - google libros. https://books.google.es/books?hl=es&
lr=&id=fExOEAAAQBAJ&oi=fnd&pg=PR1&dq=plataforma+arduino&
ots=PYm4j5EfpK&sig=-BhJjHd1RW1ecOXfGGZADdYB1kM#v=onepage&
q=plataforma%20arduino&f=false
