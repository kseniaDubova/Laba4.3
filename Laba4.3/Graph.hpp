#ifndef Graph_hpp
#define Graph_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include "ESetErrors.hpp"
#include <algorithm>
using namespace std;
//template<typename T>
struct Edge //ребро
{
    float weight; // вес ребра
    int id; // индекс вершины, в которую ведет ребро
//        vector<Edge> next;
    Edge(float new_weight, int to_id)
    {
        weight = new_weight;
        id = to_id;
    }
};
struct Vertex //вершина
{
    int id;
    int color;// название вершины
    vector<Edge> edges; // список исходящих ребер
    Vertex(int new_id)
    {
        id = new_id;
        color = 0;
    }
};
class Graph
{
private:
    vector<Vertex> graph;
public:
    ~Graph();
    //проверка-добавление-удаление вершин
    int find_vertex(int id);
    void add_vertex(int id);
    bool remove_vertex(int id);
    //проверка-добавление-удаление ребер
    void add_edge(int from, int to, int weight);
    bool remove_edge(int from, int to);
    bool find_edge(int from, int to);
    void print();
    //получение всех ребер, выходящих из вершины
    vector<Edge> edges(int from);
    int order(); //порядок число вершин
    int degree(int id); //степень входящие
    //поиск кратчайшего пути
    vector<Edge> shortest_path(int from, int to);
    //обход
    void clean_color();
    void walk(int from);
};
#endif /* Graph_hpp */
