# CAL Notes
----
## Dynamic Programming

----
## Greedy Algorithms

----

## Backtracking Algorithms

----
## Divide and Conquer Algorithms

----
## Algorithm Analysis

----
## Graphs
### Graph G = (V, E)
- **V** → set of vertices/nodes
- **E** → set of edges/archs
- an edge is a pair of vertices so that (v, w) | v, w ∈ V
- if the pair is ordered, then the graph is directed (digraph)
- a vertice w is adjacent to a vertice v if and only if (v, w) ∈ E
- in a non-directed graph with an edge (v, w), and so edge (w, v), w is adjacent to v and v is adjacent to w

### Paths
- sequence of vertices v<sub>1</sub>, ..., v<sub>n</sub> so that (v<sub>i</sub>, v<sub>i+1</sub>) ∈ E, 1 ≤ i < n
- the length of a path is the number of edges (n-1 | n=number of vertices)
- if n = 1, the path only has 1 vertice, and so has length 0

#### Simple Path
- every vertice is distinct, with the first and last being posible exceptions

#### Cycles
- path with length ≥ 1 | v<sub>1</sub> = v<sub>n</sub>
- in a non-directed graph, the edges must be different/distinct
###### Ring
    - path v, v ⇒ (v, v) ∈ E, length = 1

#### DAG - Directed Acyclic Graph
- Directed graph without cycles: For any vertice v, there isn't any directed link that begins and ends in v

#### Simple Graph
- Graph without parallel edges (multiple adjacencies for the same pair of vertices), nor rings

#### Dense Graph
