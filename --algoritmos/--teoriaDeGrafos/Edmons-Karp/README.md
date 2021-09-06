# Edmons Karp
#### *¿Qué es?* 
La búsqueda del flujo máximo para una red se resolvió primero mediante el algoritmo Ford-Fulkerson. Una red a menudo se define de manera abstracta como un grafo *G*, que tiene un conjunto de vértices *V*, conectados por un conjunto de bordes *E*. Hay una inicio *s*, y un final *t*. La búsqueda del flujo máximo a través de una red se resolvió mediante el teorema de corte mínimo de flujo máximo, que luego se utilizó para crear el algoritmo de Ford-Fulkerson.

Edmonds-Karp es idéntico a Ford-Fulkerson excepto por un rasgo muy importante. El orden de búsqueda de las rutas de aumento está bien definido. Las rutas de aumento son simplemente cualquier ruta desde la fuente hasta el sumidero que actualmente puede tomar más flujo. A lo largo del algoritmo, el flujo aumenta de forma monótona. Entonces, hay momentos en que un camino desde la fuente hasta el sumidero puede tomar más flujo, y ese es un camino en aumento.

## *Código base*
-  [Edmons Karp](edmonsKarp.cpp) - _C++_

## *Refrencias*
-  [Algoritmo de Edmons Karp](https://es.wikipedia.org/wiki/Algoritmo_de_Edmonds-Karp)
-  [Transcript](https://courses.engr.illinois.edu/cs491cap/fa2019/transcripts/edmonds-karp/)
-  [Edmons Karp Algorithm](https://brilliant.org/wiki/edmonds-karp-algorithm/)
