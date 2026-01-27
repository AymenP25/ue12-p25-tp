#include <iostream>
#include <stdexcept>
#include <vector>

struct Edge;

struct Vertex{

    int name;
    std::vector<Edge*> v;

    Vertex(int a) : name(a){}

    void print(){

        std::cout << "vertex " << name;

    };

};


struct Edge{

    int value;
    Vertex* begin;
    Vertex* end;

    Edge(int a, int b, int p) : value(p), begin(new Vertex(a)), end(new Vertex(b)){} 

    void print(){

        
    }

};

struct Graph{

    int size;
    std::vector<Vertex*> sommets;
    std::vector<Edge*> arrete;

    void add_vertex(int i){
        if (i < sommets.size()){
            throw std::runtime_error("Le vertex existe déjà");

        };

        while (sommets.size()<= i){
        sommets.push_back(new Vertex(sommets.size()));
        }
    }

    void add_edge(int a, int b, int p){
        if (sommets.size() <= a){
            throw std::runtime_error("Le vertex existe déjà");
        }
        for (int i = 0; i< sommets[a]->v.size(); i++){

            if (sommets[a]->v[i]->end->name = b){
                throw std::runtime_error("Le vertex existe déjà");
            }
        }
        sommets[a]->v.push_back(new Edge(a,b,p));
    }

    void print()
    {

        for (int i = 0; i<sommets.size(); i++){
            for (int j = 0; i<sommets[i]->v.size(); j++){
                std::cout<< sommets[i]->name<< "--" << sommets[i]->v[j]->value << "-->" << sommets[i]->v[j]->end->name<<std::endl;

            }

        }

    };
~Graph()
{
    for (int i = 0; i<sommets.size(); i++){
    delete[] sommets[i];
    }
};
    };






int main()
{

    Graph g;
    g.add_vertex(5);
    g.add_edge(5,3,24);
    g.add_edge(2,5,18);
    g.add_edge(3,4,17);
    g.add_edge(4,0,700);
    g.print();

}

