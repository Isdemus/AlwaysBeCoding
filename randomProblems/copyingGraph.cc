#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

typedef class node {
	public:
		node(int val) : next(list<struct node*>()), value(val) {}
		void Add(struct node* n) {
			next.push_back(n);
		}
		int GetValue(void) {
			return value;
		}
		list<struct node*> GetList(void) {
			return next;
		}
		virtual ~node() {
			while (!next.empty()) {
				delete next.front();
				next.pop_front();
			}
		}
	private:
		int value;
		list<struct node*> next;
} Node;

// Decoration design pattern for copying a cyclic graph
typedef struct decoration {
	Node *node;
	bool selected;
	decoration(Node *givennode) : node(givennode), selected(false) {}
} Decorator;

void CopyGraph(Node *newnode, Node *orignode) {
	auto origlist = orignode->GetList();
	auto listiterator = origlist.begin();
	for (; listiterator != origlist.end(); listiterator++) {
		Node *node_in_orig_node = *listiterator;
		Node *node_need_to_copy = new Node(node_in_orig_node->GetValue());
		newnode->Add(node_need_to_copy);
		CopyGraph(node_need_to_copy, node_in_orig_node);
	}
}

void PrintGraph(Node *node) {
	auto list = node->GetList();
	auto listiterator = list.begin();
	for (; listiterator != list.end(); listiterator++) {
		Node *next_node = *listiterator;
		printf("%d -> %d\n", node->GetValue(), next_node->GetValue());
		PrintGraph(next_node);
	}
}

int main(int argc, char* argv[]) {
	Node *root = new Node(0);
	Node *firstnode = new Node(1);
	Node *secondnode = new Node(2);
	Node *thirdnode = new Node(3);
	Node *fourthnode = new Node(4);
	Node *fifthnode = new Node(5);

	root->Add(firstnode);
	firstnode->Add(secondnode);
	secondnode->Add(thirdnode);
	secondnode->Add(fourthnode);
	fourthnode->Add(fifthnode);

	Node *newroot = new Node(root->GetValue());
	CopyGraph(newroot, root);

	PrintGraph(root);
	PrintGraph(newroot);

	return 0;
}
