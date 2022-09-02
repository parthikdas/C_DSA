#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
typedef struct lineno {
    int ln;
    struct lineno *next;
} node;
typedef struct lx {
    char str[20];
    node *next;
    struct lx *down;
} lex;
lex *keyhd,*ophd,*idhd;
FILE *fp;
char temp[20];
int line=1;
lex *getkeynode();
node *getlnode();
void analyze();
void add(lex *);
void show(lex *);
char key[100][100] = {"auto","break","case","char","const","continue","default", "do","double", "else", "enum", "extern","float", "for", "goto", "if","int", "long", "register", "return","short","signed", "sizeof", "static", "main","struct", "switch", "typedef", "union", "include", "scanf", "printf","unsigned", "void", "volatile", "while",
"stdio.h", "stdlib.h", "string.h", "math.h"}; // keywords and header files
int main() {
    keyhd=getkeynode();
    ophd=getkeynode();
    idhd=getkeynode();
    fp=fopen("inp.c", "rt");
    if(fp==NULL) {
        printf("No input file!!");
        exit(1);
    }
    analyze();
    printf("\n\t\tKeywords\n\n");
    show(keyhd); // keyword
    printf("\n\t\tIdentifier\n\n");
    show(idhd); // identifer
    printf("\n\t\tOperator\n\n");
    show(ophd); // operator
    free(ophd);
    free(idhd);
    free(keyhd);
    return 0;
}
lex *getkeynode() {
    lex *temp = (lex*)malloc(sizeof(lex));
    temp->next=NULL;
    temp->down=NULL;
    return temp;
}
node *getlnode() {
    node *temp = (node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
void analyze() {
    int i,flag;
    char ch=fgetc(fp);
    while(ch!=EOF) {
        if(ch=='\n') { // new line
            ch=fgetc(fp);
            line++;
            continue;
        }
        if(isspace(ch)) { // space
            ch=fgetc(fp);
            continue;
        }
        if(ch== '/') while((ch=fgetc(fp))!='/'); // comment
        if(isalpha(ch)) { // alphabet (keyword or identifier)
            i=0;
            do {
                temp[i++]=ch;
                ch=fgetc(fp);
            }
            while(isalpha(ch)||ch=='.');
            fseek(fp,-1,1);
            temp[i]='\0';
            i=0;
            flag=0;
            while(strlen(key[i])) {
                if(strcmp(temp,key[i])==0) {
                    add(keyhd); // keyword
                    flag=1;
                    break;
                }
                i++;
            }
            if(flag==0) add(idhd); // identifier
        } else { // operator
            temp[0]=ch;
            temp[1]='\0';
            add(ophd);
        }
        ch=fgetc(fp);
    }
}
void add(lex *hd) {
    node *l,*m;
    lex *q,*p=hd->down;
    while(p) {
        if(strcmp(p->str,temp)==0)
        break;
        p=p->down;
    }
    if(p==NULL) {
        p=hd;
        while(p->down)p=p->down;
        q=getkeynode();
        p->down=q;
        strcpy(q->str,temp);
        l=getlnode();
        l->ln=line;
        q->next=l;
    } else {
        m=getlnode();
        l=p->next;
        m->ln=line;
        if(l==NULL) p->next=m;
        else {
            while(l->next)
            l=l->next;
            l->next=m;
        }
    }
}
void show(lex *hd) {
    lex *p=hd->down,*q;
    node *l,*m;
    int i=1,occ=0;
    printf("\tTokens\t\tLineno\t\tOccurences\n\n");
    while(p) {
        occ=1;
        l=p->next;
        printf("\t%s\t\t",p->str);
        printf("%d",l->ln);
        l=l->next;
        while(l) {
            printf("%d",l->ln);
            l=l->next;
            occ++;
        }
        printf("\t\t%d",occ);
        p=p->down;
        printf("\n");
    }
}