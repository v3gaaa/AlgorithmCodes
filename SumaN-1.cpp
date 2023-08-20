#include <iostream>

using namespace std;

// Función para calcular la sumatoria de 1 hasta n de forma iterativa
int sumaIterativa(int n,int suma) {
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

// Función para calcular la sumatoria de 1 hasta n de forma recursiva
int sumaRecursiva(int n, int suma) {
    if (n == 0) {
        return suma;
    } else {
        return sumaRecursiva(n - 1, suma + n);
    }
    
}

// Función para calcular la sumatoria de 1 hasta n de forma directa
int sumaDirecta(int n) {
    return (n * (n + 1)) / 2;
}

int main() {

    int n;
    int suma = 0;

    cout << "Ingrese un numero n: ";
    cin >> n;
    
    
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
