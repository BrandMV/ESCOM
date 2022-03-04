class SSP {

    static boolean esSumaConjunto(int conjunto[], int n, int sum)
    {
        boolean subconjunto[][] = new boolean[n + 1][sum + 1];

        //*Si la suma a buscar es 0, se regresa true
        for(let i=0; i<= n; i++)
        subconjunto[i][0] = true;

        //*Si la suma no es 0, pero el conjunto es vacio se regresa false
        for(let i = 1; i <= sum; i++)
            subconjunto[0][i] = false;

        //*Se llena la tabla recorriendo la suma y los elementos del conjunto
        for(let i=1; i <= n; i++){
            for(let j=1; j <= sum; j++){
                //*Si el elemento actual es mayor al valor actual de la suma copiamos el valor del caso anterior
                if(j < conjunto[i - 1])
                    subconjunto[i][j] = subconjunto[i-1][j];
                //*Si el valor actual de la suma es mayor que el iesimo elemento
                //*]hacemos or entre los casos previos y el caso de j-valor de suma actual
                if(j >= conjunto[i-1])
                    subconjunto[i][j] = subconjunto[i-1][j] || subconjunto[i-1][j-conjunto[i-1]];
            }
        }

        return subconjunto[n][sum];
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


class SSP {

    static boolean esSumaConjunto(int conjunto[], int n, int sum)
    {
        int tab[][] = new int[n + 1][sum + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                tab[i][j] = -1;
            }
        }

        if (sum == 0)
            return 1;

        if (n <= 0)
            return 0;

        if (tab[n - 1][sum] != -1)
            return tab[n - 1][sum];

        if (conjunto[n - 1] > sum)
            return tab[n - 1][sum]
                = esSumaConjunto(conjunto, n - 1, sum);
        else {
            if (esSumaConjunto(conjunto, n - 1, sum) != 0 || esSumaConjunto(conjunto, n - 1, sum - conjunto[n - 1]) != 0) {
                return tab[n - 1][sum] = 1;
            }
            else
                return tab[n - 1][sum] = 0;
        }
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