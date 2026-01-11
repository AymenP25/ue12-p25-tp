#include <iostream>
#include <stdexcept>

class Stack {

private:
    int* tab;
    int size;
    int nb;

public:
    // Constructeur
    Stack(int s) {
        size = s;
        nb = 0;
        tab = new int[size];
    }

    // Destructeur
    ~Stack() {
        delete[] tab;
    }

    // Constructeur de copie
    Stack(const Stack& other) {
        size = other.size;
        nb = other.nb;
        tab = new int[size];

        for (int i = 0; i < nb; i++) {
            tab[i] = other.tab[i];
        }
    }

    // Opérateur d'affectation
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            
            size = other.size;
            nb = other.nb;
            delete[] tab;
            tab = new int[size];
            

            for (int i = 0; i < nb; i++) {
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }

    bool is_empty() {
        return nb == 0;
    }

    bool is_full() {
        return nb == size;
    }

    void push(int value) {
        if (is_full())
            throw std::overflow_error("pile pleine");

        tab[nb] = value;
        nb++;
    }

    int pop() {
        if (is_empty())
            throw std::underflow_error("pile vide");

        nb--;
        return tab[nb];
    }

    int top() {
        if (is_empty())
            throw std::underflow_error("pile vide");

        return tab[nb - 1];
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < nb; i++)
            std::cout << tab[i] << " ";
        std::cout << "[\n";
    }
};
