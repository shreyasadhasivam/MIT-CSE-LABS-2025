#include<stdio.h>
#include<string.h>
struct token{
	char type[20];
	int row,col;
};
struct symboltable{
	int sno;
	char lexemename[20];
	char tokenname[20];
	char rettype[10];
	char type[10];
	int argno;
};
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd, int *sidx, struct symboltable *symt);
int kw(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx, int *sidx, struct symboltable *symt);
void symb(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void nc(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void st(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void logop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void relop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
void arop(FILE *rd, int *r, int *c, struct token *arr, int *idx);
int noargs(FILE *rd);
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
int main(){
	FILE *rd,*fp,*fpp;
	char name[100];
	struct symboltable symt[100];
	int sidx=0;
	printf("Enter read file name: ");
	scanf("%s",name);
	rd=fopen(name,"r");
	fp = fopen("inter.c", "w+");
	int r=1;
	int c=0;
	struct token arr[3000];
	int idx=0;
	removePreProcessers(rd,fp);
	fclose(fp);
	fpp= fopen("inter.c","r");
	getNextToken(arr, &idx, &r, &c, fpp,&sidx,symt);
	printf("Tokens: \n");
	for(int i=0;i<idx;i++){
		printf("%s %d %d\n",arr[i].type,arr[i].row,arr[i].col);
	}
	printf("\n\nIdentifiers: \n");
	printf("Sno,\t Lexeme  Token Name  Return Type  Type  Arguments\n");
	for(int i=0;i<sidx;i++){
		if(strcmp(symt[i].lexemename,"\0")!=0){
			printf("%d\t %s\t %s\t\t %s\t %s\t %d\n",symt[i].sno,symt[i].lexemename,symt[i].tokenname,symt[i].rettype,symt[i].type,symt[i].argno);
		}
	}
	return 0;
}
void getNextToken(struct token *arr, int *idx, int *r, int *c, FILE *rd,int *sidx, struct symboltable *symt){
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
				id(rd,r,c, arr, idx, sidx, symt);
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
void id(FILE *rd, int *r, int *c, struct token *arr, int *idx, int *sidx, struct symboltable *symt){
	char key[100];
	int i=0;
	int c2=0;
	int k;
	int num;
	char ch=getc(rd);
	c2++;
	int flag=0;
	while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
        key[i]=ch;
        i++;
		ch=getc(rd);
		c2++;
	}
	key[i]='\0';
	fseek(rd,-1,SEEK_CUR);
	c2--;
	for(k=0;k<(*sidx);k++){
        if(strcmp(symt[k].lexemename,key)==0){
            flag=1;
            break;
        }
	}
	if(flag==1){
        sprintf(arr[*idx].type,"id%d",k);
        arr[*idx].row=*r;
        arr[*idx].col=(*c)+1;
        (*c)=(*c)+c2;
        (*idx)++;
	}
	else{
        sprintf(arr[*idx].type,"id%d",(*sidx));
        arr[*idx].row=*r;
        arr[*idx].col=(*c)+1;
        (*c)=(*c)+c2;
        (*idx)++;
        symt[(*sidx)].sno=(*sidx);
        strcpy(symt[(*sidx)].lexemename,key);
        if(ch=='('){
            strcpy(symt[(*sidx)].type,"func");
            strcpy(symt[(*sidx)].tokenname, "-");
            //strcpy(symt[(*sidx)].datatype,"-");
            //rettype
            if(strcmp(key,"printf")==0 || strcmp(key,"scanf")){
            	strcpy(symt[(*sidx)].rettype,"void");
            }
            else{
            	k=(*idx);
            	while(strcmp(arr[k].type,"int")!=0 && strcmp(arr[k].type,"char")!=0 && strcmp(arr[k].type,"float")!=0 && strcmp(arr[k].type,"double")!=0 && strcmp(arr[k].type,"void")!=0){
                k--;
           	 }
            strcpy(symt[(*sidx)].rettype,arr[k].type);
        	}
            //no of args**************************************
            num=noargs(rd);
            symt[(*sidx)].argno=num;
        }
        else{
            strcpy(symt[(*sidx)].type,"var");
            strcpy(symt[(*sidx)].tokenname,"id");
            //sprintf(arr[*idx].type,"id%d",(*sidx));
            // for(int i=0;i<*sidx;i++)
            // {
            // 	printf("%d",i);
            // }
            strcpy(symt[(*sidx)].rettype,"-");
            symt[(*sidx)].argno=0;
            //datatype
            k=(*idx);
            while(strcmp(arr[k].type,"int")!=0 && strcmp(arr[k].type,"char")!=0 && strcmp(arr[k].type,"float")!=0 && strcmp(arr[k].type,"double")!=0){
                k--;
            }
            //strcpy(symt[(*sidx)].datatype,arr[k].type);
        }
        (*sidx)++;
	}
}
int noargs(FILE *rd){
	char ch;
	int c=0;
	int i=0;
	ch=getc(rd);
	c++;
	char key[100];
	int commas=0;
	while(ch!=')'){
		ch=getc(rd);
		c++;
		if(ch=='"'){
			ch=getc(rd);
			c++;
			key[i]=ch;
			i++;
			while(ch!='"'){
				ch=getc(rd);
				c++;
				key[i]=ch;
				i++;
			}
		}
		else if(ch==','){
			commas++;	
		}
		key[i]=ch;
		i++;
	}
	key[i-1]='\0';
	fseek(rd,-c,SEEK_CUR);
	if(strcmp(key," ")==0||strcmp(key,"void")==0||strcmp(key,"\0")==0){
		return 0;
	}
	else{
		return commas+1;
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