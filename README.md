# Robotica
Diego Amaya 149119
Julio Sánchez 148221

ITAM

Robótica

ReadMe del primer proyecto de Robótica.
Se utilizó Ubuntu 16.04 LTS y ROS Kinetic como entorno para este proyecto.

En el repositorio de gitHub llamado Robotica creado por Juliosnchz se encuentra la carpeta src en la que se encuentra el proyecto, llamada proyecto1, hay que clonar la carpeta completa src al espacio de trabajo de ROS de la computadora.
Posteriormente hay que hacer el catkin_make desde el workspace.
Correr el source devel/setup.bash.
Se corre el roscore
Se inicia turtle sim corriendo: rosrun turtlesim turtlesim_node

El primer programa se ejecuta usando el comando:
rosrun proyecto1 controlaTortuga

Se preguntará primero la distancia a recorrer, se introduce y se da enter y lo mismo para la velocidad, la cual debe estar entre 1 y 5.
Luego se imprimirán los valores de las poses.

Se puede detener y volver a iniciar el turtlesim_node si se desea.

Para correr el segundo programa se usa el comando:
rosrun proyecto1 controlaTortuga2

Se preguntará primero la distancia a recorrer, se introduce y se da enter y lo mismo para la velocidad, ésta debe ser entre 1 y 5.
Comenzará a imprimir valores de las poses.

Nota: En la computadora en la que fue creada, ambos programas corren de manera cabal. En caso de que no corra de una manera correcta o esperada, es muy probable que sea por una versión diferente de ROS, ya que cambian ciertos aspectos del Turtlesim.

diegoamayaw@gmail.com
julio_milan19@hotmail.com 
