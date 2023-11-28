#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Estructura para almacenar la información de cada entrada en la bitácora
struct LogEntry {
    string month;
    int day;
    string time;
    string ipAddress;
    string reason;
};

struct Node {
    string key;
    string value;
    Node* next;
    Node(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Estructura para la tabla hash
struct HashTable {
    static const int tableSize = 100; 
    vector<Node*> table;

    HashTable() : table(tableSize, nullptr) {}

    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        // Si no hay colisión inserta el nuevo nodo
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            // Si hay colisión, agrega el nuevo nodo al principio de la lista
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    // Método para buscar un valor dado una clave en la tabla hash
    string find(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        // Busca en la lista en caso de colisión
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        // Retorna una cadena indicando que la clave no se encontró
        return "Dominio no encontrado en la bitácora.";
    }

private:
    // Función de hash simple para obtener el índice en la tabla hash
    int hashFunction(const string& key) {
        int sum = 0;
        for (char ch : key) {
            sum += static_cast<int>(ch);
        }
        return sum % tableSize;
    }
};

// Método para leer la bitácora y construir la tabla hash
void buildHash(const string& filename, HashTable& hashTable) {
    ifstream inputFile(filename);
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        LogEntry entry;

        iss >> entry.month >> entry.day >> entry.time >> entry.ipAddress;
        getline(iss, entry.reason);

        // Extraer el dominio del campo ipAddress
        size_t pos = entry.ipAddress.find(":");
        if (pos != string::npos) {
            string domain = entry.ipAddress.substr(0, pos);
            // Asignar el resumen al dominio en la tabla hash
            hashTable.insert(domain, entry.reason + "\n");
        }
    }
}

int main() {
    const string filename = "bitacora.txt";

    // Construir la tabla hash a partir del archivo de bitácora
    HashTable hashTable;
    buildHash(filename, hashTable);

    // Ejemplo: Obtener el valor asociado al dominio "ejemplo.com"
    string domain = "960.96.3.29";
    string summary = hashTable.find(domain);

    // Desplegar la información de manera adecuada
    cout << "Resumen para el dominio " << domain << ":\n";
    cout << summary;

    return 0;
}
