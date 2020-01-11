/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//http://www.cplusplus.com/reference/cstring/strtok/
//https://www.mkssoftware.com/docs/man3/strtok_r.3.asp
//https://stackoverflow.com/questions/10711277/reading-columns-from-a-text-file-in-c
int main ()
{
  char str[1024];
  char * pch,*state;
  FILE *fp;int irow,icol;
  int columns=5,rows=6;
  
  int **arr=(int**)malloc(rows*sizeof(int*));
  for(irow=0;irow<rows;irow++) arr[irow]=(int*)malloc(columns*sizeof(int));
  
  for(irow=0;irow<rows;irow++) for(icol=0;icol<columns;icol++)arr[irow][icol]=0;

  fp=fopen("data","r");

  int rowloop=0;
  while (fgets(str,sizeof(str),fp)!=NULL)
  {
    pch=strtok_r(str," \n",&state);
    int colloop=0;
    while(pch != NULL)
    {
      arr[rowloop][colloop]=atoi(pch);
      pch=strtok_r(NULL," .,\t-_",&state);
      colloop++;
    }
    rowloop++;
  }
  
  //printf("%i\n",arr[1][0]);
  fclose(fp);
    
  for(irow=0;irow<rows;irow++)
  {
    for(icol=0;icol<columns;icol++) printf("%i ",arr[irow][icol]);
    printf("\n");
  }
  
  for (irow=0;irow<rows;irow++) free(arr[irow]); free(arr);
  return 0;
}
