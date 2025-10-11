#include <iostream>
#include <random>
#include <thread>
#include <vector>
using namespace std;

void print(int** A, int fil, int col) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] == 9)
                cout << "* ";
            else
                cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void procesar(int** A, int fil, int col, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        for (int j = 0; j < col; j++) {
            if (A[i][j] != 9) {
                int conteo = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < fil && nj >= 0 && nj < col && A[ni][nj] == 9)
                            conteo++;
                    }
                }
                A[i][j] += conteo;
            }
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1);

    int fil = 10, col = 10;
    int** p = new int*[fil];
    for (int i = 0; i < fil; i++) {
        p[i] = new int[col];
        for (int j = 0; j < col; j++)
            p[i][j] = (dist(gen) == 1) ? 9 : 0;
    }

    cout << "Solo minas:" << endl;
    print(p, fil, col);

    // Crear 4 threads
    int numThreads = 4;
    int bloque = fil / numThreads;
    vector<thread> hilos;

    for (int t = 0; t < numThreads; t++) {
        int inicio = t * bloque;
       int fin;
        if (t == numThreads - 1)
            fin = fil;
        else
            fin = inicio + bloque;
        hilos.emplace_back(procesar, p, fil, col, inicio, fin);
    }

    for (auto& h : hilos) h.join();

    cout << endl << "Solucion:" << endl;
    print(p, fil, col);

    for (int i = 0; i < fil; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}
