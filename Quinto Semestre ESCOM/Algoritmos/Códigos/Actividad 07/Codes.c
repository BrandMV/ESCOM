int i,j,k,A

int main(){

    return 0;
}

// Codigo 01

func SumaCuadratica3Mayores(A,n){
    if(A[1] > A[2] && A[1] > A[3])
        m1 = A[1];              -- O(1)
        if(A[2] > A[3])
            m2 = A[2];          -- O(1)
            m3 = A[3];          -- O(1)
        else
            m2 = A[3];          -- O(1)
            m3 = A[2];          -- O(1)
    else if(A[2] > A[1] && A[2] > A[3])
        m1 = A[2];              -- O(1)
        if(A[1] > A[3])
            m2 = A[1];          -- O(1)
            m3 = A[3];          -- O(1)
        else   
            m2 = A[3];          -- O(1)
            m3 = A[1];          -- O(1)
    else
        m1 = A[3];
        if(A[1] > A[2])
            m2 = A[1];          -- O(1)
            m3 = A[2];          -- O(1)
        else
            m2 = A[2];          -- O(1)
            m3 = A[1];          -- O(1)

    i = 4;                      -- O(1)

    while(i <= n)               -- O(n)
        if(A[i] > m1)           -- O(1)
            m3 = m2;            -- O(1)
            m2 = m1;            -- O(1)
            m1 = A[i];          -- O(1)
        else if(A[i] > m2)      -- O(1)
            m3 = m2;            -- O(1)
            m2 = A[i];          -- O(1)
        else if (A[i] > m3)     -- O(1)
            m3 = A[i];          -- O(1)

        i = i +1;               -- O(1)
}
// Codigo 02

func ordenamientoINtercambio(A,n){

    for(i=0; i<n-1; i++)      -- O(n)
        for(j=i+1; j<n; j++)  -- O(n)
            if(A[j] < A[i]){
                temp = A[i];  -- O(1)
                A[i] = A[j];  -- O(1)
                A[j] = temp;  -- O(1)
            }
}


// Codigo 03

func MaximoComunDividor(m, n){
    a = max(n,m);           -- O(1)
    b = min(n,m);           -- O(1)
    residuo = 1;
    mientras(residuo > 0){  --O(log(min(n,m)))
        residuo = a mod b;  -- O(1)
        a = b;              -- O(1)
        b = residuo;        -- O(1)
    }

    MaximoComunDividor = a; -- O(1)
    return MaximoComunDividor;

}
// Codigo 04

func sumaCuadratica3MayoresV2(A,n){

    for(i=0; i<3, i++)              -- O(3)
        for(j=0; j<n-1-i; j++)      -- O(n)
            if(A[j] > A[j+1]){
                aux = A[j];         -- O(1)
                A[j] = A[j+1];      -- O(1)
                A[j+1] = aux;       -- O(1) 
            }

    r = A[n-1] + A[n-2] + A[n-3]; -- O(1)
    return pow(r, 2)
}
// Codigo 05

Procedimiento burbujaOptimizada(A,n){
    cambios = "Si";                                 -- O(1)
    i = 0;                                          -- O(1)
    Mientras i < n-1 && cambios != "No" hacer       -- O(n)
        cambios = "No"                              -- O(1)
        Para j = 0 hasta (n-2)-i hacer              -- O(n)
            Si(A[j] < A[j+1]) hacer
                aux = A[j]                          -- O(1)
                A[j] = A[j+1]                       -- O(1)
                A[j+1] = aux                        -- O(1)
                cambios "Si"                        -- O(1)
            FINSI
        FinPara
        i = i+1                                     -- O(1)
    FinMientras
}
// Codigo 06

Procedimiento burbujaSimple(A,n){
    Para i = 0 hasta n-2 hacer                      -- O(n)
        Para j = 0 hasta (n-2)-i hacer              -- O(n)
            Si(A[j] < A[j+1]) hacer
                aux = A[j]                          -- O(1)
                A[j] = A[j+1]                       -- O(1)
                A[j+1] = aux                        -- O(1)
            FINSI
        FinPara
    FinMientras
}
// Codigo 07

Proceso validarPrimo(){
    Leer n                                  -- O(1)
    divisores <- 0                          -- O(1)

    si > 0 Entonces
        Para i <- i Hasta n Hacer           -- O(n)
            si (n % i = 0) Entonces
                divisores = divisores + 1   -- O(1)
            FinSi
        FinPara
    FinPara

    si divisores = 2
        Escribir 'S'                        -- O(1)
    SiNo
        Escribir 'N'                        -- O(1)
    FinSi
}
// Codigo 08

Algoritmo FrecuenciaMinNumeros{
    Leer n                              -- O(1)
    Dimension A[n]                      -- O(1)
    i = 1                               -- O(1)
    Mientras i <= n                     -- O(n)
        Leer A[i]                       -- O(1)
        i = i + 1                       -- O(1)
    FinMientras

    f = 0                               -- O(1)
    i = 1                               -- O(1)
    Mientras i <= n                     -- O(n)
        ntemp = A[i]                    -- O(1)
        j = 1                           -- O(1)
        ftemp = 0                       -- O(1)
        Mientras j <= n                 -- O(n)
            si ntemp = A[j]
                ftemp = ftemp + 1       -- O(1)
            FinSi
            j = j + 1                   -- O(1)
        FinMientras

        si f < ftemp
            f = ftemp                   -- O(1)
            num = ntemp                 -- O(1)
        FinSi

        i = 1 + 1                       -- O(1)
    FinMientras
    Escribir num
}
// Codigo 09

void search(char *pat, char* txt){

    int M = strlen(pat);                                    -- O(M)
    int N = strlen(txt);                                    -- O(N)

    for(int i = 0; i <= N-M; i++){                          -- O(M*(N-M))
        int j;
        for(j = 0; j < M; j++)                              -- O(M)
            if(txt[i + j] != pat[j])
                break;                                      -- O(1)

        if(j == M)
            printf("pattern found at index %d \n", i);      -- O(1)
    }

}

// Codigo 10

stack<int> sortStack(stack<int> &input){
    stack<int> tmpStack;                                        -- O(1)

    while(!input.empty()){                                      -- O(n)
        int tmp = input.pop();                                  -- O(1)
        input.pop();                                            -- O(1)

        while(!tmpStack.empty() && tmpStack.top() > tmp){       -- O(n)
            input.push(tmpStack.top());                         -- O(1)
            tmpStack.pop();                                     -- O(1)
        }

        tmpStack.push(tmp);                                     -- O(1)
    }

    return tmpStack;
}
