#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1() {
    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->setBackground("../resources/images/background.png");
    gv->createWindow(206, 197);
    gv->defineVertexColor("pink");
    gv->defineEdgeColor("black");


    gv->addNode(0);
    gv->addNode(1);
    gv->addNode(2);
    gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
    gv->addEdge(1, 1, 2, EdgeType::DIRECTED);
    gv->addEdge(2, 0, 2, EdgeType::UNDIRECTED);
    gv->setVertexLabel(0, "node 0");
    gv->setEdgeLabel(0, "edge 0");
    gv->setVertexColor(0, "blue");
    gv->setEdgeColor(0, "red");
    gv->rearrange();

    getchar();

    gv->closeWindow();
    delete gv;
}

void exercicio2() {
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("../resources/images/background2.gif");
    gv->createWindow(600, 600);
    gv->defineVertexColor("pink");
    gv->defineEdgeColor("black");

    gv->addNode(0, 300, 50);
    gv->addNode(1, 318, 58);
    gv->addNode(2, 325, 75);
    gv->addNode(3, 318, 93);
    gv->addNode(4, 300, 100);
    gv->addNode(5, 282, 93);
    gv->addNode(6, 275, 75);
    gv->addNode(7, 282, 58);
    gv->addNode(8, 150, 200);
    gv->addNode(9, 300, 200);
    gv->addNode(10, 450, 200);
    gv->addNode(11, 300, 400);
    gv->addNode(12, 200, 550);
    gv->addNode(13, 400, 550);

    gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
    gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
    gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
    gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
    gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
    gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
    gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
    gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);
    gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
    gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
    gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
    gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
    gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
    gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);
    gv->rearrange();

    for (int i = 0; i < 10; i++) {
        Sleep(1000);

        gv->removeNode(8);
        gv->removeNode(10);
        gv->addNode(14, 150, 100);;
        gv->addNode(15, 450, 100);
        gv->addEdge(14, 9, 14, EdgeType::UNDIRECTED);
        gv->addEdge(15, 9, 15, EdgeType::UNDIRECTED);
        gv->rearrange();

        Sleep(1000);

        gv->removeNode(14);
        gv->removeNode(15);
        gv->addNode(8, 150, 200);;
        gv->addNode(10, 450, 200);
        gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
        gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
        gv->rearrange();
    }

    getchar();

    gv->closeWindow();
    delete gv;
}

void exercicio3() {
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("../resources/images/background3.gif");
    gv->createWindow(600, 600);
    gv->defineVertexColor("pink");
    gv->defineEdgeColor("black");

    ifstream node_in("../resources/mapa1/nos.txt", std::ios::out);
    string line;
    char c;
    int id, x, y;
    while (getline(node_in, line)) {
        istringstream ss(line);
        ss >> id >> c >> x >> c >> y;
        gv->addNode(id, x, y);
    }

    node_in.close();

    ifstream edge_in("../resources/mapa1/arestas.txt", std::ios::out);

    while (getline(edge_in, line)) {
        istringstream ss(line);
        ss >> id >> c >> x >> c >> y;
        gv->addEdge(id, x, y, EdgeType::UNDIRECTED);
    }

    edge_in.close();

    gv->rearrange();

    getchar();

    gv->closeWindow();
    delete gv;
}

int main() {
    //exercicio1();

    //exercicio2();

    exercicio3();

	return 0;
}
