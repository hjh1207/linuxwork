void show (int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
  printf("%4d :%4d\n",i,a[i]);
}
void init(int *a,int n)
{
int x,i;
    srand(time(0));
    for(i=0;i<n;)
      { 
        x=rand();
        if(x>0&&x<=1000)
        {
          a[i]=x;
          i++;
        }
      }
}
