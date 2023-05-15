#include <iostream>
#include <iomanip>

void print_array_from_1(int pi[], int m){
    // Print the results
    for (int i = 0; i < m; i++){
        std::cout << std::setfill('0') << std::setw(2) << i+1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m; i++){
        std::cout << " " << pi[i] << " ";
    }
    std::cout << std::endl;
}

void print_array(int pi[], int m){
    // Print the results
    for (int i = 0; i < m; i++){
        std::cout << std::setfill('0') << std::setw(2) << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < m; i++){
        if(pi[i]!=-1){
            std::cout << " " << pi[i] << " ";
        } else {
            std::cout << "   ";
        }
        
    }
    std::cout << std::endl;
}

int* compute_prefix_from_1(char P[], int m){
    int* pi = new int[m];
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q < m; q++){
        while (k > 0 && P[k+1] != P[q]){
            k = pi[k];
        }
        if (P[k+1] == P[q]){
            k = k + 1;
        }
        pi[q] = k;
    }
    return pi;
}

int* KMP_from_1(char T[], int n, char P[], int m){
    int* pi = compute_prefix_from_1(P, m);
    print_array_from_1(pi, m);
    int q = 0;
    int* sol = new int[n];
    for (int i = 0; i < n; i++){
        while (q > 0 && P[q+1] != T[i]){
            q = pi[q];
        }
        if (P[q+1] == T[i]){
            q = q + 1;
        }
        sol[i] = -1;
        if (q == m){
            sol[i] = i - m;
            q = pi[q];
        }
    }

    delete[] pi;

    return sol;
}

int* compute_prefix(char P[], int m){
    int* pi = new int[m];
    pi[0] = -1;
    int k = -1;
    for (int q = 1; q < m-1; q++){
        while (k > -1 && P[k+1] != P[q]){
            k = pi[k];
        }
        if (P[k+1] == P[q]){
            k = k + 1;
        }
        pi[q] = k;
    }
    return pi;
}

int* KMP(char T[], int n, char P[], int m){
    int* pi = compute_prefix(P, m);
    print_array(pi, m);
    int q = -1;
    int* sol = new int[n];
    for (int i = 0; i < n; i++){
        while (q > -1 && P[q+1] != T[i]){
            q = pi[q];
        }
        if (P[q+1] == T[i]){
            q = q + 1;
        }
        sol[i] = -1;
        if (q == m-1){
            std::cout << "i " << i<< std::endl;
            std::cout << "Found at " << i - (m-1) << std::endl;
            sol[i] = i - (m-1);
            q = pi[q];
        }
    }

    delete[] pi;

    return sol;
}

int main() {
    const int n = 12;
    const int m = 6;
    int* sol;
    
    char T[n] = {'a','b','a','b','a','b','a','c','a','b','a','b'};
    char P[m] = {'a','b','a','b','a','c'};
    //char P[m] = {'a','b','a'};

    sol = KMP(T, n, P, m);
    print_array(sol, n);

    return 0;
}
