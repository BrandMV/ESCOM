package com.company;

public class Main {

    public static void main(String[] args) {
        Cuenta cuenta = new Cuenta(1500.00, "Divier");
        System.out.println(cuenta.consultaSaldo());
        System.out.println(cuenta.retiroCuenta(249.98));
        cuenta.abonoCuenta(1300.25);
        System.out.println(cuenta.consultaSaldo());
    }
}
