# ING-LP1-TPFinal

La línea 60, una de las más grandes de la capital desea unificar el sistema de
seguimiento de vehículos ya que ha habido muchos robos de colectivos y en los colectivos, y quieren
identificar el lugar donde pasó. En estos momentos la línea 60 cuenta con 2 tipos de colectivos y un subtipo.
Colectivos Con aire y dirección eléctrica. Cuyo subtipo es el colectivo acordeón. Y los colectivos viejos sin aire
y dirección hidráulica.

Los colectivos tienen una determinada cantidad de pasajeros máxima, que está dada por su tipo. El
colectivero, abre la puerta cuando llega a una parada, y deja primero bajar a los pasajeros que se deban bajar
en esta parada y luego entrar a los pasajeros (debe verificar que la cantidad no supere a su capacidad, no se
permite sobrepeso) que están en la parada. Cada pasajero debe indicar a la parada a la que viaja. El
colectivero le cobrara dependiendo de una tabla que posee que va en relación con la cantidad de paradas
entre la parada de subida y la de destino. Por obvios motivos, si el colectivo no pasa por la parada indicada
por el pasajero, este no sube. Si en la cola de la parada se encuentra una persona con sillas de rueda, esta
sube primero.

El colectivo posee además un recorrido, definido como una lista estática de paradas. Para poder identificar
en todo momento al colectivo, el mismo tiene un sistema GPS que actualiza cada 5 minutos su posición.
Cuando un colectivo se rompe, se envía un colectivo que tenga poca gente arriba directamente hasta su
ubicación, y se trasladan los pasajeros de uno a otro colectivo, y luego se lo lleva a arreglar al taller. Cuando
el colectivo llega a su parada final, el sistema le asigna dinámicamente un nuevo ramal (obviamente, el ramal
que se le asigna debe salir de la parada en la que está).

El sistema tiene además de la lista de colectivos, la lista de paradas. Estas además de su código
identificatorio, tienen un nombre descriptivo, una dirección, y una lista de personas que están en la parada.
El sistema simulador tiene un método TICK que se llama una vez por minuto actualiza el estado de todos los
objetos.

Al final del día, se debe desplegar una lista indicando la cantidad de personas que viajaron y el monto total
colectado por cada colectivo (indicando ramal y código de colectivo), y finalmente el monto y la cantidad
totales de pasajeros que viajaron en el día.

Modele. Los distintos tipos de colectivos, listas de paradas con las que se trabajan y personas.
Además de la funcionalidad requerida. Implemente un Simulador (main) de manera de verificar el
correcto funcionamiento del Sistema Big Brother Bus, genere aleatoriamente personas en las paradas y
simule el recorrido de los colectivos.
