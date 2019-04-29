#include <iostream>
#include <cstdlib>
class Node {
private:
int data;
Node* left;
Node* right;
public:
Node(int data) {
this->data = data;
left = NULL;
right = NULL;
}
void SetData(int data) {
this->data = data;
}
void SetLeft(Node* left) {
this->left = left;
}
void SetRight(Node* right) {
this->right = right;
}
int GetData() {
return data;
}
Node* GetLeft() {
return left;
}
Node* GetRight() {
return right;
}
};

int main()
{
    std::cout << "Hello, Wandbox!" << std::endl;
}