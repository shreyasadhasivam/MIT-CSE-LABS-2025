#include <stdio.h>
#include<stdlib.h>

typedef struct LL* Node;

typedef struct LL
{
	int data;
	Node next;
}LL;

Node getnode()
{
	Node temp = (Node)malloc(sizeof(LL));
	return temp;
}

void printAdjList(Node List)
{
	Node temp = List;
	while(temp)
	{
		printf("%d-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void createAdjList(int row[],int vert,int rownum)
{
	Node list = getnode();
	list->data = rownum+1;
	list->next = NULL;
	Node rear = list;
	for(int i=0;i<vert;i++){
		if(row[i] == 1){
			Node temp = getnode();
			temp->data = i+1;
			temp->next = NULL;
			rear->next = temp;
			rear = rear->next;		
		}
	}
	printAdjList(list);
}

void createAdjMat(int** mat,int vert)
{
	char ans;
	for(int i=0;i<vert;i++){
		for(int j=0;j<vert;j++){
			printf("Does vertex %d have an edge with vertex %d (Y/N): ",i+1,j+1);
			scanf(" %c",&ans);
			if(ans == 'Y'){
				mat[i][j] = 1;
			}
			else{
				mat[i][j] = 0;
			}
			printf("\n");
		}
	}
}

void printAdjMat(int** mat,int vert)
{
	printf("Adjacency Matrix:\n");
	for(int i=0;i<vert;i++){
		for(int j=0;j<vert;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{

	int vert,edges;
	printf("Enter the number of vertices: ");
	scanf("%d",&vert);
	printf("Enter the number of edges: ");
	scanf("%d",&edges);
	int** mat = (int**)malloc(vert*sizeof(int*));
	for(int i=0;i<vert;i++)
	{
		mat[i] = (int*)malloc(vert*sizeof(int));
	}
	createAdjMat(mat,vert);
	printAdjMat(mat,vert);
	printf("Adjacency Lists:\n");
	for(int i=0;i<vert;i++)
	{
		createAdjList(mat[i],vert,i);
	}
}