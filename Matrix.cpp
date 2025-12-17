#include <iostream>

struct Buffer
{
    int size;
    int cpt = 0;
    double *tab;

    Buffer(int a) : size(a), tab(new double[a]) {}
    ~Buffer()
    {
        delete[] tab;
    }
};

struct Matrix
{
    int nbl;
    int nbc;
    Buffer *M;

    Matrix(int a, int b) : nbl(a), nbc(b), M(new Buffer(nbl * nbc))
    {
        M->cpt = M->cpt + 1;
    }

    Matrix(int a, int b, Buffer *c) : nbl(a), nbc(b), M(c)
    {
        M->cpt = M->cpt + 1;
    }

    ~Matrix()
    {
        M->cpt--;
        if (M->cpt<=0)
        {
            std::cout << "ici" << std::endl;
            delete M; 
        }


    }

    int flatten_index(int i, int j)
    {
        return i * nbc + j;
    }

    void set(int i, int j, double value)
    {
        M->tab[flatten_index(i, j)] = value;
    }

    double get(int i, int j)
    {

        return M->tab[i * nbl + j];
    }

    Matrix reshape(int L, int C)
    {
        return Matrix(L, C, M);
    }

    void print()
    {
        std::cout<< "[ ";
        for (int i = 0; i < nbl; i++)
        {
            std::cout<<"[";
            for (int j = 0; j < nbc; j++)
            {

                std::cout << M->tab[flatten_index(i, j)] << " ";
            }
            std::cout<<"]"<<std::endl;
    }
    std::cout<<" ]"<<std::endl;
};
};


int main(){

    Matrix m(4,3);
    m.set(0,0,17.3);
    m.print();

    double d=m.get(0,0);
    Matrix h = m.reshape(2,6);
    h.set(0,0,21.3);
    h.print();

};