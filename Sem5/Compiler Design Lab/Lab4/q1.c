#include<stdio.h>
#include<string.h>
#define HASHMOD 100
struct token{
	char type[20];
	int row,col;
};
struct symboltable{
	int sno;
	char lexemename[20];
	char rettype[10];
	char datatype[10];
	char type[10];
	int argno;
};
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd, int *idc, int *sidx, struct symboltable *symt);
int kw(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx, int *idc, int *sidx, struct symboltable *symt);
void symb(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void nc(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void st(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void relop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void arop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
int main(){
	int idc=0;
	struct symboltable symt[100];
	int sidx=0;
	FILE *rd;
	char name[100];
	printf("Enter read file name: ");
	scanf("%s",name);
	rd=fopen(name,"r");
	int r=1;
	int c=0;
	struct token arr[3000];
	int idx=0;
	for(int i=0;i<HASHMOD;i++){
		strcpy(symt[i].lexemename,"\0");
	}
	getNextToken(arr, &idx, &r, &c, rd, &idc, &sidx, symt);
	printf("Tokens: \n");
	for(int i=0;i<idx;i++){
		printf("%s %d %d\n",arr[i].type,arr[i].row,arr[i].col);
	}
	printf("\n\nIdentifiers: \n");
	printf("Sno  Lexeme  Return Type  Data type  Type  Arguments\n");
	for(int i=0;i<HASHMOD;i++){
		if(strcmp(symt[i].lexemename,"\0")!=0){
			printf("%d  %s   %s   %s  %s  %d\n",symt[i].sno,symt[i].lexemename,symt[i].rettype,symt[i].datatype,symt[i].type,symt[i].argno);
		}
	}
	return 0;
}
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd, int *idc, int *sidx, struct symboltable *symt){
	char ch;
	int rec=0;
	ch=getc(rd);
	(*c)++;
	while(ch!=EOF){
		if(ch=='\n'){
			(*r)++;
			(*c)=0;
		}
		else if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
			fseek(rd,-1,SEEK_CUR);
			(*c)--;
			rec=kw(rd,r,c, arr, idx);
			if(rec!=0){
                fseek(rd,-rec,SEEK_CUR);
				id(rd,r,c, arr, idx, idc, sidx, symt);
			}
		}
		else if(ch>='0' && ch<='9'){
			fseek(rd,-1,SEEK_CUR);
			(*c)--;
			nc(rd,r,c, arr, idx);
		}
		else{
			fseek(rd,-1,SEEK_CUR);
			(*c)--;
			symb(rd,r,c, arr, idx);
		}
		ch=getc(rd);
		(*c)++;
	}
}
int kw(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=0;
	char key[100];
	char words[16][10]={"if","else","int","float","char","break","case","continue","default","double","for","while","return","sizeof","struct","void"};
	int i=0;
	char ch=getc(rd);
	c2++;
	while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
		key[i]=ch;
		i++;
		c2++;
		ch=getc(rd);
	}
	key[i]='\0';
	fseek(rd,-1,SEEK_CUR);
	c2--;
	for(int j=0;j<16;j++){
		if(strcmp(key,words[j])==0){
			strcpy(arr[*idx].type,key);
			arr[*idx].row=*r;
			arr[*idx].col=(*c)+1;
			(*c)=(*c)+c2;
			(*idx)++;
			return 0;
		}
	}
	return c2;
}
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx, int *idc, int *sidx, struct symboltable *symt){
	char key[100];
	int i=0;
	int c2=0;
	char ch=getc(rd);
	c2++;
	int sum=0;
	int flag;
	while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
		key[i]=ch;
		sum+=ch;
		ch=getc(rd);
		i++;
		c2++;
	}
	key[i]='\0';
	fseek(rd,-1,SEEK_CUR);
	c2--;
	strcpy(arr[*idx].type,"id");
	sprintf(arr[*idx].type,"%s%d",arr[*idx].type,*idc);
	arr[*idx].row=*r;
	arr[*idx].col=(*c)+1;
	(*c)=(*c)+c2; 	
	(*idx)++;
	//*********************************
	if(ch=='('){
		flag=1;
	}
	else{
		flag=0;
	}
	sum=sum%HASHMOD;
	if(strcmp(symt[sum].lexemename,key)!=0){
		symt[sum].sno=(*idc);
		(*idc)++;
		strcpy(symt[sum].lexemename,key);
		if(flag==0){
			int x=(*idx)-1;
			while(strcmp(arr[x].type,"int")!=0 && strcmp(arr[x].type,"char")!=0 && strcmp(arr[x].type,"float")!=0 && strcmp(arr[x].type,"double")!=0){
				x--;
			}
			strcpy(symt[sum].rettype,"-");
			strcpy(symt[sum].datatype,arr[x].type);
			strcpy(symt[sum].type,"var");
			symt[sum].argno=0;
		}
		else{
			strcpy(symt[sum].rettype,arr[(*idx)-2].type);
			strcpy(symt[sum].datatype,"  -  ");
			strcpy(symt[sum].type,"func");
			symt[sum].argno=0;
		}
	}
}
void nc(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=0;
	char ch=getc(rd);
	c2++;
	while(ch>='0' && ch<='9'){
		ch=getc(rd);
		c2++;
	}
	fseek(rd,-1,SEEK_CUR);
	c2--;
	strcpy(arr[*idx].type,"num const");
	arr[*idx].row=*r;
	arr[*idx].col=(*c)+1;
	(*c)=(*c)+c2;
	(*idx)++;
}
void symb(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char ch=getc(rd);
	(*c)++;
	if(ch=='"'){
        (*c)--;
		st(rd,r,c,arr,idx);
	}
	if(ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='('||ch==')'||ch==';'||ch==':'||ch=='#'||ch==','){
		strcpy(arr[*idx].type,"spcl");
		arr[*idx].row=*r;
		arr[*idx].col=*c;
		(*idx)++;
	}
	if(ch=='&'||ch=='|'||ch=='!'||ch=='^'){
		fseek(rd,-1,SEEK_CUR);
		(*c)--;
		logop(rd,r,c,arr,idx);
	}
	if(ch=='>'||ch=='<'||ch=='='||ch=='!'){
		fseek(rd,-1,SEEK_CUR);
		(*c)--;
		relop(rd,r,c,arr,idx);
	}
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='%'){
		fseek(rd,-1,SEEK_CUR);
		(*c)--;
		arop(rd,r,c,arr,idx);
	}
}
void st(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=1;
	char key[100];
	int i=1;
	key[0]='"';
	char ch=getc(rd);
	c2++;
	while(ch!='"'){
		key[i]=ch;
		i++;
		ch=getc(rd);
		c2++;
	}
	key[i]=ch;
	i++;
	key[i]='\0';
	strcpy(arr[*idx].type,key);
	arr[*idx].row=*r;
	arr[*idx].col=(*c)+1;
	(*c)=(*c)+c2;
	(*idx)++;
}
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=0;
	char key[10];
	char ops[10][3]={"&&","||","!","&","|","^","&=","|=","^="};
	int i=0;
	char ch=getc(rd);
	c2++;
	while(ch=='&'||ch=='|'||ch=='!'||ch=='^'||ch=='='){
		key[i]=ch;
		i++;
		ch=getc(rd);
		c2++;
	}
	fseek(rd,-1,SEEK_CUR);
	c2--;
	key[i]='\0';
	for(int j=0;j<10;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"log op");
			arr[*idx].row=*r;
			arr[*idx].col=(*c)+1;
			(*c)=(*c)+c2;
			(*idx)++;
		}
	}
}
void relop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=0;
	char key[10];
	char ops[6][3]={"==",">",">=","<","<=","!="};
	int i=0;
	char ch=getc(rd);
	c2++;
	while(ch=='>'||ch=='='||ch=='<'||ch=='!'){
		key[i]=ch;
		i++;
		ch=getc(rd);
		c2++;
	}
	fseek(rd,-1,SEEK_CUR);
	c2--;
	key[i]='\0';
	for(int j=0;j<6;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"rel op");
			arr[*idx].row=*r;
			arr[*idx].col=(*c)+1;
			(*c)=(*c)+c2;
			(*idx)++;
		}
	}
}
void arop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
    int c2=0;
	char key[10];
	char ops[8][3]={"+","-","*","/","=","%","++","--"};
	int i=0;
	char ch=getc(rd);
	c2++;
	while(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='='){
		key[i]=ch;
		i++;
		ch=getc(rd);
		c2++;
	}
	fseek(rd,-1,SEEK_CUR);
	c2--;
	key[i]='\0';
	for(int j=0;j<8;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"arith op");
			arr[*idx].row=*r;
			arr[*idx].col=(*c)+1;
			(*c)=(*c)+c2;
			(*idx)++;
		}
	}
}
