package com.company;

public class Cuenta{
    double saldo;
    String nombre;

    Cuenta (double saldo, String nombre){
        this.nombre=nombre;
        this.saldo=saldo;
    }

    double consultaSaldo(){

        return this.saldo;
    }
    void abonoCuenta(double cantidad){

        this.saldo += cantidad;
    }
    double retiroCuenta(double cantidad) {
        if (cantidad <= saldo) {
            this.saldo -= cantidad;
            return consultaSaldo();
        }
        else {
         return -1.0;
        }
    }
}

