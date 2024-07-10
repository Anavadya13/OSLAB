#include <stdio.h>
void
main ()
{
    int i, j, k, y, n, m, flag, ind = 0;
    printf ("enter the number of processes : ");
    scanf ("%d", &n);
    printf ("enter the number of resources : ");
    scanf ("%d", &m);
    int alloc[n][m], max[n][m], need[n][m], avail[m], work[m], finish[n],safeseq[n];
    printf ("enter the allocation mtrix: \n");
    for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
          {
              scanf ("%d", &alloc[i][j]);
          }} 
    printf ("enter the max mtrix: \n");
    for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
          {
              scanf ("%d", &max[i][j]);    }} 
    printf ("enter the available matrix : \n");
    for (int i = 0; i < m; i++)
     {
        scanf ("%d", &avail[i]);
      } 
    for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
            {
        need[i][j] = max[i][j] - alloc[i][j];           }} 
    printf ("the need matrix is :\n");
    for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
      {
          printf ("%d\t", need[i][j]);
      } 
      printf ("\n");
      } 
    for (int i = 0; i < m; i++)
     {
       work[i] = avail[i];
      } 
    for (int i = 0; i < n; i++)
     {
       finish[i] = 0;      } 
    for (int k = 0; k < n; k++)
     {
       for (int i = 0; i < n; i++)
      {
        if (finish[i] == 0)
       {
         flag = 0;
         for (int j = 0; j < m; j++)
        {
          if (need[i][j] > work[j])
         {
           flag = 1;
           break;         }      }
    if (flag == 0){
        safeseq[ind++] = i;
    for (int y = 0; y < m; y++)
    {
        work[y] = work[y] + alloc[i][y];         } 
    finish[i] = 1;
        }       }      }     }
    printf ("the safe sequence is : \n");
    for (int i = 0; i < n; i++){
        printf ("P%d ", safeseq[i]);
       }} 
 
