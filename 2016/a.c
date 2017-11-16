#include<stdio.h>
#include<stdlib.h>
int main()
{
  int B; //the number of tax bands
  double *s, *p;//size and percentage for each tax band
  scanf("%d", &B);
  s = (double *)malloc(sizeof(double)*(B+1));
  p = (double *)malloc(sizeof(double)*(B+1));
  for(int i = 0; i < B; i++)scanf("%lf %lf", &s[i], &p[i]);
  scanf("%lf", &p[B]);//percentage tax above all other tax bands
  int F;//number of friends
  scanf("%d", &F);
  double *e, *m; //earnings and money received after tax by friends
  e = (double *)malloc(sizeof(double)*F);
  m = (double *)malloc(sizeof(double)*F);
  for(int i = 0; i < F; i++)scanf("%lf %lf", &e[i], &m[i]);

  for(int i = 0; i < F; i++)//perform the calculation for each friend
  {
    double gift_before_tax = 0;
    //start off by breaking down the friends earnings
    int b = 0; //current tax bracket
    while(e[i] >= 0)
    {
      e[i] -= s[b++];
    }
    if(e[i] < 0)//a dirty hack
    {
      e[i] *= -1;
      b--;
    }
    int done = 0;
    while(!done)//if he wants money
    {
      if((m[i]*100)/(100-p[b]) >= e[i])
      {
	gift_before_tax += e[i];
	m[i] -= e[i]*((100-p[b])/100);
	if(b < B)
	{
	  b++;
	  e[i] = s[b];
	}
	else
	{
	  e[i] = 1000000;
	}
      }
      else
      {
	gift_before_tax += ((m[i]*100)/(100-p[b]));
	done = 1;
      }
    }
    printf("%.2f\n", gift_before_tax);
  }
}
