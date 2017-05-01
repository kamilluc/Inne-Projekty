#include <iostream>
#include <fstream>
using namespace std;
struct dane_w
{
    int od_1;
    int odl;
	int do_1;
    dane_w *next;
};
int sprawdz( int *&tab,int l)
{
	int z=1;
	for(int i=0;i<20;i++)
	{
		if((*(tab+i))==l)
		{
			z=0;
		}
	return z;
}
}
void show(dane_w *head)
{ cout<<"head-> ";
  dane_w *p=head;
  while(p!=NULL)
  { cout<<"od "<<p->od_1<<" do "<<p->do_1<<" dlugosc "<<p->odl<<" -> ";
   p=p->next;
  }
cout<<"NULL"<<endl;
}
int main()
{
	fstream czytaj;
	czytaj.open("C:\\Users\\student\\Desktop\\macierz.txt");
	int size;
	czytaj>>size;
	int ** tablica = new int * [size];
	for (int i = 0; i<size; i++)
	{
		tablica[i] = new int [size];
	}
	for (int i = 0; i<size; i++)
	{
		cout<<endl;
		for (int j = 0; j<size; j++)
		{	 czytaj>>tablica[i][j];
			cout<<tablica[i][j]<<"  ";
		}
	}
	cout<<size<<endl;
	czytaj.close();
	dane_w *z=NULL;
	int tab[20];
	int *t=tab;
	for(int i=0;i<20;i++)
	{
		tab[i]=0;
	}
	 for(int h=0;h<size;h++)
        {
            for(int g=(size-1);g>=0;g--)
            {   int c=sprawdz(t,tablica[h][g]);
                if(tablica[h][g]>0 && c!=0)
                {
                   if(z==NULL)
                   {
                       dane_w *pom=new dane_w;
                       pom->next=NULL;
                       int w=g+1;
					   pom->od_1=(h+1);
					   pom->do_1=w;
                       pom->odl=tablica[h][g];
                       z=pom;
                   }
                   else
                   {
                       dane_w *pom=new dane_w;
                       pom->next=z;
                       int w=g+1;
                       pom->od_1=(h+1);
					   pom->do_1=w;
                       pom->odl=tablica[h][g];
                       z=pom;
                   }
                }
            }
        }
	 cout<<"lista krawedzi"<<endl;
	 show(z);

	cout<<"hello"<<endl;
	dane_w **tabh=new dane_w*[size];
	//tworzenie listy head
    for(int i=0;i<size;i++)
    {
        tabh[i]=NULL;
    }
	//robienie listy
        for(int h=0;h<size;h++)
        {
            for(int g=(size-1);g>=0;g--)
            {
                if(tablica[h][g]>0)
                {
                   if(tabh[h]==NULL)
                   {
                       dane_w *pom=new dane_w;
                       pom->next=NULL;
                       int w=g+1;
					   pom->od_1=(h+1);
					   pom->do_1=w;
                       pom->odl=tablica[h][g];
                       tabh[h]=pom;
                   }
                   else
                   {
                       dane_w *pom=new dane_w;
                       pom->next=tabh[h];
                       int w=g+1;
                       pom->od_1=(h+1);
					   pom->do_1=w;
                       pom->odl=tablica[h][g];
                       tabh[h]=pom;
                   }
                }
            }
        }
        cout<<"lista s¹siedztwa"<<endl;
	for(int i=0;i<size;i++)
	{
		show(tabh[i]);
	}
		system("PAUSE");
	return 0;
	
}