/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::infinity()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;						// content of the vertex
	vector<Edge<T> > adj;		// outgoing edges
	
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool visited = false;		// auxiliary field
	bool processing = false;	// auxiliary field

public:
	Vertex(T in);
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;

    void addEdge(Vertex<T> *dest, double w);

	bool operator<(Vertex<T> & vertex) const;

    void setDist(double dist);

    void setInfo(T info);

    void setAdj(const vector<Edge<T>> &adj);

    void setPath(Vertex<T> *path);

    void setQueueIndex(int queueIndex);

    void setVisited(bool visited);

    void setProcessing(bool processing);

    const vector<Edge<T>> &getAdj() const;

    int getQueueIndex() const;

    bool isVisited() const;

    bool isProcessing() const;



    // // required by MutablePriorityQueue
	friend class MutablePriorityQueue<Vertex<T>>;
	friend class Graph<T>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template<class T>
void Vertex<T>::setDist(double dist) {
    Vertex::dist = dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

template<class T>
void Vertex<T>::setInfo(T info) {
    Vertex::info = info;
}

template<class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}

template<class T>
void Vertex<T>::setPath(Vertex<T> *path) {
    Vertex::path = path;
}

template<class T>
void Vertex<T>::setQueueIndex(int queueIndex) {
    Vertex::queueIndex = queueIndex;
}

template<class T>
void Vertex<T>::setVisited(bool visited) {
    Vertex::visited = visited;
}

template<class T>
void Vertex<T>::setProcessing(bool processing) {
    Vertex::processing = processing;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template<class T>
int Vertex<T>::getQueueIndex() const {
    return queueIndex;
}

template<class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template<class T>
bool Vertex<T>::isProcessing() const {
    return processing;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);

    Vertex<T> *getDest() const;

    void setDest(Vertex<T> *dest);

    double getWeight() const;

    void setWeight(double weight);

    friend class Vertex<T>;
    friend class Graph<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *dest) {
    Edge::dest = dest;
}

template<class T>
double Edge<T>::getWeight() const {
    return weight;
}

template<class T>
void Edge<T>::setWeight(double weight) {
    Edge::weight = weight;
}

/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
    vector<vector<double>> D;      // minimum distance matrix
    vector<vector<Vertex<T>*>> P;  // path matrix
public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	// Fp05 - single source
	void unweightedShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);
	void bellmanFordShortestPath(const T &s);
	vector<T> getPathTo(const T &dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;

    friend class Vertex<T>;
    friend class Edge<T>;
};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	for (Vertex<T> *v : vertexSet) {
	    v->dist = INF;
	    v->path = NULL;
	}
	Vertex<T> *start = findVertex(orig);
	start->dist = 0;
	queue<Vertex<T>*> q;
	q.push(start);

	while (!q.empty()) {
	    Vertex<T> *v = q.front();
	    q.pop();
	    for (Edge<T> edge : v->getAdj()) {
	        Vertex<T> *w = edge.dest;
	        if (w->dist == INF) {
	            q.push(w);
	            w->dist = v->dist + 1;
	            w->path = v;
	        }
	    }
	}
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    for (Vertex<T> *v : vertexSet) {
        v->dist = INF;
        v->path = NULL;
    }
    Vertex<T> *start = findVertex(origin);
    start->dist = 0;
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(start);

    while (!q.empty()) {
        Vertex<T> *v = q.extractMin();
        for (Edge<T> edge : v->getAdj()) {
            Vertex<T> *w = edge.dest;
            if (w->dist > v->dist + edge.weight) {
                w->dist = v->dist + edge.weight;
                w->path = v;
                if (w->getQueueIndex() == 0)
                    q.insert(w);
                else
                    q.decreaseKey(w);
            }
        }
    }
}


template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
    for (Vertex<T> *v : vertexSet) {
        v->dist = INF;
        v->path = NULL;
    }
    Vertex<T> *start = findVertex(orig);
    start->dist = 0;
    for (int i = 1; i < vertexSet.size(); i++) {
        for (Vertex<T> *v : vertexSet) {
            for (Edge<T> edge : v->adj) {
                Vertex<T> *w = edge.dest;
                if (w->dist > v->dist + edge.weight) {
                    w->dist = v->dist + edge.weight;
                    w->path = v;
                }
            }
        }
    }
    for (Vertex<T> *v : vertexSet) {
        for (Edge<T> edge : v->adj) {
            if (v->dist + edge.weight < (edge.dest)->dist) {
                cerr << "there are cycles of negative weight\n";
                return;
            }
        }
    }
}


template<class T>
vector<T> Graph<T>::getPathTo(const T &dest) const{
	vector<T> res;
	Vertex<T> *v = findVertex(dest);
    while (v != NULL) {
        res.insert(res.begin(), v->info);
        v = v->path;
    }
	return res;
}



/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {

    const int SIZE = vertexSet.size();

    D.resize(SIZE); P.resize(SIZE);
    for (int i = 0; i < SIZE; i++) {
        D[i].resize(SIZE); P[i].resize(SIZE);
        Vertex<T> *v = vertexSet[i];
        for (int j = 0; j < SIZE; j++) {
            if (i == j) { D[i][j] = 0; P[i][j] = v; continue; }
            D[i][j] = INF; P[i][j] = NULL;
            Vertex<T> *w = vertexSet[j];
            for (Edge<T> edge : v->adj) {
                if (edge.dest == w) {
                    D[i][j] = edge.weight;
                    P[i][j] = edge.dest;
                    break;
                }
            }
        }
    }

    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[i][k];
                }
            }
        }
    }
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const {
	vector<T> res;

	int pos_orig = -1, pos_dest = -1;
	Vertex<T> *origV, *destV;
	for (int i = 0; i < vertexSet.size(); i++) {
	    Vertex<T> *v = vertexSet[i];
	    if (pos_orig == -1 && v->info == orig) {
	        pos_orig = i;
	        origV = v;
	    }
	    if (pos_dest == -1 && v->info == dest) {
            pos_dest = i;
            destV = v;
        }
	    if (pos_orig != -1 && pos_dest != -1) break;
	}

	if (pos_orig == -1 || pos_dest == -1) return res;

    if (D[pos_orig][pos_dest] == INF) return res;

    res.push_back(origV->info);
    while (pos_orig != pos_dest) {
        origV = P[pos_orig][pos_dest];
        res.push_back(origV->info);
        for (int i = 0; i < vertexSet.size(); i++) {
            if (vertexSet[i] == origV) {
                pos_orig = i;
                break;
            }
        }
    }

	return res;
}


#endif /* GRAPH_H_ */
