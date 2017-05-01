#include<iostream>
#include<fstream>
#include <conio.h>
using namespace std;
 
struct list{
    int value;
    int odl;
    int y;
    list* next;
};
 
void addbeg(list*&h, int a, int dl=0, int y=0) {               //dodaje element do listy na poczatek
    list* p=new list;
    p->value=a;
    p->odl=dl;
    p->y=y;
    if(h!=NULL){
        p->next=h;
        h=p;
    }else{   
        p->next=NULL;
        h=p;
    }
}
 
list* min_k(list* LS[], int size, int *kol){
	list *p;
	int min;
	bool min_0=true;
	list* p_min=NULL;

	for (int i=0; i<size; i++){
		if (kol[i] == 1){
			p=LS[i];
			while(p){
				if (kol[p->value-1] == 0 && !min_0){
					if(min>p->odl){
						min = p->odl;
						p->y=i;
						p_min=p;
					}
				}
				if (kol[p->value-1] == 0 && min_0){
					min=p->odl;
					min_0=false;
					p_min=p;
					p->y=i;
				}
				
				p=p->next;
			}
		}

	}
	return p_min;
}

void read(list* h){                     //wypisywanie listy
    if(h==NULL)cout<<"lista pusta"<<endl;
      
    while(h!=NULL){
        cout <<h->value<<","<<h->odl<<" ";
        h=h->next;
    }
      
}
void read2(list* h){                     //wypisywanie listy
    if(h==NULL)cout<<"lista pusta"<<endl;
      
    while(h!=NULL){
        cout <<h->value<<","<<h->y<<", "<<h->odl<<" "<<endl;
        h=h->next;
    }
      
}
 
int main(){
	const int w = 8;
    fstream plik;
    string napis;
    list*tab[w];
    list* LS=NULL;
     
    int x;
    int y;
    int dl;
    int MS[w][w];
    for (int i=0; i<w; i++){
        for (int j=0; j<w; j++){
            MS[i][j]=0;
        }
    }
 
    //tworzenie macierzy sasiedztwa z pliku
    plik.open( "nazwa.txt", std::ios::in);
    if( plik.good() == true ){
        std::cout << "Uzyskano dostep do pliku!" << std::endl;
         while( !plik.eof() ){
            plik >> x;
            plik >> y;
            plik >> dl;
            MS[x-1][y-1]=dl;
        }
 
        plik.close();
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
    //wypisanie MS
   /* cout<<"macierz sasiedztwa"<<endl;
    for (int i=0; i<w; i++){
        for (int j=0; j<w; j++){
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
	*/
    //tworzenie LS
    for (int i=0; i<w; i++){
        tab[i]=NULL;
        for (int j=0; j<w; j++){
            if (MS[i][j]>0)
                addbeg(tab[i],j+1,MS[i][j]);
        }
    }
    //wypisanie LS
    cout <<endl<<"lista sasiedztwa"<<endl;
    for (int i=0; i<w; i++){
        cout<<i+1<<" ";
        read(tab[i]);
        cout <<endl;
    }
    //tworzenie LK
    for(int i=0; i<w; i++){
        for(int j=0; j<w; j++){
            if(MS[i][j] > 0){
                addbeg(LS, i+1,MS[i][j],j+1);
            }
        }
    }
    
    //wypisanie LK
   // read2(LS);
	//algorytm prima
	int kol[w];
	for(int i=0; i<w; i++){
		kol[i]=0;
	}
	
	kol[0]=1;
	list* q=min_k(tab,w,kol);
	list* LK=NULL;
	for (int i=0; i<w; i++){
		if(kol[i] == 1){
			q=min_k(tab,w,kol);
		}
		kol[q->value-1]=1;
		addbeg(LK,q->y+1,q->odl,q->value+1);
	}
	cout<<endl<<endl;
	read2(LK);

    system("PAUSE");
    return 0;
}