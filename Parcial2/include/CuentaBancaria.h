#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
using namespace std;

/**
 * @brief Clase que representa una cuenta bancaria
 * @author Leydi Juliana Solorza Gonzalez
 * @date 2025-04-04
 */
class CuentaBancaria {
private:
    float saldo;                ///< Saldo actual de la cuenta.
    string numeroCuenta;        ///< Número de cuenta.
    bool cuentaBloqueada;       ///< Estado de bloqueo de la cuenta.

public:
    /// Constructor por defecto. Inicializa con saldo 0, número vacío y cuenta desbloqueada.
    CuentaBancaria();

    /// Constructor con parámetros: establece saldo y número de cuenta iniciales, y deja la cuenta desbloqueada.
    CuentaBancaria(float s, string n);

    /**
     * @brief Constructor de copia.
     * @param c Objeto a copiar.
     * Crea una nueva cuenta copiando saldo, número y estado de la cuenta dada.
     */
    CuentaBancaria(const CuentaBancaria& c);

    /// @return Saldo actual de la cuenta.
    float obtenerSaldo() const;

    /// @return Número de cuenta.
    string getNumeroCuenta() const;

    /// Establece un nuevo número de cuenta.
    void setNumeroCuenta(string n);

    /// @return `true` si la cuenta está bloqueada, `false` en caso contrario.
    bool getCuentaBloqueada();

    /**
     * @brief Realiza un depósito en la cuenta.
     * @param cantidad Monto a depositar.
     * @param os Flujo de salida para mostrar mensajes.
     */
    void depositar(float cantidad, ostream& os);

    /**
     * @brief Intenta retirar un monto del saldo.
     * @param cantidad Monto a retirar.
     * @param os Flujo de salida.
     * @return `true` si el retiro fue exitoso, `false` si no hay saldo suficiente o la cuenta está bloqueada.
     */
    bool retirar(float cantidad, ostream& os);

    /**
     * @brief Bloquea la cuenta.
     * @param os Flujo de salida.
     * @return `true` si la cuenta se bloqueó correctamente, `false` si ya estaba bloqueada.
     */
    bool bloquearCuenta(ostream& os);

    /**
     * @brief Desbloquea la cuenta.
     * @param os Flujo de salida.
     * @return `true` si la cuenta se desbloqueó correctamente, `false` si ya estaba desbloqueada.
     */
    bool desbloquearCuenta(ostream& os);

    /**
     * @brief Imprime los datos de la cuenta usando el operador `<<`.
     * @param os Flujo de salida.
     * @param cuenta Objeto a mostrar.
     * @return Flujo de salida.
     */
    friend ostream& operator<<(ostream& os, const CuentaBancaria& cuenta);

    /// Muestra en el flujo de salida toda la información de la cuenta.
    void display(ostream& os);
};

#endif // CUENTABANCARIA_H