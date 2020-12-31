#include<iostream>
#include<string.h>
using namespace std;
class Painting
{
protected:
    string title;
    string artist;
    int value;
public:
    Painting(string title,string artist,int val=400)
    {
        this->title=title;
        this->artist=artist;
        this->value=val;
    }
    virtual void display()
    {
        cout<<"\nTitle:"<<title<<"\nArtist:"<<artist<<"\nValue:"<<value;
    }
};
class FamousPainting:public Painting
{
public:
    FamousPainting(string title,string artist):Painting(title,artist,25000)
    {

    }
    void display()
    {
        cout<<"\nTitle:"<<title<<"\nArtist:"<<artist<<"\nValue:"<<value;
    }
};
int main()
{
    char title[20],artist[20];
    int i;
    Painting *p[10];
    for(i=0;i<10;i++)
    {
        cout<<"\nEnter the title:";
        cin>>title;
        cout<<"\nenter the artist name:";
        cin>>artist;
        if(strcmpi(artist,"Degas")==0 || strcmpi(artist,"Monet")==0 || strcmpi(artist,"Picasso")==0 || strcmpi(artist,"Rembrandt")==0)
        {
            p[i]=new FamousPainting(title,artist);
        }
        else
        {
            p[i]=new Painting(title,artist);
        }
    }
    cout<<"\nDisplay:";
    for(i=0;i<10;i++)
    {
        p[i]->display();
    }
}
