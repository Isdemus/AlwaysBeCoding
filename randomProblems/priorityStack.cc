#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

class Node {
  public:
    Node (int value, unsigned int depth);
    Node *left;
    Node *right;
    int value;
    unsigned int depth;
};

Node::Node(int value, unsigned int depth) {
    Node::value = value;
    Node::depth = depth;
    Node::left = NULL;
    Node::right = NULL;
}

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top()->value << " " << q.top()->depth << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    auto custom_cmp = [] (Node* firstnode, Node* secondnode) {
        cout << "firstnode : " << firstnode->value << " && " << firstnode->depth << endl;
        cout << "secondnode : " << secondnode->value << " && " << secondnode->depth << endl;
        if (firstnode->depth < secondnode->depth) {
            cout << "this" << endl;
            return false;   
        }
        cout << "that" << endl;
        return true;
    };
    
    std::priority_queue<Node*, std::vector<Node*>, decltype(custom_cmp)> que(custom_cmp);
    
    return 0;
}
