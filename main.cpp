#include <iostream>

using namespace std;
//mamy merge i middle //dopisz
/*
struct node
{
    int n;
    node* next;
};
node* merge_sort(node* list)
{
    if(list==NULL)return NULL;
    if(list->next==NULL)return list;
    node* middle= middle(list);
    node* list2= middle->next;
    middle->next=NULL;//zerujemy ,zeby rozdzielic listy
    node* l1=merge_sort(list);
    node* l2=merge_sort(list2);
    return merge(l1,l2);
}
int main() {

    return 0;
}
 */
//zadanie domowe
/*
int main()
{
    int z;
    cin>>z;
    for(int i=0;i<z;i++)
    {

    }
}
 */
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
void zeruj(bool t[N])
    {
    for(int i=0;i<k;i++)t[i]=false;
}

int main()
{
    int n,k;//gry,pieniadze
    cin>>n>>k;
    //bool t[k];
    //zeruj(t[]);
    sort(t,t+n);
    N=k;


    return 0;
}
 */

struct node
{
    string imie ;
    node* next;
    node* prev;
};

struct train
{
    node *head;
    node *tail;
};

train* NEW(node* (&osoba),string imie)
{
    train *poc=new train;
    osoba->next=osoba->prev=NULL;
    osoba->imie=imie;
    poc->head=osoba;
    poc->tail=osoba;
    osoba=NULL;
    return poc;
}

train* BACK(train* pociag,node* (&osoba),string imie)
{
    osoba->prev=pociag->tail;
    pociag->tail->next=osoba;
    osoba->imie=imie;
    pociag->tail=osoba;
    osoba=NULL;
    return pociag;
}

train* FRONT(train* pociag,node* (&osoba),string imie)
{
    osoba->next=pociag->head;
    pociag->head->prev=osoba;
    osoba->imie=imie;
    pociag->head=osoba;
    osoba=NULL;
    return pociag;
}

void PRINT(train* pociag)
{
    node* p=pociag->head;
    cout<<pociag<<endl;
    while(p->next!=NULL)
    {
        cout<<p->imie<<"<-";
        p=p->next;
    }
    cout<<p->imie<<endl;
}

train* REVERSE(train* pociag)
{
    node* p=pociag->head;
    node* r;
    pociag->tail=p;
    p->prev=p->next;
    p->next=NULL;
    p=p->prev;
    while(p->next!=NULL)
    {
        r=p->prev;
        p->prev=p->next;
        p->next=r;
        p=p->prev;
    }
    p->next=p->prev;
    p->prev=NULL;
    pociag->head=p;
}

train* UNION(train* pociag1,train* (&pociag2))
{
    pociag1->tail->next=pociag2->head;
    pociag2->head->prev=pociag1->tail;
    pociag1->tail=pociag2->tail;
    pociag2=NULL;
    return pociag1;
}

train* DELFRONT(train* pociag1,train* (&pociag2))
{
    pociag1->head=pociag1->tail=pociag2->head;
    if(pociag2->head==pociag2->tail)pociag2=NULL;
    else pociag2->head=pociag2->head->next;
    return pociag1;
}

train* DELBACK(train* (&pociag2),train* pociag1)
{
    pociag1->head=pociag1->tail=pociag2->tail;
    if(pociag2->head==pociag2->tail)pociag2=NULL;
    else pociag2->tail=pociag2->tail->prev;
    return pociag1;
}
#define x(a) train* t##a
#define z(a) t##a
void polecenia()
{
    int n;
    int licz=0;
    string polecenie,nazwa1,nazwa2;
    cin>>n;
    string nazwy[n]={};
    for(int i=0;i<n;i++)
    {
        cin>>polecenie>>nazwa1>>nazwa2;
        if(polecenie == "NEW")
        {
            node* osoba=new node;
            nazwy[licz]=nazwa1;
            x(licz)=NEW(osoba,nazwa2);
            licz++;
            cout<<nazwy[licz-1];
            continue;
        }
        else if(polecenie == "BACK")
        {
            node* osoba=new node;
            int y=0;
            while(nazwy[y]!=nazwa1)y++;
            BACK(z(y),osoba,nazwa2);
            

        }
    }
}

int main()
{
    polecenia();
}