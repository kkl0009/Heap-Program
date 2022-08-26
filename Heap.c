#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int id;
	struct Node* left;
	struct Node* right;
} Node;

Node* head = NULL;

Node* create_node(int new_id);
Node* create_node_ex(int new_id, Node* new_left, Node* new_right);
void add_node(int new_id);
void print_inorder_helper(Node* curr_node);
void print_preorder_helper(Node* curr_node);
void print_postorder_helper(Node* curr_node);
void print_inorder();
void print_preorder();
void print_postorder();
void set_head(int new_id);
void reset_heap();
void reset_heap_helper(Node* curr_node);

Node* create_node(int new_id)
{
	Node* new_node = malloc(sizeof(Node));
	new_node -> id = new_id;
	new_node -> left = NULL;
	new_node -> right = NULL;

	return new_node;
}

Node* create_node_ex(int new_id, Node* new_left, Node* new_right)
{
	Node* new_node = malloc(sizeof(Node));
	new_node -> id = new_id;
	new_node -> left = new_left;
	new_node -> right = new_right;

	return new_node;
}

void add_node(int new_id)
{
	if(head == NULL)
	{
		set_head(new_id);
		return;
	}

	Node* curr_node = head;
	while(curr_node != NULL)
	{
		if(new_id < curr_node -> id)
		{
			if(curr_node -> left == NULL)
			{
				curr_node -> left = create_node(new_id);
				break;
			}
			else
			{
				curr_node = curr_node -> left;
			}
		}
		else
		{
			if(curr_node -> right == NULL)
			{
				curr_node -> right = create_node(new_id);
				break;
			}
			else
			{
				curr_node = curr_node -> right;
			}
		}
	}
}

void print_inorder_helper(Node* curr_node)
{
	if(curr_node -> left != NULL)
	{
		print_inorder_helper(curr_node -> left);
	}
	printf("%d ", curr_node -> id);
	if(curr_node -> right != NULL)
	{
		print_inorder_helper(curr_node -> right);
	}
}

void print_preorder_helper(Node* curr_node)
{
	printf("%d ", curr_node -> id);

	if(curr_node -> left != NULL)
	{
		print_preorder_helper(curr_node -> left);
	}
	if(curr_node -> right != NULL)
	{
		print_preorder_helper(curr_node -> right);
	}
}

void print_postorder_helper(Node* curr_node)
{
	if(curr_node -> left != NULL)
	{
		print_postorder_helper(curr_node -> left);
	}
	if(curr_node -> right != NULL)
	{
		print_postorder_helper(curr_node -> right);
	}
	printf("%d ", curr_node -> id);
}

void print_inorder()
{
	if(head == NULL)
	{
		printf("Heap is empty, please add a value\n");
		return;
	}

	print_inorder_helper(head);
	printf("\n");
}

void print_preorder()
{
	if(head == NULL)
	{
		printf("Heap is empty, please add a value\n");
		return;
	}

	print_preorder_helper(head);
	printf("\n");
}

void print_postorder()
{
	if(head == NULL)
	{
		printf("Heap is empty, please add a value\n");
		return;
	}

	print_postorder_helper(head);
	printf("\n");
}

void set_head(int new_id)
{
	if(head == NULL)
	{
		head = create_node(new_id);
	}
	else
	{
		printf("Head already set (reset the tree to set a new value)\n");
	}
}

void reset_heap()
{
	if(head == NULL)
	{
		printf("\nHeap is already empty\n\n");
		return;
	}
	reset_heap_helper(head);
	head = NULL;
	printf("\nHeap successfully reset\n\n");
}

void reset_heap_helper(Node* curr_node)
{
	if(curr_node -> left != NULL)
	{
		reset_heap_helper(curr_node -> left);
	}
	if(curr_node -> right != NULL)
	{
		reset_heap_helper(curr_node -> right);
	}
	free(curr_node);
}

void main()
{
	printf("Hello, welcome to heap builder!\n");

	while(1)
	{
		printf("Select an option:\n");
		printf("1) Add a node to the heap\n");
		printf("2) View the heap in inorder\n");
		printf("3) View the heap in preorder\n");
		printf("4) View the heap in postorder\n");
		printf("5) Reset the heap\n");
		printf("9) Exit\n");

		int response;
		scanf("%d", &response);

		switch(response)
		{
			case 1:
				printf("\nWhat value would you like to add?\n");
				scanf("%d", &response);
				add_node(response);
				printf("Successfully added %d\n\n", response);
				break;
			case 2:
				printf("\nInorder: ");
				print_inorder();
				printf("\n");
				break;
			case 3:
				printf("\nPreorder: ");
				print_preorder();
				printf("\n");
				break;
			case 4:
				printf("\nPostorder: ");
				print_postorder();
				printf("\n");
				break;
			case 5:
				reset_heap();
				break;
			case 9:
				printf("\nExiting the system...\n\n");
				return;
			default:
				printf("\nInvalid option, please see the menu of options\n\n");
		}
	}
}
