/*
required space complexity O(h1+h2)

3 STEPS
1. convert BST into sorted doubly Linked List
2. merge 2 double LL into a single sorted doubly Linked list
3. Make a balanced Binary Search Tree
*/
#include <iostream>
using namespace std;

// A BST node
struct Node
{
	int data;
	Node* left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};
// Function to print preorder traversal of the BST
void preorder(Node* root)
{
	if (root == nullptr) {
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int countNode(Node* head)
{
	int count = 0;
	Node* temp = head;
	while (temp)
	{
		temp = temp->right;
		count++;
	}
	return count;
}

//STEP 3:
Node* sortedLLToBST(Node* &head, int n)
{
	//base case
	if (head == NULL || n <= 0)
		return NULL;
	Node* left = sortedLLToBST(head, n/2);
	Node* root = head;
	root->left = left;
	head = head->right;
	root->right = sortedLLToBST(head, n-(n/2+1));
	return root;
}

//STEP 2:
Node* mergeLinkedList(Node* head1, Node* head2)
{
	Node *head = NULL, *tail = NULL;
	while (head1 && head2)
	{
		if (head1->data < head2->data)
		{
			if (head == NULL)
			{
				head = head1;
				tail = head1;
				head1 = head1->right;
			}
			//insert at tail
			else
			{
				tail->right = head1;
				head1->left = tail; 
				tail = head1;
				head1 = head1->right;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = head2;
				tail = head2;
				head2 = head2->right;
			}
			else
			{
				tail->right = head2;
				head2->left = tail;
				tail = head2;
				head2 = head2->right;
			}
		}
		
	}
	while (head1)
	{
		tail->right = head1;
		head1->left = tail;
		tail = head1;
		head1 = head1->right;
	}
	while(head2)
	{
		tail->right = head2;
		head2->left = tail;
		tail = head2;
		head2 = head2->right;
	}
	return head;
}

//logic: L N R(inorder gives us sorted in BST), if we do R N L it'll give reverse sort(decreasing order), thus at the end we'll get the smallest element that will be our head!(so head goes from largest to smallest )

//Step 1:
void convertIntoSortedDLL(Node* root, Node* &head)
{
	//base case
	if (root == NULL)
		return;

	//right
	convertIntoSortedDLL(root->right,head);

	//Node
	root->right = head;
	if (head && head->left)
		head->left = root;
	head = root;

	//left
	convertIntoSortedDLL(root->left,head);
}

// Function to merge two balanced BSTs into a single balanced BST
Node* merge(Node* first, Node* second)
{
	//STEP 1: convert BST into sorted DLL in-place
	Node* head1 = NULL;
	convertIntoSortedDLL(first,head1);
//	head1->left = NULL;
	
	Node* head2 = NULL;
	convertIntoSortedDLL(second,head2);
//	head2->left = NULL;
	
	//Step 2: Merge sorted LL
	Node* head = mergeLinkedList(head1, head2);
	
	//Step 3: Covert sorted LL into BST
	return sortedLLToBST(head, countNode(head));
}


int main()
{
	/*
	Construct the following BST
		  20
		 /  \
		10  30
			/ \
		   25 100
	*/

	Node* first = new Node(20);
	first->left = new Node(10);
	first->right = new Node(30);
	first->right->left = new Node(25);
	first->right->right = new Node(100);

	/*
	Construct the following BST
		  50
		 /  \
		5   70
	*/

	Node* second = new Node(50);
	second->left = new Node(5);
	second->right = new Node(70);

	// merge both BSTs
	Node* root = merge(first, second);

	preorder(root);
	//required output
	//30 20 10 5 25 70 50 100
	return 0;
}