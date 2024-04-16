#pragma once 
#define __GRAPH__
#define SIZE 10
#include <iostream>
using namespace std;
class  Graph {
public:
    Graph();
    // добавление имён пользователей
    void addName_P(string name, int num);
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // удаление вершины
    void delVertex(int vnumber);
    // удаление ребра
    void delEdge(int v1, int v2);
    //поиск количества путей
    int findPathCount(int v1, int v2);
   // int dummy1(int v1, int v2);
   // void dummy2(void** param);
    void   width(int start);
    string   getName(int num);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);
    int matrix[SIZE][SIZE]; // матрица смежности
    string Name_P[SIZE]; // хранилище имён пользователей
    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
    int num; string name;
};
 