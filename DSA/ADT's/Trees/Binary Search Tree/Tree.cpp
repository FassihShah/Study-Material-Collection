#include<iostream>
#include"Tree.h"
using namespace std;
template<typename T>
TreeNode<T>::TreeNode()
{
	left = nullptr;
	right = nullptr;
}
template<typename T>
TreeNode<T>::TreeNode(T val, TreeNode<T>* l, TreeNode<T>* r)
{
	data = val;
	left = l;
	right = r;
}
template<typename T>
Tree<T>::Tree()
{
	root = nullptr;
}
template<typename T>
void Tree<T>::inTraverse(TreeNode<T>* ptr)
{
	if (ptr == nullptr)
		return;
	inTraverse(ptr->left);
	cout << ptr->data << " ";
	inTraverse(ptr->right);
}
template<typename T>
void Tree<T>::insert(T val)
{
	if (root == nullptr)
	{
		root = new TreeNode<T>(val);
		return;
	}
	TreeNode<T>* ptr = root;
	TreeNode<T>* ptr1 = root;
	while (ptr != nullptr)
	{
		if (ptr->data > val)
		{
			ptr1 = ptr;
			ptr = ptr->left;
		}
		else if (ptr->data < val)
		{
			ptr1 = ptr;
			ptr = ptr->right;
		}
		else if (ptr->data == val)
		{
			return;
		}
	}
	if (ptr1->data > val)
	{
		ptr1->left = new TreeNode<T>(val);
	}
	else
	{
		ptr1->right = new TreeNode<T>(val);
	}
}
template<typename T>
TreeNode<T>* Tree<T>::getParentOfSuccessor(TreeNode<T>* node)
{
	TreeNode<T>* successor = node->right;
	TreeNode<T>* parent = node->right;
	while (successor->left != nullptr)
	{
		parent = successor;
		successor = successor->left;
	}
	return parent;
}
template<typename T>
void Tree<T>::deleteNode(T val)
{
	TreeNode<T>* ptr = root;
	TreeNode<T>* parent = root;
	bool flag = false;
	while (ptr != nullptr && !flag)
	{
		if (ptr->data > val)
		{
			parent = ptr;
			ptr = ptr->left;
		}
		else if (ptr->data < val)
		{
			parent = ptr;
			ptr = ptr->right;
		}
		else if (ptr->data == val)
		{
			flag = true;
		}
	}
	if (!flag)
		return;
	if (ptr->left == nullptr && ptr->right == nullptr)
	{
		if (parent->left == ptr)
			parent->left = nullptr;
		else
			ptr->right = nullptr;
		delete ptr;
	}
	else if (ptr->left != nullptr && ptr->right != nullptr)
	{
		TreeNode<T>* parentSuccessor = getParentOfSuccessor(ptr);
		TreeNode<T>* successor = parentSuccessor;
		if (parentSuccessor->left != nullptr)
                	successor = parentSuccessor->left;
                ptr->data = successor->data;
                if (parentSuccessor == successor)
                	ptr->right = parentSuccessor->right;
                else
                	parentSuccessor->left = successor->right;
                delete successor;
	}
	else
	{
		TreeNode<T>* temp = ptr->right;
		if (ptr->left != nullptr)
			temp = ptr->left;
		if (parent->left == ptr)
			parent->left = temp;
		else
			parent->right = temp;
		delete ptr;
	}
}
template<typename T>
T Tree<T>::getLCA(T a, T b)
{
	TreeNode<T>* ptr = root;
	while (ptr != nullptr)
	{
		if (ptr->data > a && ptr->data > b)
			ptr = ptr->left;
		else if (ptr->data < a && ptr->data < b)
			ptr = ptr->right;
		else
			return ptr->data;
	}
	return -1;
}
template<typename T>
void Tree<T>::convertToSortedArray(TreeNode<T>* ptr, int arr[100], int& index)
{
	if (ptr == nullptr)
		return;
	convertToSortedArray(ptr->left, arr, index);
	arr[index++] = ptr->data;
	convertToSortedArray(ptr->right, arr, index);
}
template<typename T>
bool Tree<T>::findTarget(TreeNode<T>* root, int k)
{
	int arr[100];
	int left = 0;
	int right = 0;
	convertToSortedArray(root, arr, right);
	right--;
	while (left != right)
	{
		if (arr[left] + arr[right] < k)
		{
			left++;
		}
		else if (arr[left] + arr[right] > k)
		{
			right--;
		}
		else
		{
			return true;
		}
	}
	return false;
}
template<typename T>
void Tree<T>::traverse()
{
	inTraverse(root);
}