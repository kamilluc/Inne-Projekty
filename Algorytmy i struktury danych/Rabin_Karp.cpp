#include <iostream>
#include <math.h>

using namespace std;

int fh(int m, int n){
    return m%n;
}

int main()
{

    int rozmiar = 17;
    int m=5;
    int modulo = 13;
   // int *tab = new int[rozmiar];
   int tab[] = {2,3,5,9,0,2,3,1,4,1,5,2,6,7,3,9,9};
    // int *klucz = new int[m];
   int  klucz[] = {3,1,4,1,5};
    int *t_fh = new int[rozmiar-m-1];
    int p = 0;
    int p2 = 0;
    int q = 0;
    int fh_p = 0;
    int index = 0;

    //generowanie liczby z klucza
    for (int i=0; i<m; i++){
        p*=10;
        p+=klucz[i];
    }
    fh_p = fh(p,modulo);
  //  cout <<"p: "<< p<<endl;
    cout <<"fh(p): " << fh_p<<endl;
    //generuje pierwsze q
    for (int i=0; i<m; i++){
        q*=10;
        q+=tab[i];
    }
  //  cout <<"q: "<<q<<endl;
    t_fh[0] = fh(q,modulo);
 //   cout <<"fh(q): " << fh(q,modulo) <<endl;
    for (int i=1; i<rozmiar-m+1; i++){
        q-=tab[i-1]*pow(10,m-1);
        q*=10;
        q+=tab[i+m-1];
        t_fh[i] = fh(q,modulo);
    }

    cout<<endl;

    for (int i=0; i<rozmiar-m+1; i++){
 //       cout<<t_fh[i]<<endl;
    }
    p2 = 0;
    for (int i=0; i<rozmiar-m+1; i++){
            cout << "t_fh[i]: " << t_fh[i] <<endl;
        if (t_fh[i] == fh_p){
            cout << "mach" <<endl;
            for (int j=0; j<m; j++){
                p2*=10;
                p2+=tab[i+j];
                cout << "p2: "<< p2 << endl;
            }
            if (p == p2){
                index = i;
            }
        }
    }
    cout <<endl;
    cout <<"index: " << index << endl;
    for (int j=0; j<m; j++){
                cout << tab[j+index] <<endl;
            }





    cout << "Hello world!" << endl;
    return 0;
}
