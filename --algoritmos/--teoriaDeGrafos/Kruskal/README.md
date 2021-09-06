# Kruskal
#### *¿Qué es?* 
El algoritmo de Kruskal, encuentra un árbol de expansión mínima. Es decir, es capaz de encontrar un subconjunto de las aristas que formen un árbol que incluya todos los vértices del grafo inicial, donde el peso total de las aristas del árbol es el mínimo posible. Si el grafo no es conexo, entonces busca un bosque expandido mínimo.
El algoritmo de Kruskal es un ejemplo de algoritmo voraz.
Se realiza de la siguiente manera:
1. Ordene los bordes en orden ascendente de acuerdo con sus pesos.
2. En cada paso, elija el borde más pequeño (con un peso mínimo). Si este borde forma un ciclo con el MST formado hasta ahora, descarte el borde, de lo contrario, agréguelo al MST.
3. Repita el paso 2, hasta que no todos los vértices estén presentes en MST.

## *Funcion*
* Se crea un bosque B (un conjunto de árboles), donde cada vértice del grafo es un árbol separado
* Se crea un conjunto C que contenga a todas las aristas del grafo
* Mientras C es no vacío
* Eliminar una arista de peso mínimo de C
* Si esa arista conecta dos árboles diferentes se añade al bosque, combinando los dos árboles en un solo árbol
* En caso contrario, se desecha la arista
* Al acabar el algoritmo, el bosque tiene un solo componente, el cual forma un árbol de expansión mínimo del grafo.

## *Código base*
-  [Kruskal](kruskal.cpp) - _C++_

## *Refrencias*
-  [Algoritmo de Kruskal - arbol de expansion minimo](https://www.tutorialcup.com/es/interview/graph/kruskal-algorithm.htm)
-  [Algoritmo_kruskal-Grafos](https://arodrigu.webs.upv.es/grafos/doku.php?id=algoritmo_kruskal)
-  [Algoritmos de Kruskal y Prim](https://www.wextensible.com/temas/voraces/kruskal-prim.html)
-  [Algoritmos de Kruskal - Complejidad algoritmica](https://sites.google.com/site/complejidadalgoritmicaes/kruskal)