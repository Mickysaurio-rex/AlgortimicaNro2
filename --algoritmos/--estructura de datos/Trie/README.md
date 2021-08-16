# Trie Data Structure 
#### *¿Qué es?* 

También conocido como *Árbol de Prefijos*, es una estructura de datos útil para resolver problemas asociados con el almacenamiento de strings con la finalidad de poder realizar operaciones como:
- consultar
- insertar
- elminar

Esta estructura fue introducida por por Rene de la Briandais y Edward Fredking en 1959. El nombre proviene de la palabra RETRIEVAL, que significa recuperación. El poder de Trie radica en su complejidad temporal, el tiempo de inserción y consulta tardan O (k), donde k es la longitud de la palabra, independientemente de cuántos elementos ya se tienen almacenados.
Para implementar esta estructura podemos utilizar un **Array** o **Map**. Pero cada uno tiene su desventaja:
1. Para el primer caso, al utilizar *array*, ocupamos mucha más memoria.
2. Por otro lado, map consume más tiempo al momento de buscar una palabra.

[![TRIE](https://media.vlpt.us/images/roo333/post/d29f3566-596d-40ae-868e-9322bba44ed6/Trie.png "TRIE")](https://www.google.com/url?sa=i&url=https%3A%2F%2Fvelog.io%2F%40roo333%2FTrie-8dfhae1g&psig=AOvVaw0CDrqQaoP1XJb4gyCiAVXy&ust=1629225299001000&source=images&cd=vfe&ved=0CAsQjRxqFwoTCJiJxcWXtvICFQAAAAAdAAAAABAI "TRIE")

#### *Partes del Árbol Trie* 
El árbol de Trie tiene algunas características:
- El nodo raíz no contiene caracteres.
- Desde el nodo raíz hasta cierto nodo, los caracteres que pasan por la ruta se conectan para formar la cadena para así armar una palabra.
- Todos los nodos secundarios de cada nodo contienen caracteres diferentes.
- Si el número de caracteres es n, entonces el grado de salida de cada nodo es n, que también es una manifestación del espacio para el tiempo, que desperdicia mucho espacio.
- La complejidad de la búsqueda por inserción es O (n) y n es la longitud de la cadena.
Idea básica.
- El nodo final de cada palabra contiene un identificador booleano.

#### *¿Cómo funciona?*

1. Proceso de inserción
Para una palabra, comenzando desde la raíz, baje por la rama del nodo en el árbol correspondiente a cada letra de la palabra hasta que la palabra se atraviese, y el último nodo se marque con el identificador boolenao, lo que indica que la palabra se ha insertado en el árbol Trie.
2. Proceso de consulta
De manera similar, comenzando desde la raíz y atravesando el árbol trie hacia abajo en orden alfabético de palabras, una vez que se encuentra que una determinada marca de nodo no existe o que se completa el recorrido de palabra y el último nodo no está marcado con el identificador, significa que el la palabra no existe Si el último nodo está marcado, indica que la palabra existe.
3. Proceso de eliminación
Durante la operación de eliminación, eliminamos la clave de abajo hacia arriba usando recursividad. Si la clave presente como clave única no es prefijo de otra clave en trie. Se eliminan todos los nodos.

#### *Algunas aplicaciones* 

- Búsqueda de cadenas
- El prefijo común más largo de una cadena
- Ordenar
- Como estructura auxiliar para otras estructuras de datos y algoritmos.
- Estadísticas de frecuencia de palabras
- Prefijo coincidente para búsqueda de cadenas 
