#include"Record.h"

using namespace std;
class BinaryNode : public Record {
	BinaryNode* _left;
	BinaryNode* _right;

public:
	BinaryNode(string w, string m) :Record(w, m), _left(NULL), _right(NULL) {}

	void setLeft(BinaryNode *l) { _left = l; }
	void setRight(BinaryNode *r) { _right = r; }
	BinaryNode* getLeft() { return _left; }
	BinaryNode* getRight() { return _right; }
	bool isLeaf() { return _left == NULL && _right == NULL; }
};