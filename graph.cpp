#include "graph.h"
using namespace std;
#include <iostream>
using namespace std;
Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// ���������� ��� ���������� ������
void Graph::addName_P(string name, int num)
{
    Name_P[num] = name;
}
string  Graph::getName(int num)//������ � ������ ���������� ������
{
    string t = Name_P[num];
    return t;
}

// ���������� �������
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// ���������� �����
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// �������� ������������� �����
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// �������� ������������� �������
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}
void  Graph::width(int start)
{
    int queue_to_visit[SIZE]; // ������� ������ ��� ������
    int queueCount = 0;
    bool visited[SIZE]; // ������ ���������� ������
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // ������ � ������� ��������� �������
    int rpz = 0;// ���������� ����������� 
 
    while ((queueCount > 0) && (rpz < 4))
    {
        // ������ �� ������� �������
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;

        if (rpz == 0) { std::cout << "  uchastnik  socialnoi gruppy '" << getName(current) << "' tesno obschaetcya c : " << endl; }
        else {
            std::cout << rpz << "-e rukopozatie c " << getName(current) << " ; " ;
        }
        rpz++;
        // ����� ������� ������ � ���������� �� � �������
        for (int i = 0; i < SIZE; i++)
        {
            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && edgeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;

        }
        if (queueCount == 0) { std::cout << endl<< " -!- uchastnik  socialnoi gruppy '" << getName(current) << "' NE obschaetcya ni c kem : " << endl; }
    }

    std::cout << std::endl;
}
