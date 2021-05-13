using namespace std;

class Node {
private:
	int x;
	int y;
	Node* left;
	Node* right;
	int height;
public:
	Node(int incX, int incY) {
		x = incX;
		y = incY;
	}
	void setLeft(Node* n) {
		left = n;
	}
	Node* getLeft() {
		return left;
	}
	void setRight(Node* n) {
		right = n;
	}
	Node* getRight() {
		return right;
	}
	void setHeight(int h) {
		height = h;
	}
	int getHeight() {
		return height;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getHeight(Node* n)
	{
		if (n == nullptr)
			return 0;
		return n->getHeight();
	}
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
};

class Tree {
private:

public:
	Node* addNode(int x, int y) {
		Node* newNode = new Node(x, y);
		newNode->setLeft(nullptr);
		newNode->setRight(nullptr);
		newNode->setHeight(1);
		return newNode;
	}
	Node* insert(Node* n, int key, int y) {
		if (n == nullptr) { //only for first add
			return addNode(key, y);
		}
		if (key < n->getX()) { //compares key of previous with current
			n->setLeft(insert(n->getLeft(), key, y)); //getLeft is nullptr
		}
		else if (key > n->getX()) {
			n->setRight(insert(n->getRight(), key, y));
		}
		//are equal keys allowed?
		else {
			cout << "Not adding same key" << endl;
			return n;
		}
		n->setHeight(1 + n->max(n->getHeight(n->getLeft()), n->getHeight(n->getRight())));
		return n;
		
	}
	void print(Node* root) {
		if (root != nullptr) {
			//prints first node, then all to the left, then all to the right

			cout << root->getX() << ", " << root->getY() << endl;
			print(root->getLeft());
			print(root->getRight());
		}
	}

};