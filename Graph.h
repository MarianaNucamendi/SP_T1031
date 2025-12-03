#pragma once
#include "LinkedList.h"

template <typename T>
class Graph{
public:
    Graph();
    ~Graph();

    bool createGraph(unsigned int newVertexCount);
    bool insertEdge(unsigned int source, unsigned int destiny);
    bool eraseEdge(unsigned int source, unsigned int destiny);
    bool loadFile(std::string fileName);
    bool saveGraph(std::string fileName);
    bool deepSearchFirst(unsigned int source);
    bool breadthSearchFirst(unsigned int source);
    bool bsfPath(unsigned int source, unsigned int destiny, LinkedList<unsigned int> *roomPath);
    void eraseGraph();
    void print();
    unsigned int getVertexCount();
private:
    class Edge{
    public:
        Edge();
        Edge(unsigned int nDestiny);
        unsigned int destiny;
        friend std::ostream& operator<<(std::ostream& os, const Edge &e){
            os << e.destiny;
            return os;  
        }
        bool operator==(const Edge &e){
            return destiny == e.destiny;
        }
        bool operator!=(const Edge &e){
            return destiny != e.destiny;
        }
    };
    class Vertex{
    public:
        Vertex();
        Vertex(T ndata);
        ~Vertex();
        T data;
        LinkedList<Edge> *adjacencyList;
    };
    bool *visited;
    unsigned int *previous;
    
    unsigned int vertexCount;
    Vertex *vertexArray;

    void clearArrays();
};

#include "Graph.tpp"