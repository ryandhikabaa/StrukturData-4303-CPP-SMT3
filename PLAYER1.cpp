#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct player
{
    string nama;
    int nilai;
    player *next;
};
player *head, *tail;
int top=1;
int maks=5;

void tampil()
{
	player *bantu;
	int x=1;
	bantu=head;
	do
	{
		cout<<x<<"."<<bantu->nama<<" - "<<bantu->nilai<<endl;
		bantu=bantu->next;
		x++;
	}
	while(bantu!=NULL);
	cout<<endl;
}

void nodebaru(string a, int b)
{
	player *baru;
	baru=new player;
	baru->nama=a;
	baru->nilai=b;
	baru->next=NULL;
	head=tail=baru;
}

void nodebelakang(string a, int b)
{
	player *baru;
	baru=new player;
	baru->nama=a;
	baru->nilai=b;
	baru->next=NULL;
	tail->next=baru;
	tail=baru;
}

void nodedepan(string a, int b)
{
	player *baru;
	baru=new player;
	baru->nama=a;
	baru->nilai=b;
	baru->next=head;
	head=baru;
}

void deletebelakang()
{
	player *bantu;
	bantu=head;
	while(bantu!=NULL)
	{
		if(bantu->next->nama==tail->nama)
		{
			bantu->next=NULL;
			delete tail;
			tail=bantu;		
		}
		bantu=bantu->next;
	}
}

void nodetengah(string a, int b)
{
	player *bantu, *baru;
	baru=new player;
	baru->nama=a;
	baru->nilai=b;
	baru->next=NULL;
	
	bantu=head;
	do
	{
		if((b < bantu->nilai) && (b > bantu->next->nilai))
		{
			baru->next=bantu->next;
			bantu->next=baru;
			break;
		}
		bantu=bantu->next;
	}
	while(bantu!=NULL);
}


int main()
{
    string nmplayer[11]={"Agus","Indah","Heru","Kiki","Bagus","Yuli","Budi","Carlie","Linda","Putri","Feri"};
    int point[11]={100,50,110,120,80,90,140,95,160,115,88};
    
    for(int a=0;a<=10;a++)
    {
        cout<<"Hasil Permainan Terakhir : "<<nmplayer[a]<<" "<<point[a]<<endl;
        /*disini code utk mengatur (menyimpan/menghapus) nama player dan nilainya*/
        if(top==1)
        {
        	nodebaru(nmplayer[a],point[a]);
         	top++;
  		}
		if((top<maks) && (tail->nilai>point[a]))
		{
			nodebelakang(nmplayer[a],point[a]);
			top++;
		}
		if(point[a]>head->nilai)
		{
			nodedepan(nmplayer[a],point[a]);
			top++;
		}
		
		if((point[a] < head->nilai) && (point[a] > tail->nilai))
		{
			nodetengah(nmplayer[a],point[a]);
			top++;
		}
		
		if(top>maks+1)
		{
			deletebelakang();
			top--;
		}
		tampil();
		getch();
	}

    return 0;
}
