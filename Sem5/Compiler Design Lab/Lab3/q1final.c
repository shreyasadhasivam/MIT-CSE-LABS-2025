#include<stdio.h>
#include<string.h>
struct token{
	char type[20];
	int row,col;
};
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd);
int kw(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void symb(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void nc(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void st(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void relop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void arop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void removePreProcessers(FILE *rd, FILE *fp);
int main(){
	FILE *rd,*fp,*fpp;
	char name[100];
	printf("Enter read file name: ");
	scanf("%s",name);
	rd=fopen(name,"r");
	fp = fopen("inter.c", "w+");
	int r=1;
	int c=0;
	struct token arr[200];
	int idx=0;
	removePreProcessers(rd,fp);
	fclose(fp);
	fpp = fopen("inter.c","r");
	getNextToken(arr, &idx, &r, &c, fpp);
	for(int i=0;i<idx;i++){
		printf("<%s,%d,%d>\n",arr[i].type,arr[i].row,arr[i].col);

	}
	return 0;
}
void removePreProcessers(FILE *rd,FILE *fp)
{
	char ca;
	
	ca =getc(rd);
	while(ca!=EOF)
	{
		if(ca=='#')
		{
			while(ca!='>'||ca=='\n')
				ca=getc(rd);
		}
		else putc(ca,fp);
		ca = getc(rd);
	}
}
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd){
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
			if(rec==-1){
				id(rd,r,c, arr, idx);
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
	char key[100];
	char words[16][10]={"if","else","int","float","char","break","case","continue","default","double","for","while","return","sizeof","struct","void"};
	int i=0;
	char ch=getc(rd);
	(*c)++;
	while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
		key[i]=ch;
		i++;
		(*c)++;
		ch=getc(rd);
	}
	key[i]='\0';
	fseek(rd,-1,SEEK_CUR);
	(*c)--;
	for(int j=0;j<16;j++){
		if(strcmp(key,words[j])==0){
			strcpy(arr[*idx].type,key);
			arr[*idx].row=*r;
			arr[*idx].col=*c;
			(*idx)++;
			return 1;
		}
	}
	return -1;
}
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char key[100];
	int i=0;
	char ch=getc(rd);
	(*c)++;
	while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
		ch=getc(rd);
		(*c)++;
	}
	fseek(rd,-1,SEEK_CUR);
	(*c)--;
	strcpy(arr[*idx].type,"id");
	arr[*idx].row=*r;
	arr[*idx].col=*c;
	(*idx)++;
} 
void nc(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char ch=getc(rd);
	(*c)++;
	while(ch>='0' && ch<='9'){
		ch=getc(rd);
		(*c)++;
	}
	fseek(rd,-1,SEEK_CUR);
	(*c)--;
	strcpy(arr[*idx].type,"num const");
	arr[*idx].row=*r;
	arr[*idx].col=*c;
	(*idx)++;
}
void symb(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char ch=getc(rd);
	(*c)++;
	if(ch=='"'){
		st(rd,r,c,arr,idx);
	}
	else if(ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='('||ch==')'||ch==';'||ch==':'||ch=='#'||ch==','){
		strcpy(arr[*idx].type,"spcl");
		arr[*idx].row=*r;
		arr[*idx].col=*c;
		(*idx)++;
	}
	else if(ch=='&'||ch=='|'||ch=='!'||ch=='^'){
		fseek(rd,-1,SEEK_CUR);
		logop(rd,r,c,arr,idx);
	}
	else if(ch=='>'||ch=='<'||ch=='='||ch=='!'){
		fseek(rd,-1,SEEK_CUR);
		relop(rd,r,c,arr,idx);
	}
	else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='%'){
		fseek(rd,-1,SEEK_CUR);
		arop(rd,r,c,arr,idx);
	}
}
void st(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char key[100];
	int i=1;
	key[0]='"';
	char ch=getc(rd);
	(*c)++;
	while(ch!='"'){
		key[i]=ch;
		i++;
		ch=getc(rd);
		(*c)++;
	}
	key[i]=ch;
	i++;
	key[i]='\0';
	strcpy(arr[*idx].type,key);
	arr[*idx].row=*r;
	arr[*idx].col=*c;
	(*idx)++;
}
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char key[10];
	char ops[10][3]={"&&","||","!","&","|","^","&=","|=","^="};
	int i=0;
	char ch=getc(rd);
	(*c)++;
	while(ch=='&'||ch=='|'||ch=='!'||ch=='^'||ch=='='){
		key[i]=ch;
		i++;
		ch=getc(rd);
		(*c)++;
	}
	fseek(rd,-1,SEEK_CUR);
	key[i]='\0';
	for(int j=0;j<10;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"log op");
			arr[*idx].row=*r;
			arr[*idx].col=*c;
			(*idx)++;
		}
	}
}
void relop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char key[10];
	char ops[6][3]={"==",">",">=","<","<=","!="};
	int i=0;
	char ch=getc(rd);
	(*c)++;
	while(ch=='>'||ch=='='||ch=='<'||ch=='!'){
		key[i]=ch;
		i++;
		ch=getc(rd);
		(*c)++;
	}
	fseek(rd,-1,SEEK_CUR);
	key[i]='\0';
	for(int j=0;j<6;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"rel op");
			arr[*idx].row=*r;
			arr[*idx].col=*c;
			(*idx)++;
		}
	}
}
void arop(FILE *rd, int *r, int *c, struct token *arr, int *idx){
	char key[10];
	char ops[8][3]={"+","-","*","/","=","%","++","--"};
	int i=0;
	char ch=getc(rd);
	(*c)++;
	while(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'){
		key[i]=ch;
		i++;
		ch=getc(rd);
		(*c)++;
	}
	fseek(rd,-1,SEEK_CUR);
	key[i]='\0';
	for(int j=0;j<8;j++){
		if(strcmp(ops[j],key)==0){
			strcpy(arr[*idx].type,"arith op");
			arr[*idx].row=*r;
			arr[*idx].col=*c;
			(*idx)++;
		}
	}
}