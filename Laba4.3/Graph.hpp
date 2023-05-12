#ifndef Graph_hpp
#define Graph_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
//template<typename T>
class Graph
{
private:
    struct Edge //ребро
    {
        float weight; // вес ребра
        int id; // индекс вершины, в которую ведет ребро
        vector<Edge> next;
        Edge(float new_weight, int to_id)
        {
            weight = new_weight;
            id = to_id;
        }
    };
    struct Vertex //вершина
    {
        int id; // название вершины
        vector<Edge> edges; // список исходящих ребер
        Vertex(int new_id)
        {
            id = new_id;
        }
    };
    vector<Vertex> graph;
    int size;
public:

    //проверка-добавление-удаление вершин
    int find_vertex(int id);
    void add_vertex(int id);
    bool remove_vertex(int id);
//    std::vector<Vertex> vertices() const;


    //проверка-добавление-удаление ребер
    void add_edge(int from, int to, int weight);
    bool remove_edge(int from, int to);
    bool find_edge(int from, int to);
//    bool has_edge (const Edge& e); //c учетом расстояния в Edge
    
    //получение всех ребер, выходящих из вершины
    std::vector<Edge> edges(const Vertex& vertex);

    size_t order() const; //порядок
    size_t degree() const; //степень


    //поиск кратчайшего пути
    std::vector<Edge> shortest_path(const Vertex& from,
                                        const Vertex& to) const;
    //обход
    std::vector<Vertex>  walk(const Vertex& start_vertex)const;
};
#endif /* Graph_hpp */
