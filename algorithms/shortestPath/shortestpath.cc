#include <iostream>
#include <vector>
#include <queue>
#include <list>

using std::cout;
using std::vector;
using std::queue;
using std::list;

struct node {
	int x;
	int y;
	bool visited;
	node *parent;
};

typedef vector<vector<int>> layout;
// marker on the layout
typedef vector<vector<struct node *>> nodelist;

// this is how you get to the potential neighbors
const int neighbors[4][2] = {
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1}
};

// validates if node can be traversed, that is it is not a -1 or out of bounds
bool isValidNode(const layout &l, const int x, const int y) {
	// first check out of bounds case
	if (x > l.size()-1 or y > l[x].size()-1) {
		return false;
	}
	
	// not out of bounds, check if this can be traversed
	if (l[x][y] != -1) {
		return true;
	}

	// cannot be traversed
	return false;
}

// check if this node is taversed already
bool isVisited(const node *n) {
	return n->visited;	
}

// explore neighbors of start_node and add to the back of the queue
void findNeighbors(const layout &l, nodelist &state, const int x, const int y, queue<struct node *> &q) {
	// loop through current nodes' potential neighbors
	for (int i = 0; i < 4; i++) {
		int newx = x + neighbors[i][0];
		int newy = y + neighbors[i][1];

		if (isValidNode(l, newx, newy)) {
			auto n = state[newx][newy]; 
			
			// add unvisited neighbors
			if (! isVisited(n)) {
				//printf("Current: %d %d, neighbor: %d %d\n", x, y, newx, newy);
				n->parent = state[x][y];
				q.push(n);
			}
		}
	}	
}

void constructFinalPath(struct node *end_node, list<node *> &path) {
	// traverse until start node is hit
	while (end_node) {
		printf("x: %d, y: %d\n", end_node->x, end_node->y);
		if (end_node->x == 0 && end_node->y == 0)
			break;
		path.push_front(end_node);
		end_node = end_node->parent;
	}
};

bool isEqual(int x2, int y2, struct node *n) {
	return (x2 == n->x && y2 == n->y);
}

// Calculates the shortest path between start and end points
// returns a vector of nodes on the shortest path
void shortestPath(const layout &map, nodelist &state, int x1, int y1, int x2, int y2, list<node *> &path) {
	queue<struct node *> q;

	// add neighbors of start_node to queue
	findNeighbors(map, state, x1, y1, q);

	// run till queue is empty or we found the end_node
	while (! q.empty()) {
		auto n = q.front();

		if (isEqual(x2, y2, n)) {
			constructFinalPath(n, path);
			return;
		}

		// find neighbors
		findNeighbors(map, state, n->x, n->y, q);

		// remove first element
		q.pop();
	}	
}


// print out the path
void printPath(const list<node *> &path) {
	for (auto const &n: path) {
		printf("(%d %d)\n", n->x, n->y);
	}
}

int main() {
	layout m {
			{1, 1, 1, 1}, 
			{1, -1, 1, 1}, 
			{1, -1, 1, 1}, 
			{1, -1, 1, 1}
	};

	nodelist nodeStateList{4};
	for (int i = 0; i < 4; i++) {
		nodeStateList[i].resize(4);
		for (int j = 0; j < 4; j++) {
			struct node *n = new struct node;
			n->x = i;
			n->y = j;
			n->visited = false;
			n->parent = nullptr;
			nodeStateList[i][j] = n;	
		}
	}

	printf("Done initializing\n");
	// print node list
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "i: " << nodeStateList[i][j]->x << " ";
			cout << "j: " << nodeStateList[i][j]->y << " ";
			cout << "Visited: " << nodeStateList[i][j]->visited << " ";
			cout << "---\n";
		}
		cout << "++++++++++++++\n";
	}
		
	// print out the map
	for (auto const &r1: m) {
		for (auto const &it: r1) {
			cout << it << " ";
		}
		cout << "\n";
	}

	// calculate shortest path
	list<node *> path;
	shortestPath(m, nodeStateList, 0, 0, 3, 3, path);

	// print out the path
	printPath(path);

	return 0;
}

