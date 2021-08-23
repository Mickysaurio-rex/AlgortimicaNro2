# Backtracking  
#### *¿Qué es?* 

La técnica de *backtracking* está muy asociada a la recursividad, o mas propiamente, a la estructura recursiva de la mayoría de tipos de datos: listas, árboles, etc. Consiste básicamente en :

* Enumerar sistemáticamente las alternativas que existen en cada momento para dar con la solución a un problema.

* Se prueba una alternativa, guardando memoria del resto de alternativas.

* Si no damos con la solución, podemos dar marcha atrás (backtracking) y probar otra alternativa.

Los problemas que deben satisfacer un determinado tipo de restricciones son problemas completos, donde el orden de los elementos de la solución no importa. Estos problemas consisten en un conjunto de variables a la que a cada una se le debe asignar un valor sujeto a las restricciones del problema. La técnica va creando todas las posibles combinaciones de elementos para obtener una solución. Su principal virtud es que en la mayoría de las implementaciones se puede evitar combinaciones, estableciendo funciones de acotación (o poda) reduciendo el tiempo de ejecución.

[![Backtracking](https://slidetodoc.com/presentation_image_h/b880e5f78c05b441f56f3761c97ee1e3/image-14.jpg "Backtracking")](https://slidetodoc.com/presentation_image_h/b880e5f78c05b441f56f3761c97ee1e3/image-14.jpg "Backtracking")

## *Código base*

-  [Queens](queens.cpp) - _C++_

## *Refrencias*

-  [Recursion And Backtracking](https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/)
-  [Vuelta Atras(Backtracking)](https://www.ecured.cu/Vuelta_atr%C3%A1s_(backtracking))
- [Backtracking](https://www.ciberaula.com/cursos/java/backtracking.php)
