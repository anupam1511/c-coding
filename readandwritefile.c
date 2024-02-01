#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *readfromsrcfile(char *filename)
{
     FILE *fp ;
     char *p ;
    long int size ;
   fp = fopen(filename , "r") ;
   if(fp==NULL)
   {
      printf("file not found\n");
      exit(0);
   }
   fseek(fp,0,2);
   size = ftell(fp)+1;
   fseek(fp,0,0);
   p = calloc(size,1);
   fread(p,size,1,fp);
   p[size-1]='\0';
   fclose(fp);
   return p ;
}
void writetodestfile(char *buf , char *filename)
{
    FILE *p ;
    p = fopen(filename,"w");
    fwrite(buf,strlen(buf),1,p);
    fclose(p);
}
int main(int argc , char **argv)
{
    char *buf  = NULL ;
    if(argc!=3)
    {
        printf("./a.out srcfile destfile\n");
        exit(0) ;
    }
    buf=readfromsrcfile(argv[1]);
    writetodestfile(buf,argv[2]);
    free(buf);
}
         
