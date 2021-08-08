#include <iostream>

using namespace std;



int main() {

 int cuota,inicial,costo;



 cout << "Inserte el Costo del Curso en Bsf Aqui ";

 cin >> costo;



 inicial=costo*20/100;

 cuota=(costo-inicial)/24;



 cout << "La inicial a pagar es de Bsf " << inicial << endl;

 cout << "El monto de las cuotas es de Bsf " << cuota << endl;



 return 0;

}
