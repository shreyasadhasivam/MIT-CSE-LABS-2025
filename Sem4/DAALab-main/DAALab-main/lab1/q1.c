#include<stdio.h>
#include<stdlib.h>

typedef struct BST* node;

typedef struct BST
{
	int data;
	node Rchild, Lchild;

}BST;

node getNode()
{
	node temp = (node)malloc(sizeof(BST));
	return temp;
}

void createBST(node *tree)
{
	node cur = *tree;
	node parent =*tree;

	int item;
	if(parent==NULL)
	{
		printf("Enter the root: ");
		scanf("%d", &item);
		node temp = getNode();
		temp->data = item;
		temp->Rchild= temp->Lchild=NULL;
		*tree = temp;
	}
	while(1)
	{
		node cur = *tree;
		node parent = *tree;
		printf("Enter the value to insert: ");
		scanf("%d", &item);
		if(item == -1)
			break;
		while(cur)
		{
			parent=cur;
			if(cur->data < item)
			{
				cur = cur-> Rchild;

			}
			else
			{
				cur = cur->Lchild;
			}
		}
		node temp = getNode();
		temp->data = item;
		temp->Rchild = temp->Lchild = NULL;
		if(parent->data <item)
			{
				parent ->Rchild = temp;
			}
			else
			{
				parent->Lchild = temp;
			}
	}
}

void inorder(node root)
{
	if(root)
	{
		inorder(root->Lchild);
		printf("%d->", root->data);
		inorder(root->Rchild);

	}
	//printf("NULL");

}

void preorder(node root)
{
	if(root)
	{
		printf("%d ->", root->data);
		preorder(root->Lchild);
		preorder(root->Rchild);

	}
	//printf("NULL");

}

void postorder(node root)
{
	if(root)
	{
		postorder(root->Lchild);
		postorder(root->Rchild);
		printf("%d-> ", root->data);
	}
	//printf("NULL");
}


void searchBST(node *tree, int key)
{
	node parent = *tree;
	node cur = *tree;
	while(cur)
	{
		parent = cur;
		if(cur->data == key)
		{
			printf("Key Found\n");
			return;

		}
		else if(cur->data < key)
		{
			cur = cur->Rchild;
		}
		else
		{
			cur = cur->Lchild;
		}
	}
	node temp = getNode();
	temp ->data = key;
	temp -> Rchild = temp -> Lchild = NULL;
	if(parent->data < key)
	{
		parent->Rchild = temp;
	}
	else
	{
		parent->Lchild = temp;
	}
	printf("Key inserted.\n");
	return;
}

int main()
{
	node tree= NULL;
	createBST(&tree);
	inorder(tree);
	printf("NULL\n");
	preorder(tree);
	printf("NULL\n");
	postorder(tree);
	printf("NULL\n");
	//int key;
	//printf("Enter key to be searched: ");
	//scanf("%d", &key);
	searchBST(&tree,1);
	searchBST(&tree,15);
}