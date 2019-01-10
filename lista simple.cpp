//Declaración de librerías
#include <iostream>
#include <stdlib.h>
//Estructura
struct Nodo{
	int elem;
	Nodo *sig;
};
//Funciones prototipos
int vacia (Nodo **);
void insertar (Nodo **, Nodo **, Nodo **, int);
void irInicio (Nodo **, Nodo **);
void irFinal (Nodo **, Nodo **);
void avanzar (Nodo **);
void mostrar (Nodo **);
//función main
using namespace std;
int main(){
	Nodo *cab = NULL, *ult = NULL, *pvte = NULL;
	int valor;
	int opc;
	
	do{
		system("cls");
		cout << "1.-Insertar" << endl;
		cout << "2.-Mostrar" << endl;
		cout << "3.-SALIR" << endl;
		cout << "Ingrese opcion: ";
		cin >> opc;
		switch (opc){
			case 1:
				system("cls");
				cout << "Ingrese numero: ";
				cin >> valor;
				int opcion;
				cout << "1.-Para ir al inicio" << endl;
				cout << "2.-Para ir al final" << endl;
				cout << "3.-Para avanzar" << endl;
				cout << "Ingrese opcion: ";
				cin >> opcion;
				switch (opcion){
					case 1:
						irInicio (&cab, &pvte);
						break;
					case 2:
						irFinal (&ult, &pvte);
						break;
					case 3:
						avanzar (&pvte);
						break;
				}
				
				insertar (&cab, &ult, &pvte, valor);
				break;
			case 2:
				system("cls");
				cout << "LOS ELEMENTOS INGRESADOS SON" << endl;
				
				mostrar (&cab);
				break;
		}
		system("pause");
	}while(opc != 3);
	
	return 0;
}
//Desarrollo y cuerpo de las funciones prototipos
int vacia (Nodo **cab){
	if (*cab == NULL)
		return 1;
	else 
		return 0;
}
void insertar (Nodo **cab, Nodo **ult, Nodo **pvte, int valor){
	Nodo *p, *aux = NULL;
	p = new Nodo ();
	p -> elem = valor;
	if(vacia(cab)){
		p -> sig = NULL;
		*cab = *ult = *pvte = p;
		cout << "Valor insertado correctamente como primero" << endl;
	}
	else{
		if(*pvte == *ult){
			aux = *ult;
			p -> sig = NULL;
			aux -> sig = p;
			*ult = p;
			cout << "Valor insertado correctamente como ultimo" << endl;
		}
		else{
			aux = *pvte;
			p -> sig = aux -> sig;
			aux -> sig = p;
			cout << "Valor insertado correctamente" << endl;
		}
	}
}
void irInicio (Nodo **cab, Nodo **pvte){
	if (vacia(cab))
		*pvte = NULL;
	else 
		*pvte = *cab;
}
void irFinal (Nodo **ult, Nodo **pvte){
	if (*ult == NULL)
		*pvte = NULL;
	else 
		*pvte = *ult;
}
void avanzar (Nodo **pvte){
	if (*pvte == NULL)
		cout << "No se puede avanzar" << endl;
	else {	
		Nodo *aux = NULL;
		aux = *pvte;
		aux = aux -> sig;
		if(aux == NULL){
			cout << "No se puede avanzar" << endl;
			system("pause");
		}
		else
			*pvte = aux;
	}
}
void mostrar(Nodo **cab){
	Nodo *aux;
	if (vacia(cab))
		cout << "La pila esta vacia";
	else {
		aux = *cab;
		while (aux != NULL){
			cout << aux -> elem << endl;
			aux = aux -> sig;
		}
		cout << "TODOS LOS ELEMENTOS MOSTRADOS" << endl;
	}
} 
