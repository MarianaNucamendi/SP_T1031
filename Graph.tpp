#include "Graph.h"
#include "LinkedList.h"
#include "stack.h"
#include "queue.h"
#include <fstream>
#include <sstream>
#include <climits>

template <typename T>
Graph<T>::Edge::Edge(){}

template <typename T>
Graph<T>::Edge::Edge(unsigned int nDestiny) : destiny(nDestiny) {}

template <typename T>
Graph<T>::Vertex::Vertex() : adjacencyList(nullptr) {}

template <typename T>
Graph<T>::Vertex::Vertex(T nData) : adjacencyList(nullptr), data(nData) {}

template <typename T>
Graph<T>::Vertex::~Vertex(){
    if(adjacencyList){
        delete adjacencyList;
        adjacencyList = nullptr;
    }
}

template <typename T>
Graph<T>::Graph() : visited(nullptr), previous(nullptr), vertexCount(0), vertexArray(nullptr) {}

template <typename T>
Graph<T>::~Graph(){
    eraseGraph();
}

template <typename T>
bool Graph<T>::createGraph(unsigned int newVertexCount){
    if(vertexArray)
        return false;

    vertexArray = new(std::nothrow) Vertex[newVertexCount];
    if(!vertexArray)
        return false;

    visited = new(std::nothrow) bool[newVertexCount];
    if(!visited){
        delete[] vertexArray;
        return false;
    }

    previous = new(std::nothrow) unsigned int[newVertexCount];
    if(!previous){
        delete[] vertexArray;
        delete[] visited;
        return false;
    }

    for(unsigned int i = 0; i < newVertexCount; i++){
        vertexArray[i].adjacencyList = new(std::nothrow) LinkedList<Edge>;
        if(!vertexArray[i].adjacencyList){
            delete[] vertexArray;
            delete[] visited;
            return false;
        }     
    }

    clearArrays();

    vertexCount = newVertexCount;
    return true;
}

template <typename T>
bool Graph<T>::insertEdge(unsigned int source, unsigned int destiny){
    if(!vertexArray)
        return false;

    if(source >= vertexCount || destiny >= vertexCount)
        return false;

    if(vertexArray[source].adjacencyList->exists(destiny))
        return false;

    if(!vertexArray[source].adjacencyList->insertTail(destiny))
        return false;

    return true;
}

template <typename T>
bool Graph<T>::eraseEdge(unsigned int source, unsigned int destiny){
    if(!vertexArray)
        return false;

    if(source >= vertexCount || destiny >= vertexCount)
        return false;
    
    if(!vertexArray[source].adjacencyList->exists(destiny))
        return false;

    if(!vertexArray[source].adjacencyList->deleteNode(destiny))
        return false;
    return true;
}

template <typename T>
bool Graph<T>::loadFile(std::string fileName){
    std::ifstream file(fileName);

    if(!file.is_open())
        return false;

    std::string line;

    if(!std::getline(file, line)){
        file.close();
        return false;
    }

    std::getline(file, line);
    unsigned int vertexCount = std::stoul(line);
    createGraph(vertexCount);
    unsigned int index = 0;

    while(index != vertexCount){
        std::getline(file, line);
        std::stringstream ss(line);
        std::string cell;

        while(std::getline(ss, cell, ' ')){
            unsigned int cellInt = std::stoul(cell); 
            insertEdge(index, cellInt);
        }
        index++;
    }
    file.close();
    return true;
}

template <typename T>
bool Graph<T>::saveGraph(std::string fileName){
    if(!vertexArray)
        return false;

    std::ofstream file(fileName);

    if(!file.is_open())
        return false;

    file << "Grafo\n";

    file << vertexCount;
    file << '\n';

    for(unsigned int i = 0; i < vertexCount; i++){
        for(auto it = vertexArray[i].adjacencyList->begin(); it != vertexArray[i].adjacencyList->end(); it++){
            file << *it;
            file << ' ';
        }
        file << '\n';
    }

    file.close();
    return true;
}

template <typename T>
bool Graph<T>::deepSearchFirst(unsigned int source){
    if(!vertexArray || source >= vertexCount)
        return false;

    clearArrays();

    visited[source] = true;

    std::cout << source << " ";
    
    Stack<unsigned int> stack;
    stack.push(source);

    unsigned int current = 0;
    
    while(!stack.isEmpty()){
        current = *stack.getTop();
        stack.pop();
        for(auto it = vertexArray[current].adjacencyList->begin(); it != vertexArray[current].adjacencyList->end(); it++){
            if(!visited[it->destiny]){
                visited[it->destiny] = true;
                std::cout << it->destiny << " ";
                stack.push(it->destiny);
            }
        }
    }
    std::cout << "\n";
    return true;
}

template <typename T>
bool Graph<T>::breadthSearchFirst(unsigned int source){
    if(!vertexArray || source >= vertexCount)
        return false;

    clearArrays();

    visited[source] = true;

    std::cout << source << " ";
    Queue<unsigned int> queue;
    queue.enqueue(source);

    unsigned int current = 0;

    while(!queue.isEmpty()){
        current = *queue.getFront();
        queue.dequeue();
        for(auto it = vertexArray[current].adjacencyList->begin(); it != vertexArray[current].adjacencyList->end(); it++){
            if(!visited[it->destiny]){
                visited[it->destiny] = true;
                std::cout << it->destiny << " ";
                queue.enqueue(it->destiny);
            }
        }
    }
    std::cout << "\n";
    return true;
}

template <typename T>
bool Graph<T>::bsfPath(unsigned int source, unsigned int destiny, LinkedList<unsigned int> *roomPath){
    if(!vertexArray || source >= vertexCount)
        return false;

    if(source == destiny)
        return false;

    clearArrays();

    Queue<unsigned int> queue;
    visited[source] = true;
    queue.enqueue(source);

    bool found = false;
    unsigned int current = 0;

    while(!queue.isEmpty() || !found){
        current = *queue.getFront();
        queue.dequeue();
        for(auto it = vertexArray[current].adjacencyList->begin(); it != vertexArray[current].adjacencyList->end(); it++){
            if(!visited[it->destiny]){
                visited[it->destiny] = true;
                previous[it->destiny] = current;
                if(it->destiny == destiny)
                    found = true;
                queue.enqueue(it->destiny);
            }
        }
    }
    
    if(!found)
        return false;

    current = destiny;
    Stack<unsigned int> stack;
    stack.push(destiny);

    while(previous[current] != UINT_MAX){
        stack.push(previous[current]);
        roomPath->insertHead(previous[current]);
        current = previous[current];
    }

    std::cout << "path: ";

    while(!stack.isEmpty()){
        std::cout << *stack.getTop() << " ";
        stack.pop(); 
    }

    std::cout << "\n";

    return true;
}

template <typename T>
void Graph<T>::eraseGraph(){
    if(vertexArray){
        delete[] vertexArray;
        vertexArray = nullptr;
        delete[] visited;
        visited = nullptr;
        delete[] previous;
        previous = nullptr;
        vertexCount = 0;

    }
}

template <typename T>
void Graph<T>::print(){
    for(unsigned int i = 0; i < vertexCount; i++){
        if(vertexArray)
            vertexArray[i].adjacencyList->printList();
        std::cout << "\n";
    }
}

template <typename T>
void Graph<T>::clearArrays(){
    for(unsigned int i = 0; i < vertexCount; i++){
        visited[i] = false;
        previous[i] = UINT_MAX;
    }
}

template <typename T>
unsigned int Graph<T>::getVertexCount(){
    return vertexCount;
}