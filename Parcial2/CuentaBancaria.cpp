#include <iostream> // Biblioteca para operaciones estándar de entrada y salida
#include "src/CuentaBancaria.cpp" // Inclusión de la implementación de la clase CuentaBancaria
#include <string> // Biblioteca para trabajar con cadenas de texto
#include <vector> // Biblioteca para usar el contenedor vector
#include <fstream> // Biblioteca para manejo de archivos
using namespace std; // Uso del espacio de nombres estándar

int main() {

    vector<CuentaBancaria> cuentas; // Vector para almacenar varias cuentas bancarias

    ofstream archivoSalida("../../Parcial2/salidas/reporte.txt"); // Crear y abrir el archivo de salida
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl; // Mostrar error si el archivo no se abre
        return 1; // Finaliza el programa con error
    }

    // Crear y agregar 3 cuentas bancarias con datos iniciales
    cuentas.push_back(CuentaBancaria(1000.0, "12345"));
    cuentas.push_back(CuentaBancaria(1500.0, "67890"));
    cuentas.push_back(CuentaBancaria(5000.0, "54321"));

    // Simulación de transacciones para cada cuenta
    for (int i = 0; i < cuentas.size(); i++) {
        archivoSalida << "----------------------------------------" << endl;
        archivoSalida << cuentas[i] << endl; // Mostrar información de la cuenta
        float consumo = 1000.0 * (i + 1); // Calcular un consumo simulado
        cuentas[i].retirar(consumo, archivoSalida); // Intentar retirar el consumo calculado
        archivoSalida << "Saldo restante: " << cuentas[i].obtenerSaldo() << endl; // Mostrar saldo final
    }

    archivoSalida.close(); // Finalizar y cerrar el archivo
    return 0; // Fin del programa exitosamente
}