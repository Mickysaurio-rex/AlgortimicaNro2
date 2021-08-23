# Segment Tree  
#### *¿Qué es?* 

Un *árbol de segmentos* es una estructura de datos que se utiliza para almacenar información sobre segmentos de matriz y responder a las consultas de segmento de forma eficaz. Hay dos operaciones principales realizadas en un árbol de segmentos:

* query(i, j): da la suma de los elementos de la matriz que comienzan en el índice i y terminan en el índice j.

* update(i, val):actualiza el valor del índice i al valor de la matriz original y actualiza el árbol de segmentos en consecuencia.

Estos dos toman log(n)log(n) time, donde n es el número de elementos del árbol de segmentos.

[![SegmentTree](https://he-s3.s3.amazonaws.com/media/uploads/eec15d3.jpg "SegmentTree")](https://he-s3.s3.amazonaws.com/media/uploads/eec15d3.jpg "SegmentTree")