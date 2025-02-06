# Modelado de servicio de streaming 

En los últimos años, han proliferado los servicios de streaming de video bajo demanda por ejemplo Netflix, Disney, DC entre otros. Algunos de ellos se especializan por el volumen de videos que proporcionan a sus usuarios mientras que otros se han puesto el reto de mostrar solamente videos de su propia marca. Una versión limitada para apoyar a un futuro proveedor de este tipo de servicios es la que se describe a continuación:

Se quiere trabajar con dos tipos de videos: películas y series. 

Todo video tiene :

-  ID
- Nombre Pelicula / Serie
- Género
- Calificación
- Duración 
- Fecha Estreno

Las series tienen episodios y cada episodio tiene:

- ID
- Nombre
- Temporada a la que pertenece.
- Número de episodio

Nos interesa conocer la calificación promedio que ha recibido cada uno de los videos. Esta califiación está en escala de 1 a 10 donde 10 es la mejor calificación.

El sistema debe ser capaz de :

La aplicación debe mostrar el siguiente menu ciclado:

1. Cargar archivo de datos (Excel o csv)
2. Mostrar los videos en general con:
   1.  Una calificación mayor a cierto parámtero 
   2.  Un cierto género
3.  Mostrar los episodios de una determinada serie.
4. Mostrar las películas con una calificacion mayor a cierto número
5. Calificar un video
   - Pedir titulo de película o nombre episodio de la serie a calificar
   - Pedir valor otorgado
6. Salir
