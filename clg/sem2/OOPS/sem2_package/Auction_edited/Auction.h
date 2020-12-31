#ifndef AUCTION_H_INCLUDED
#define AUCTION_H_INCLUDED

typedef struct
{
    char name[50];
    int mat,runs,hs,wkts;
    float bavg,eco,avg,sr;
}inData;

class currentPlayer
{
public:
    char *name;
    int mat,runs,hs,wkts;
    float bavg,eco,avg,sr;
    long int mon;
    int unsol;
    currentPlayer();
};

class Player
{
protected:
    char *name;
    int mat,runs,hs,wkts;
    float bavg,eco,avg,sr;
    long int mon;
    int unsol;
public:
    Player();
    void setPlayer(inData);
    void display();
    void getData(currentPlayer*);
    void setData(currentPlayer);
};

class CSK : protected Player
{
public:
    char *name1;
    int mat1,runs1,hs1,wkts1;
    float bavg1,eco1,avg1,sr1;
    long int mon1;
    int unsol1;
    CSK();
    CSK& operator=(const currentPlayer&);
};

class MI : protected Player
{
public:
    char *name2;
    int mat2,runs2,hs2,wkts2;
    float bavg2,eco2,avg2,sr2;
    long int mon2;
    int unsol2;
    MI();
    MI& operator=(const currentPlayer&);
};

class DC : protected Player
{
public:
    char *name3;
    int mat3,runs3,hs3,wkts3;
    float bavg3,eco3,avg3,sr3;
    long int mon3;
    int unsol3;
    DC();
    DC& operator=(const currentPlayer&);
};

class SRH : protected Player
{
public:
    char *name4;
    int mat4,runs4,hs4,wkts4;
    float bavg4,eco4,avg4,sr4;
    long int mon4;
    int unsol4;
    SRH();
    SRH& operator=(const currentPlayer&);
};

#endif // AUCTION_H_INCLUDED
