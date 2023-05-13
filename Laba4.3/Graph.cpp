#include "Graph.hpp"

Graph:: ~Graph()
{
    graph.clear();
}


int Graph:: find_vertex(int value)
{
//    vector<Vertex>:: iterator it;
//    it = find(graph.begin(), graph.end(), id);
//    if(it != graph.end())
//        return int(it - graph.begin());
//
    if(graph.size()==0) return -1;
    
    for(auto i = graph.begin(); i != graph.end(); i++)
    {
        if(i->id == value)
            return int(i - graph.begin());
    }
    return -1;
}


void Graph:: add_vertex(int id)
{
    if(find_vertex(id) != -1) throw EUncorrectIndex();
    Vertex v(id);
    graph.push_back(v);
}


bool Graph:: remove_vertex(int id)
{
    int index = find_vertex(id);
    if(index == -1) throw EUnpossibal();
    
    for(auto i = graph.begin(); i != graph.end(); i++)
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
    if(graph.size()==0) return false;
    int i_from = find_vertex(from);
    int i_to = find_vertex(to);
    if(i_to == -1 || i_from == -1) throw EUnpossibal();
    
    for(auto i = graph[i_from].edges.begin(); i != graph[i_from].edges.end(); i++)
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
    if(i_to == -1 || i_from == -1) throw EUnpossibal();
    if(find_edge(from, to)) throw EUncorrectIndex();
    
    Edge tmp(weight, to);
    graph[i_from].edges.push_back(tmp);
}
bool Graph:: remove_edge(int from, int to)
{
    int i_from = find_vertex(from);
    int i_to = find_vertex(to);
    if(i_to == -1 || i_from == -1) throw EUnpossibal();
    if(!find_edge(from, to)) throw EUnpossibal();
    
    graph[i_from].edges.erase(graph[i_from].edges.begin() + i_to);
    return true;
}


void Graph:: print()
{
    for(auto i = graph.begin(); i != graph.end(); i++)
    {
        cout << i->id << ": ";
        for(auto j = i->edges.begin(); j != i->edges.end(); j++)
        {
            cout << j->id << ", ";
        }
        cout << endl;
    }
}

vector<Edge> Graph:: edges(int from)
{
    int index = find_vertex(from);
    if(index == -1) throw EUnpossibal();
    
    return graph[index].edges;
}

int Graph:: order()
{
    return int(graph.size());
}//порядок число вершин


int Graph:: degree(int id)
{
    int index = find_vertex(id);
    if(index == -1) throw EUnpossibal();
    
    int count = 0;
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        if(find_edge(i->id, index))
            count++;
    }
    return count;
}//степень входящие
//поиск кратчайшего пути

vector<Edge> Graph:: shortest_path(int from, int to)
{
    vector<Edge> result;
    return result;
}
//обход

void Graph:: clean_color()
{
    for(auto i = graph.begin(); i != graph.end(); i++)
    {
        i->color = 0;
    }
}
void Graph:: walk(int from)
{
    int index = find_vertex(from);
// if(index == -1) throw EUncorrectIndex();
    cout << graph[index].id;
    graph[index].color = 1;
    for(auto i = graph[index].edges.begin(); i != graph[index].edges.end(); i++)
    {
        int tmp = find_vertex(i->id);
        if (graph[tmp].color == 0)
        {
            cout << " -> ";
            walk(i->id);
        }
    }
//    cout << graph[index].id << " -> ";
    graph[index].color = 2;
}
