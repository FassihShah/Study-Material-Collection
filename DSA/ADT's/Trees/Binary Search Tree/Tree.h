#ifndef TREE_H
#define TREE_H
template <typename T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode();
	TreeNode(T val, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr);
};
template <typename T>
class Tree
{
	void inTraverse(TreeNode<T>* ptr);
	TreeNode<T>* getParentOfSuccessor(TreeNode<T>* node);
	void convertToSortedArray(TreeNode<T>* ptr, int arr[100], int& index);
public:
	TreeNode<T>* root;
	Tree();
	void insert(T val);
	void traverse();
	void deleteNode(T key);
	T getLCA(T a, T b);
	bool findTarget(TreeNode<T>* root, int k);
};
template class TreeNode<int>;
template class Tree<int>;
#endif