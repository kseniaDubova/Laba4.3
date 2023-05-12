#include "Graph.hpp"

int Graph:: find_vertex(int id)
{
//    vector<Vertex>:: iterator it;
//    it = find(graph.begin(), graph.end(), id);
//    if(it != graph.end())
//        return int(it - graph.begin());
//
    for(auto i = graph.begin(); i != graph.end() - 1; i++)
    {
        if(i->id == id)
            return int(i - graph.begin());
    }
    return -1;
}


void Graph:: add_vertex(int id)
{
    if(find_vertex(id) != -1) throw "Vertex is exist";
    Vertex v(id);
    graph.push_back(v);
}


bool Graph:: remove_vertex(int id)
{
    int index = find_vertex(id);
    if(index == -1) throw "Vertex is not exist";
    
    for(auto i = graph.begin(); i != graph.end() - 1; i++)
    {
        if(find_edge(i->id, id))
            remove_edge(i->id, id);
    }
    graph[index].edges.clear();
    graph.erase(graph.begin() + index);
    return true;
}


bool Graph:: find_edge(int from, int to)
{
    int i_from = find_vertex(from);
    int i_to = find_vertex(to);
    if(i_to == -1 || i_from == -1) throw "Vertex is not exist";
    
    for(auto i = graph[i_from].edges.begin(); i != graph[i_from].edges.end() - 1; i++)
    {
        if(i->id == to)
            return true;
    }
    return false;
}

void Graph:: add_edge(int from, int to, int weight)
{
    int i_from = find_vertex(from);
    int i_to = find_vertex(to);
    if(i_to == -1 || i_from == -1) throw "Vertex is not exist";
    if(find_edge(from, to)) throw "Edge is exist";
    
    Edge tmp(weight, to);
    graph[i_from].edges.push_back(tmp);
}
bool Graph:: remove_edge(int from, int to)
{
    int i_from = find_vertex(from);
    int i_to = find_vertex(to);
    if(i_to == -1 || i_from == -1) throw "Vertex is not exist";
    if(!find_edge(from, to)) throw "Edge is not exist";
    
    graph[i_from].edges.erase(graph[i_from].edges.begin() + i_to);
    return true;
}

