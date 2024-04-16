#pragma once 
#define __GRAPH__
#define SIZE 10
#include <iostream>
using namespace std;
class  Graph {
public:
    Graph();
    // ���������� ��� �������������
    void addName_P(string name, int num);
    // ���������� �������
    void addVertex(int vnumber);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);
    // �������� �������
    void delVertex(int vnumber);
    // �������� �����
    void delEdge(int v1, int v2);
    //����� ���������� �����
    int findPathCount(int v1, int v2);
   // int dummy1(int v1, int v2);
   // void dummy2(void** param);
    void   width(int start);
    string   getName(int num);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);
    int matrix[SIZE][SIZE]; // ������� ���������
    string Name_P[SIZE]; // ��������� ��� �������������
    int vertexes[SIZE]; // ��������� ������
    int vertexCount; // ���������� ����������� ������
    int num; string name;
};
 