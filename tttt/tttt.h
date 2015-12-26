// Topology to LEDs numbers
const byte vertexLeds[] = {49, 47, 45, 43, 41, 25, 33, 31, 29, 27, 24, 22, 20, 18, 16, 9, 7, 5, 3, 1};
const byte edgeLeds[] = {48, 46, 44, 42, 40, 39, 38, 37, 36, 35, 34, 32, 30, 28, 26, 23, 21, 19, 17, 15, 14, 13, 12, 11, 10, 8, 6, 4, 2, 0};

// Face
typedef struct {
  byte antipode;
  byte vertices[5];
  byte edges[5];
} Face;

Face getFace(int f);

const Face faces[12] PROGMEM = {
  {11, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}},
  {10, {0, 6, 12, 7, 1}, {5, 11, 17, 6, 0}},
  {6, {1, 7, 13, 8, 2}, {6, 12, 18, 7, 1}},
  {7, {2, 8, 14, 9, 3}, {7, 13, 19, 8, 2}},
  {8, {3, 9, 10, 5, 4}, {8, 14, 15, 9, 3}},
  {9, {4, 5, 11, 6, 0}, {9, 10, 16, 5, 4}},
  {2, {5, 10, 16, 17, 11}, {15, 20, 26, 21, 10}},
  {3, {6, 11, 17, 18, 12}, {16, 21, 27, 22, 11}},
  {4, {7, 12, 18, 19, 13}, {17, 22, 28, 23, 12}},
  {5, {8, 13, 19, 15, 14}, {18, 23, 29, 24, 13}},
  {1, {9, 14, 15, 16, 10}, {19, 24, 25, 20, 14}},
  {0, {15, 19, 18, 17, 16}, {29, 28, 27, 26, 25}}
};

// Edge
typedef struct {
  byte vertexA;
  byte vertexB;
} Edge;

const Edge edges[30] PROGMEM = { // in order of id
  {0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 4}, {0, 6}, {1, 7}, {2, 8}, {3, 9}, {4, 5}, {5, 11}, {6, 12}, {7, 13}, {8, 14}, {9, 10}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 16}, {11, 17}, {12, 18}, {13, 19}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {15, 19}
};

Edge getEdge(int e);

// Vertex
typedef struct {
  byte edgeA;
  byte edgeB;
  byte edgeC;
} Vertex;

const Vertex vertices[20] PROGMEM = { // in order of id
  {0, 4, 5}, {0, 1, 6}, {1, 2, 7}, {2, 3, 8}, {3, 4, 9}, {10, 15, 9}, {11, 16, 5}, {12, 17, 6}, {13, 18, 7}, {14, 19, 8}, {14, 15, 20}, {10, 16, 21}, {11, 17, 22}, {12, 18, 23}, {13, 19, 24}, {24, 25, 29}, {20, 25, 26}, {21, 26, 27}, {22, 27, 28}, {23, 28, 29}
};

Vertex getVertex(int v);

// Tetrahedron
typedef struct {
  byte vertices[4];
  byte edges[6];
} Tetrahedron;

const Tetrahedron tetrahedra[20] PROGMEM = { // two parities first and second halves
{{0, 8, 10, 18}, {1, 9, 11, 19, 23, 26}},
{{1, 9, 11, 19}, {2, 5, 12, 15, 24, 27}},
{{2, 5, 12, 15}, {3, 6, 13, 16, 20, 28}},
{{3, 6, 13, 16}, {4, 7, 14, 17, 21, 29}},
{{4, 7, 14, 17}, {0, 8, 10, 18, 22, 25}},
{{0, 9, 17, 13}, {3, 16, 6, 20, 13, 28}},
{{1, 5, 18, 14}, {4, 17, 7, 21, 14, 29}},
{{2, 6, 19, 10}, {0, 18, 8, 22, 10, 25}},
{{3, 7, 15, 11}, {1, 19, 9, 23, 11, 26}},
{{4, 8, 16, 12}, {2, 15, 5, 24, 12, 27}}
};

Tetrahedron getTetrahedron(int t);


