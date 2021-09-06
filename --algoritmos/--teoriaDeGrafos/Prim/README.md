# Prim
#### *¿Qué es?* 
El algoritmo de Prim, encuentra un árbol de expansión mínima. Es decir, es capaz de encontrar un subconjunto de las aristas que formen un árbol que incluya todos los vértices del grafo inicial, donde el peso total de las aristas del árbol es el mínimo posible.
El algoritmo encuentra un subconjunto de aristas que forman un árbol con todos los vértices, donde el peso total de todas las aristas en el árbol es el mínimo posible. Si el grafo no es conexo, entonces el algoritmo encontrará el árbol recubridor mínimo para uno de los componentes conexos que forman dicho grafo no conexo.
El algoritmo incrementa continuamente el tamaño de un árbol, comenzando por un vértice inicial al que se le van agregando sucesivamente vértices cuya distancia a los anteriores es mínima. Esto significa que en cada paso, las aristas a considerar son aquellas que inciden en vértices que ya pertenecen al árbol.

## *Aplicacion*
Este algoritmo se usa normalmente para ahorrar recursos, su aplicación mas común es la implementación de cables de redes, de servidores, de postes de luz entre otros. Es decir, sirve para poder hallar el "árbol recubridor mínimo", en un grafo conexo no dirigido.

## *Código base*
-  [Prim](prim.cpp) - _C++_

## *Refrencias*
-  [El algoritmo de Prim](https://www.monografias.com/trabajos87/monografia-algoritmo-prim/monografia-algoritmo-prim.shtml#aplicacioa)
-  [Prim - Familia de funciones](https://docs.pgrouting.org/dev/es/prim-family.html)
-  [Algoritmo de Prim](https://www.ecured.cu/Algoritmo_de_Prim)
-  [Algoritmo de Prim - Complejidad algoritmica](https://sites.google.com/site/complejidadalgoritmicaes/prim)