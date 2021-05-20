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
		left = nullptr;
		right = nullptr;
		height = 1;
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
	void setX(int incX) {
		x = incX;
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
	int getBalance(Node* n) {
		if (n == nullptr)
			return 0;
		return n->getHeight(getLeft()) - n->getHeight(getRight());
	}
};

class Tree {
private:
	int nodes;
public:
	Tree(){
		nodes = 0;
	}
	Node* addNode(int x, int y) {
		nodes++;
		Node* newNode = new Node(x, y);
		newNode->setLeft(nullptr);
		newNode->setRight(nullptr);
		newNode->setHeight(1);
		return newNode;
	}
	Node* deleteNode(Node* root, int key) {
		if (root != nullptr) {
			if (root->getX() == key) {
				if ((root->getLeft() == nullptr) || (root->getRight() == nullptr))
				{
					Node* temp = root->getLeft() ? root->getLeft() : root->getRight();

					// No child case 
					if (temp == nullptr)
					{
						temp = root;
						root = nullptr;
					}
					else // One child case 
						*root = *temp; // Copy the contents of 
									   // the non-empty child 
					free(temp);
				}
				else
				{
					// node with two children: Get the inorder 
					// successor (smallest in the right subtree)

					Node* temp = minValueNode(root->getRight());

					// Copy the inorder successor's 
					// data to this node 
					root->setX(temp->getX());

					// Delete the inorder successor 
					root->setRight(deleteNode(root->getRight(), temp->getX()));
				}
				nodes--;
				//cout << "\ndeleted: " << key << endl;
			}
			else {
				// If the key to be deleted is smaller 
				// than the root's key, then it lies
				// in left subtree 
				if (key < root->getX())
					root->setLeft(deleteNode(root->getLeft(), key));

				// If the key to be deleted is greater 
				// than the root's key, then it lies 
				// in right subtree 
				else if (key > root->getX())
					root->setRight(deleteNode(root->getRight(), key));
			}
		}
		return root;
	}
	Node* minValueNode(Node* n)
	{
		Node* current = n;

		/* loop down to find the leftmost leaf */
		while (current->getLeft() != nullptr)
			current->setLeft(current->getLeft());

		return current;
	}

	Node* rotateRight(Node* y) {
		Node* x = y->getLeft();
		Node* T2 = x->getRight();

		// Perform rotation
		x->setRight(y);
		y->setLeft(T2);

		//Update heights
		updateHeight(y);
		updateHeight(x);

		// Return new root
		return x;
	}
	Node* rotateLeft(Node *x) {
		Node* y = x->getRight();
		Node* T2 = y->getLeft();

		// Perform rotation
		y->setLeft(x);
		x->setRight(T2);

		//Update heights
		updateHeight(x);
		updateHeight(y);

		// Return new root
		return y;
	}
	Node* rotate(int balance, int key, Node *n) {
		// Left Left Case
		if (balance > 1 && key < n->getLeft()->getX())
			return rotateRight(n);

		// Right Right Case
		if (balance < -1 && key > n->getRight()->getX())
			return rotateLeft(n);

		// Left Right Case
		if (balance > 1 && key > n->getLeft()->getX())
		{
			n->setLeft(rotateLeft(n->getLeft()));
			return rotateRight(n);
		}

		// Right Left Case
		if (balance < -1 && key < n->getRight()->getX())
		{
			n->setRight(rotateRight(n->getRight()));
			return rotateLeft(n);
		}
		return n;
	}

	void updateHeight(Node *n) {
		n->setHeight(1 + n->max(n->getHeight(n->getLeft()), n->getHeight(n->getRight())));
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
		updateHeight(n);

		int balance = n->getBalance(n);

		return rotate(balance, key, n);		
		
	}
	void print(Node* root) {
		if (root != nullptr) {
			//prints first node, then all to the left, then all to the right

			cout << root->getX() << ", " << root->getY() << endl;
			print(root->getLeft());
			print(root->getRight());
		}
	}
	int getNodes() {
		return nodes;
	}

};