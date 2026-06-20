#include "../include/CuentaBancaria.h" // Inclusión del encabezado de la clase CuentaBancaria
#include <string> // Para usar objetos de tipo string
#include <iostream> // Para operaciones de entrada y salida estándar

// Constructor sin parámetros: inicializa la cuenta en estado básico
CuentaBancaria::CuentaBancaria(void) {
    saldo = 0.0; // Saldo inicial en cero
    numeroCuenta = ""; // Sin número asignado inicialmente
    cuentaBloqueada = false; // La cuenta comienza desbloqueada
}

// Constructor con parámetros: configura los valores iniciales
CuentaBancaria::CuentaBancaria(float s, string n) {
    saldo = s; // Se establece el saldo inicial
    numeroCuenta = n; // Se asigna el número de cuenta
    cuentaBloqueada = false; // La cuenta permanece activa
}

// Constructor de copia: clona los datos de otra cuenta
CuentaBancaria::CuentaBancaria(const CuentaBancaria& c) {
    saldo = c.saldo; // Copia del saldo original
    numeroCuenta = c.numeroCuenta; // Copia del número de cuenta
    cuentaBloqueada = c.cuentaBloqueada; // Copia del estado de bloqueo
}

// Métodos de acceso (getters)
float CuentaBancaria::obtenerSaldo() const {
    return saldo; // Devuelve el saldo actual
}

string CuentaBancaria::getNumeroCuenta() const {
    return numeroCuenta; // Devuelve el número de cuenta
}

void CuentaBancaria::setNumeroCuenta(string n) {
    numeroCuenta = n; // Cambia el número de cuenta
}

bool CuentaBancaria::getCuentaBloqueada() {
    return cuentaBloqueada; // Informa si la cuenta está bloqueada
}

// Método para depositar dinero en la cuenta
void CuentaBancaria::depositar(float cantidad, ostream& os) {
    if (cuentaBloqueada) {
        os << "La cuenta esta bloqueada, no se puede depositar." << endl; // Depósito rechazado por bloqueo
    } else {
        os << "Depositando " << cantidad << " en la cuenta." << endl; // Confirmación del depósito
        saldo += cantidad; // Aumento del saldo
    }
}

// Método para retirar dinero de la cuenta
bool CuentaBancaria::retirar(float cantidad, ostream& os) {
    if (cuentaBloqueada) {
        os << "La cuenta esta bloqueada, no se puede retirar." << endl; // No se permite retiro
        return false;
    } else if (cantidad > saldo) {
        os << "No hay suficiente saldo para retirar " << cantidad << endl; // Saldo insuficiente
        os << "bloqueando cuenta..." << endl; // Acción de seguridad
        bloquearCuenta(os); // Se bloquea la cuenta por intento fallido
        return false;
    }
    os << "Retirando " << cantidad << " de la cuenta." << endl; // Retiro exitoso
    saldo -= cantidad; // Se descuenta el saldo
    return true;
}

// Método para bloquear la cuenta
bool CuentaBancaria::bloquearCuenta(ostream& os) {
    if (cuentaBloqueada) {
        os << "La cuenta ya esta bloqueada." << endl; // No se puede volver a bloquear
        return false;
    }
    cuentaBloqueada = true; // Cambia el estado a bloqueado
    return cuentaBloqueada;
}

// Método para desbloquear la cuenta
bool CuentaBancaria::desbloquearCuenta(ostream& os) {
    if (!cuentaBloqueada) {
        os << "La cuenta ya esta desbloqueada." << endl; // Ya está desbloqueada
        return false;
    }
    cuentaBloqueada = false; // Se reactiva la cuenta
    return !cuentaBloqueada;
}

// Definición del operador << para mostrar una cuenta por consola
ostream& operator<<(ostream& os, const CuentaBancaria& c) {
    os << "Numero de cuenta: " << c.numeroCuenta << ", Saldo: " << c.saldo; // Formato de impresión
    return os;
}

// Muestra detallada del estado de la cuenta
void CuentaBancaria::display(ostream& os) {
    os << "Numero de cuenta: " << numeroCuenta << ", Saldo: " << saldo << endl; // Presentación de datos
}