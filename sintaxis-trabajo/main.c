#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // permite usar _Bool como tipo de dato
#define MAXIMO 10 // constante para la maxima longitud de una cadena, el compilador reemplaza con el valor donde figure la constante

void getCadena (char cadena[]) { // esto funciona porque los arrays se pasan por referencia SIEMPRE
  printf("Introduzca una cadena de caracteres (limite %d): ", MAXIMO);
  gets(cadena);
  return;
}

int longitud (char cadena[]) {
  int pos = 0;
  while (cadena[pos] != '\0') pos++; // cuando llega al final sale del loop
  return pos;
}

_Bool esVacia (char cadena[]) {
  return !longitud(cadena); // si la longitud es 0 retorna 1 (true)
}

void concatenar(char cadena1[], char cadena2[], char concatenado[]) { // esto funciona porque los arrays se pasan por referencia SIEMPRE
  int pos1, pos2;

  pos1 = pos2 = 0;

  for (pos1; pos1 < longitud(cadena1); pos1++) concatenado[pos1] = cadena1[pos1];
  for (pos2; pos2 < longitud(cadena2); pos2++) concatenado[pos1 + pos2] = cadena2[pos2];

  concatenado[pos1 + pos2] = '\0';

  return;
}

void finalizarPrueba() {
  printf("\nPrueba finalizada.\n");
  return;
}

void prueba () { // funcion de prueba
  char cadena[MAXIMO];
  cadena[0] = '\0';

  getCadena(cadena); // pasaje por referencia

  if (longitud(cadena) > MAXIMO) {
    printf("\nSe han introducido mas caracteres que el maximo permitido (%d)\n", MAXIMO);
    finalizarPrueba();
    return;
  }

  printf("Longitud de la cadena: %d\n", longitud(cadena));

  if (esVacia(cadena)) printf("La cadena es vacia.\n\n");
  else printf("\n");

  char otraCadena[MAXIMO];
  otraCadena[0] = '\0';

  getCadena(otraCadena); // pasaje por referencia

  if (longitud(otraCadena) > MAXIMO) {
    printf("\nSe han introducido mas caracteres que el maximo permitido (%d)\n", MAXIMO);

    finalizarPrueba();
    return;
  }

  printf("Longitud de la otra cadena: %d\n", longitud(otraCadena));

  if (esVacia(otraCadena)) printf("La otra cadena es vacia.\n\n");
  else printf("\n");

  if (esVacia(cadena) && esVacia(otraCadena)) { // antes de concatenar cadenas vacias verificar
    printf("Ambas cadenas son vacias.\n");

    finalizarPrueba();
    return;
  } else if (esVacia(cadena) || esVacia(otraCadena)) {
    printf("La cadena concatenada va a ser igual a la cadena \"%s\", ya que la otra cadena esta vacia.\n",
      esVacia(otraCadena) ? cadena : otraCadena // condicional ternario, si otraCadena es vacia da el valor de cadena y viceversa
    );

    finalizarPrueba();
    return;
  }

  char concatenado[MAXIMO * 2]; // MAXIMO * 2 le permite a la cadena tener la longitud mas amplia posible ya que no se puede declarar con variables
  concatenar(cadena, otraCadena, concatenado); // pasaje por referencia

  printf("\nCadena concatenada de \"%s\" con \"%s\" = \"%s\".\n", cadena, otraCadena, concatenado);

  finalizarPrueba();

  return;
}

int main() {
  prueba();

  return 0;
}
