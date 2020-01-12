/* strtok example: 12.01.2020:
  first row is number of rows and columns, as I need for reading colorfiles;
  take the first entry of a row as the index of the row
*/ 
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
  int columns,rows,ind;
  
  
  fp=fopen("data3","r");
  fscanf(fp,"%i %i",&rows,&columns);
  double **arr=(double**)malloc(rows*sizeof(double*));
  for(irow=0;irow<rows;irow++)arr[irow]=(double*)malloc(columns*sizeof(double));
  for(irow=0;irow<rows;irow++)for(icol=0;icol<columns;icol++)arr[irow][icol]=0.0;

  while (fgets(str,sizeof(str),fp)!=NULL)
  {
    pch=strtok_r(str," \n",&state);
    int colloop=0;
    while(pch != NULL)
    {
      if (colloop==0) ind=atoi(pch);
      arr[ind][colloop]=atof(pch);
      pch=strtok_r(NULL," ,\t_",&state);
      colloop++;
    }
  }
  
  fclose(fp);
  
  for(irow=0;irow<rows;irow++)
  {
    for(icol=0;icol<columns;icol++)
      if(icol==0)printf("%i ",(int)arr[irow][icol]);
      else printf("%lf ",arr[irow][icol]);
    printf("\n");
  }
  
  for (irow=0;irow<rows;irow++) free(arr[irow]); free(arr);
  return 0;
}
