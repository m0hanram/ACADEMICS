#include<iostream>
#include"Auction.h"
#include<cstring>

using namespace std;

Player :: Player()
{
    name=new char[50];
    mat=runs=hs=wkts=0;
    bavg=eco=avg=sr=0;
    mon=0;
    unsol=0;
}

void Player :: setPlayer(inData d)
{
    strcpy(name,d.name);
    mat=d.mat;
    runs=d.runs;
    hs=d.hs;
    wkts=d.wkts;
    bavg=d.bavg;
    eco=d.eco;
    avg=d.avg;
    sr=d.sr;
}

void Player :: display()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Matches:"<<mat<<endl;
    cout<<"Runs:"<<runs<<endl;
    cout<<"High Score:"<<hs<<endl;
    cout<<"Wickets:"<<wkts<<endl;
    cout<<"Bowling Average:"<<bavg<<endl;
    cout<<"Economy:"<<eco<<endl;
    cout<<"Batting Average:"<<avg<<endl;
    cout<<"Strike Rate:"<<sr<<endl;
}

void Player :: getData(currentPlayer *cp)
{
    strcpy(cp->name,name);
    cp->mat=mat;
    cp->runs=runs;
    cp->hs=hs;
    cp->wkts=wkts;
    cp->bavg=bavg;
    cp->eco=eco;
    cp->avg=avg;
    cp->sr=sr;
    cp->mon=mon;
    cp->unsol=unsol;
}

void Player :: setData(currentPlayer cp)
{
    mon=cp.mon;
    unsol=cp.unsol;
}

CSK :: CSK()
{
    name1=new char[50];
    mat1=runs1=hs1=wkts1=0;
    bavg1=eco1=avg1=sr1=0;
    mon1=0;
    unsol1=0;
}

CSK& CSK::operator=(const currentPlayer &c)
{
        delete []name1;
        name1 = new char[strlen(c.name)+1];
        strcpy(name1,c.name);
        mat1=c.mat;
        runs1=c.runs;
        hs1=c.hs;
        wkts1=c.wkts;
        bavg1=c.bavg;
        eco1=c.eco;
        avg1=c.avg;
        sr1=c.sr;
        mon1=c.mon;
        unsol1=c.unsol;
    return *this;
}

MI :: MI()
{
    name2=new char[50];
    mat2=runs2=hs2=wkts2=0;
    bavg2=eco2=avg2=sr2=0;
    mon2=0;
    unsol2=0;
}

MI& MI::operator=(const currentPlayer &m)
{
        delete []name2;
        name2 = new char[strlen(m.name)+1];
        strcpy(name2,m.name);
        mat2=m.mat;
        runs2=m.runs;
        hs2=m.hs;
        wkts2=m.wkts;
        bavg2=m.bavg;
        eco2=m.eco;
        avg2=m.avg;
        sr2=m.sr;
        mon2=m.mon;
        unsol2=m.unsol;
    return *this;
}

DC :: DC()
{
    name3=new char[50];
    mat3=runs3=hs3=wkts3=0;
    bavg3=eco3=avg3=sr3=0;
    mon3=0;
    unsol3=0;
}

DC& DC::operator=(const currentPlayer &d)
{
        delete []name3;
        name3 = new char[strlen(d.name)+1];
        strcpy(name3,d.name);
        mat3=d.mat;
        runs3=d.runs;
        hs3=d.hs;
        wkts3=d.wkts;
        bavg3=d.bavg;
        eco3=d.eco;
        avg3=d.avg;
        sr3=d.sr;
        mon3=d.mon;
        unsol3=d.unsol;
    return *this;
}

SRH :: SRH()
{
    name4=new char[50];
    mat4=runs4=hs4=wkts4=0;
    bavg4=eco4=avg4=sr4=0;
    mon4=0;
    unsol4=0;
}

SRH& SRH::operator=(const currentPlayer &s)
{
        delete []name4;
        name4 = new char[strlen(s.name)+1];
        strcpy(name4,s.name);
        mat4=s.mat;
        runs4=s.runs;
        hs4=s.hs;
        wkts4=s.wkts;
        bavg4=s.bavg;
        eco4=s.eco;
        avg4=s.avg;
        sr4=s.sr;
        mon4=s.mon;
        unsol4=s.unsol;
    return *this;
}

currentPlayer :: currentPlayer()
{
    name=new char[50];
    mat=runs=hs=wkts=0;
    bavg=eco=avg=sr=0;
    mon=0;
    unsol=0;
}
