class SSP {

    static boolean esSumaConjunto(int conjunto[], int n, int sum)
    {
        //* Casos base
        if( sum == 0 )
            return true;
        if( sum < 0 || (n == 0 && sum != 0) )
            return false;

        //* Si el último elemento es mayor a la suma que estamos verificando se ignora
        if (conjunto[n - 1] > sum)
            return esSumaConjunto(conjunto, n - 1, sum);

        //* La primera opciòn es no incluirlo, la segunda es incluirlo
        return esSumaConjunto(conjunto, n - 1, sum)
            || esSumaConjunto(conjunto, n - 1, sum - conjunto[n - 1]);
    }

    public static void main(String args[])
    {
        int conjunto[] = { 2,6,4,8 };
        int sum = 10;
        int n = conjunto.length;
        if (esSumaConjunto(conjunto, n, sum) == true)
            System.out.println("Se encontro un subconjunto con la suma dada");
        else
            System.out.println("Se encontro un subconjunto con la suma dado");
    }
}
