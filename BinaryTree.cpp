#include <iostream>
#define null 0

using namespace std; //iostream 입출력

template <typename T>
class Tree;

template <typename T>
class TreeNode { //트리의 노드 class
	friend class Tree<T>;
private:
	T data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(T data = 0, TreeNode * left = null, TreeNode * right = null) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <typename T>
class Tree { //본 트리 class
private:
	TreeNode<T>* root;
public:
	Tree(T data = 0) {
		root = new TreeNode<T>(data);
	}
	// Tree 만들기
	/*
				A
			B        C
		  D      E      F   G
		 H   I J       K
	*/
	void buildTree() {
		root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
		root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
	}

	TreeNode<T>* getRoot() {
		return root;
	}

	void visit(TreeNode<T>* current) {
		cout << current->data << " ";
	}

	// 전위 순회 (현재노드 - 왼 - 오)
	void preorder(TreeNode<T>* current) {
		if (current != null) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}

	// 중위 순회 (왼 - 현재 - 오)
	void inorder(TreeNode<T>* current) {
		if (current != null) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}

	// 후위 순회 (왼 - 오 - 현재)
	void postorder(TreeNode<T>* current) {
		if (current != null) {
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};

int main() {
	Tree<char> tree('A');
	tree.buildTree();
	cout << "사전 >> ";
	tree.preorder(tree.getRoot());
	cout << endl;

	cout << "순서 >> ";
	tree.inorder(tree.getRoot());
	cout << endl;

	cout << "이후 >> ";
	tree.postorder(tree.getRoot());
	cout << endl;
}

