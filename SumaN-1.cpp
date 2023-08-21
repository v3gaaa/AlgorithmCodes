//Programa que calcula la suma de 1 a n con diferentes metodos
//Autor: Sebastian Denhi Vega Saint Martin
//Matricula:A01637397


#include <iostream>
using namespace std;

// Función para calcular la sumatoria de 1 hasta n de forma iterativa
// La complejidad de tiempo de este algoritmo es O(n) ya que se ejecuta solamente un for n veces
int sumaIterativa(int n,int suma) {
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

// Función para calcular la sumatoria de 1 hasta n de forma recursiva
//La complejidad de tiempo de este algoritmo es O(n) ya que es una función recursiva que se llama n veces
int sumaRecursiva(int n, int suma) {
    if (n == 0) {
        return suma;
    } else {
        return sumaRecursiva(n - 1, suma + n);
    }
    
}

// Función para calcular la sumatoria de 1 hasta n de forma directa
//La complejidad de tiempo de este algoritmo es O(1) ya que solo se hace una operación con tiempo constante

int sumaDirecta(int n) {
    return (n * (n + 1)) / 2;
}

int main() {

    int n;
    int suma = 0;

    cout << "Ingrese un numero n: ";
    cin >> n;

    //Verificar que el numero sea positivo
    while (n < 0) {
        cout << "Ingrese un numero n positivo: ";
        cin >> n;
    }
    
    // Calcular la sumatoria de 1 hasta n utilizando las tres funciones
    int resultIterativo = sumaIterativa(n,suma);  
    int resultRecursivo = sumaRecursiva(n,suma);
    int resultDirecto = sumaDirecta(n);
    
    
    // Mostrar los resultados
    cout << "Sumatoria iterativa: " << resultIterativo << endl;
    cout << "Sumatoria recursiva: " << resultRecursivo << endl;
    cout << "Sumatoria directa: " << resultDirecto << endl;
    
    
    return 0;
}
