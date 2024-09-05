#pragma once
#include <iostream>
#include <queue>
using namespace std;
class Node
{	
public:
	int data;
	Node* left;
	Node* right;
	Node()
	{

	}
	Node(int val)
	{
		data = val;
		right = nullptr;
		left = nullptr;
	}
	/////////////////////////////////////Problem 1///////////////////////////////////////
	void PreOrder(Node* root)
	{
		if (root == nullptr)
			return;
		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	void PostOrder(Node* root)
	{
		if (root == nullptr)
			return;
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	}
	void Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
	Node* BuildTree(int preorder[], int inorder[], int start, int end)
	{
		if (start > end)
			return nullptr;
		static int i= 0;
		int curr = preorder[i];
		i++;
		Node* node = new Node(curr);
		if (start == end)
			return node;
		int pos = search(inorder, start, end, curr);
		node->left=BuildTree(preorder, inorder, start, pos-1);
		node->right = BuildTree(preorder, inorder, pos+1, end);
		return node;
	}
	int search(int inorder[], int start, int end,int curr)
	{
		for (int i = start; i <= end; i++)
		{
			if (inorder[i] == curr)
				return i;
		}
		return -1;
	}

	Node* BuildTreePostorder(int preorder[], int inorder[], int start, int end)
	{
		if (start > end){
			return nullptr;
		}
		static int i = end;
		int curr = preorder[i];
		i--;
		Node* node = new Node(curr);
		if (start == end)
			return node;
		int pos = search(inorder, start, end, curr);
		node->right = BuildTreePostorder(preorder, inorder, pos + 1, end);
		node->left = BuildTreePostorder(preorder, inorder, start, pos - 1);
		return node;
	}
	void PrintLevelOrder(Node* root)
	{
		if (root == nullptr)
			return;
		queue <Node*>q;
		q.push(root);
		q.push(nullptr);
		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if (node != nullptr)
			{
				cout << node->data << " ";
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			else if (!q.empty())
			{
				q.push(nullptr);
			}
		}

	}
	int SumAtK(Node* root, int n)
	{
		if (root == nullptr)
			return -1;
		queue <Node*>q;
		q.push(root);
		q.push(nullptr);
		int level = 0;
		int sum = 0;
		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if (node != nullptr)
			{
				if (level== n)
				{
					sum += node->data;
				}
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
			else if (!q.empty())
			{
				q.push(nullptr);
				level++;
			}
		}
		return sum;

	}
	/////////////////////////////PROBLEM 2/////////////////
	//TreeNode* insertIntoBST(TreeNode* root, int val)
	//{
	//	if (root == nullptr) {
	//		return new TreeNode(val);
	//	}

	//	// Insert into the right subtree
	//	if (val > root->val) {
	//		root->right = insertIntoBST(root->right, val);
	//	}
	//	// Insert into the left subtree
	//	else if (val < root->val) {
	//		root->left = insertIntoBST(root->left, val);
	//	}

	//	return root;
	//}
	//////////////////////Problem 3////////////////////////////
	bool isSameTree(Node* p, Node* q) {
		// Base cases
		if (!p && !q) {
			return true; 
		}
		else if (!p || !q) {
			return false;
		}
		if (p->data != q->data) {
			return false; 
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	///////////////////////////////Problem 4 a////////////////////////
	void Inorder(Node* root, std::vector<int>& result) {
		if (root == nullptr)
			return;

		Inorder(root->left, result);
		result.push_back(root->data); 
		Inorder(root->right, result);
	}

	std::vector<int> inorderTraversal(Node* root) {
		std::vector<int> result;
		Inorder(root, result);
		return result;
	}
	///////////////////////////////Problem 4 part 2/////////////////////////
	void Postorder(Node* root, std::vector<int>& result) {
		if (root == nullptr)
			return;

		Postorder(root->left, result);
		Postorder(root->right, result);
		result.push_back(root->data);
	}

	std::vector<int> postorderTraversal(Node* root) {
		std::vector<int> result;
		Postorder(root, result);
		return result;
	}
	///////////////////////////////Problem 4 part 3////////////////////////////
	void Preorder(Node* root, std::vector<int>& result) {
		if (root == nullptr)
			return;

		result.push_back(root->data);
		Preorder(root->left, result);
		Preorder(root->right, result);
	}

	std::vector<int> preorderTraversal(Node* root) {
		std::vector<int> result;
		Preorder(root, result);
		return result;
	}
	/////////////////////////////Problem 5////////////////////////
	vector<vector<int>> levelOrder(Node* root) {
		std::vector<std::vector<int>> result;

		if (root == nullptr)
			return result;

		std::queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			int levelSize = q.size();
			std::vector<int> level;

			for (int i = 0; i < levelSize; ++i) {
				Node* node = q.front();
				q.pop();

				level.push_back(node->data);

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}

			result.push_back(level);
		}

		return result;
	}
	//////////////////////////Problem 6//////////////////////////
	int countEvenNumbers(Node* root) {
		if (root == nullptr) {
			return 0;
		}

		int count = (root->data % 2 == 0) ? 1 : 0;
		count += countEvenNumbers(root->left);
		count += countEvenNumbers(root->right);

		return count;
	}
	////////////////////////Problem 7////////////////////////
	int calculateHeight(Node* root) {
		if (root == nullptr) {
			return 0;
		}

		int leftHeight = calculateHeight(root->left);
		int rightHeight = calculateHeight(root->right);

		return 1 + max(leftHeight, rightHeight);
	}
	///////////////////////////Problem 8///////////////////////
	bool isValidBST(Node* root, Node* minNode = nullptr, Node* maxNode = nullptr) {
		if (root == nullptr) {
			return true;
		}

		if ((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data)) {
			return false;
		}

		return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
	}
	//////////////////////////////Problem 9////////////////////////////
	void insert(Node*& root, int val) {
		if (root == nullptr) {
			root = new Node(val);
			return;
		}

		if (val < root->data) {
			insert(root->left, val);
		}
		else {
			insert(root->right, val);
		}
	}

	void bstSortAndPrint(std::vector<int>& arr) {
		Node* root = nullptr;
		for (int num : arr) {
			insert(root, num);
		}

		Inorder(root);
	}
	////////////////////////Problem 10////////////////////////
	int countInternalNodes(Node* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
			return 0;
		}

		return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
	}
	//////////////////////////////Problem 11/////////////////////////
	void outputTree(Node* root, int depth = 0) {
		if (root == nullptr) {
			return;
		}

		outputTree(root->right, depth + 1);

		for (int i = 0; i < depth; ++i) {
			cout << "    ";
		}

		cout << root->data << endl;

		outputTree(root->left, depth + 1);
	}
	//////////////////////////////Problem 12/////////////////////////
	int countLeaves(Node* root) {
		if (root == nullptr) {
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr) {
			return 1;
		}

		return countLeaves(root->left) + countLeaves(root->right);
	}
};

