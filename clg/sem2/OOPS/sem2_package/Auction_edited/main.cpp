#include<iostream>
#include<conio.h>
#include<cstring>
#include<windows.h>
#include<fstream>
#include"Auction.h"

using namespace std;

void instructions()
{
    cout<<"\t\t\t\t\t->->->->->->->->->->Welcome to the IPL Auction 2020<-<-<-<-<-<-<-<-<-<-";
    Sleep(1000);
    cout<<"\n\n\t\t\t\tThis is an auction for the Mini IPL which is going to be conducted by BCCI in the year 2020";
    Sleep(300);
    cout<<"\n\t\t\t\tTeams which are eligible to participate in this Mini IPL are the teams which qualified for the playoffs in IPL 2019";
    Sleep(300);
    cout<<"\n\t\t\t\tEach team has to retain 5 players from their original IPL squad";
    Sleep(300);
    cout<<"\n\t\t\t\tThere will be no restriction for the team composition";
    Sleep(300);
    cout<<"\n\t\t\t\tThe purse money for each team is $8500000";
    Sleep(300);
    cout<<"\n\t\t\t\tThe teams participating in today's auction: ";
    Sleep(300);
    cout<<"\n\t\t\t\t1]Chennai Super Kings";
    Sleep(300);
    cout<<"\n\t\t\t\t2]Mumbai Indians";
    Sleep(300);
    cout<<"\n\t\t\t\t3]Delhi Capitals";
    Sleep(300);
    cout<<"\n\t\t\t\t4]Sunrisers Hyderabad";
    Sleep(500);
    cout<<"\n\n\t\t\t\tHow to bid in this auction:";
    Sleep(300);
    cout<<"\n\t\t\t\t1.The player who will be coming to the auction will be listed with his stats";
    Sleep(300);
    cout<<"\n\t\t\t\t2.A timer of 30 seconds will be running after all his stats are displayed";
    Sleep(300);
    cout<<"\n\t\t\t\t3.Any team which is interested in buying/bidding should enter their team number first and should enter the amount";
    Sleep(300);
    cout<<"\n\t\t\t\t4.Numbers for the respective teams is shown above";
    Sleep(300);
    cout<<"\n\t\t\t\t5.A timer will be running again for other teams to bid";
    Sleep(300);
    cout<<"\n\t\t\t\t6.When the timer gets finished the player will be sold to the team with the highest bid";
    Sleep(300);
    cout<<"\n\t\t\t\t7.While bidding amount entered by the teams should be greater than the base as well as the previous bid";
    Sleep(300);
    cout<<"\n\t\t\t\t8.If none of the team is interested in bidding the player will remain unsold and he will be brought back to the auction one more time";
    Sleep(300);
    cout<<"\n\t\t\t\t9.If no one buys the player for the second time he will leave the auction unsold";
    Sleep(500);
    cout<<"\n\n\n\t\t\t\tOnce the auction gets over all the teams will be displayed with the list of players retained and bought";

}

int main()
{
    inData *dat=new inData[30];
    currentPlayer cp1;
    Player p[30],temp;
    int i,j,k=0,n,x=1,y=1,a;
    int cno=1,mno=1,dno=1,sno=1;
    long int pmcsk=8500000,pmdc=8500000,pmmi=8500000,pmsrh=8500000;
    long int cskm=1,mim=1,dcm=1,srhm=1;
    fstream play,csk,mi,dc,srh;
    fstream csk1,mi1,dc1,srh1;
    fstream csk2,mi2,dc2,srh2;
    fstream auc;
    char ch;
    CSK c;
    MI m;
    DC d;
    SRH s;

    strcpy(dat[0].name,"Sam Billings");
    dat[0].mat=22;
    dat[0].runs=334;
    dat[0].hs=56;
    dat[0].wkts=0;
    dat[0].bavg=0;
    dat[0].eco=0;
    dat[0].avg=17.57;
    dat[0].sr=133.60;
    strcpy(dat[1].name,"Imran Tahir");
    dat[1].mat=55;
    dat[1].runs=20;
    dat[1].hs=5;
    dat[1].wkts=79;
    dat[1].bavg=20.39;
    dat[1].eco=7.88;
    dat[1].avg=5.00;
    dat[1].sr=74.07;
    strcpy(dat[2].name,"Deepak Chahar");
    dat[2].mat=34;
    dat[2].runs=71;
    dat[2].hs=39;
    dat[2].wkts=33;
    dat[2].bavg=26.51;
    dat[2].eco=7.63;
    dat[2].avg=11.83;
    dat[2].sr=161.36;
    strcpy(dat[3].name,"Shardul Thakur");
    dat[3].mat=36;
    dat[3].runs=36;
    dat[3].hs=15;
    dat[3].wkts=36;
    dat[3].bavg=29.58;
    dat[3].eco=9.03;
    dat[3].avg=7.2;
    dat[3].sr=171.42;
    strcpy(dat[4].name,"Harbhajan Singh");
    dat[4].mat=160;
    dat[4].runs=829;
    dat[4].hs=64;
    dat[4].wkts=150;
    dat[4].bavg=26.44;
    dat[4].eco=7.05;
    dat[4].avg=15.64;
    dat[4].sr=138.16;
    strcpy(dat[5].name,"Shane Watson");
    dat[5].mat=134;
    dat[5].runs=3575;
    dat[5].hs=117;
    dat[5].wkts=92;
    dat[5].bavg=29.15;
    dat[5].eco=7.93;
    dat[5].avg=31.08;
    dat[5].sr=139.53;
    strcpy(dat[6].name,"Ishant Sharma");
    dat[6].mat=89;
    dat[6].runs=55;
    dat[6].hs=10;
    dat[6].wkts=72;
    dat[6].bavg=35.83;
    dat[6].eco=8.09;
    dat[6].avg=9.16;
    dat[6].sr=90.16;
    strcpy(dat[7].name,"Axar Patel");
    dat[7].mat=82;
    dat[7].runs=796;
    dat[7].hs=44;
    dat[7].wkts=71;
    dat[7].bavg=29.98;
    dat[7].eco=7.45;
    dat[7].avg=18.95;
    dat[7].sr=126.34;
    strcpy(dat[8].name,"Trent Boult");
    dat[8].mat=33;
    dat[8].runs=12;
    dat[8].hs=6;
    dat[8].wkts=38;
    dat[8].bavg=29.47;
    dat[8].eco=8.78;
    dat[8].avg=6;
    dat[8].sr=85.71;
    strcpy(dat[9].name,"Mayank Agarwal");
    dat[9].mat=77;
    dat[9].runs=1266;
    dat[9].hs=68;
    dat[9].wkts=0;
    dat[9].bavg=0;
    dat[9].eco=0;
    dat[9].avg=18.34;
    dat[9].sr=128.13;
    strcpy(dat[10].name,"Mujeeb Ur Rahman");
    dat[10].mat=16;
    dat[10].runs=10;
    dat[10].hs=10;
    dat[10].wkts=17;
    dat[10].bavg=28.23;
    dat[10].eco=7.93;
    dat[10].avg=5;
    dat[10].sr=90.90;
    strcpy(dat[11].name,"Nitish Rana");
    dat[11].mat=46;
    dat[11].runs=1085;
    dat[11].hs=85;
    dat[11].wkts=7;
    dat[11].bavg=17;
    dat[11].eco=7.84;
    dat[11].avg=29.32;
    dat[11].sr=134.61;
    strcpy(dat[12].name,"Chris Lynn");
    dat[12].mat=41;
    dat[12].runs=1280;
    dat[12].hs=93;
    dat[12].wkts=0;
    dat[12].bavg=0;
    dat[12].eco=0;
    dat[12].avg=33.68;
    dat[12].sr=140;
    strcpy(dat[13].name,"Sunil Narine");
    dat[13].mat=110;
    dat[13].runs=771;
    dat[13].hs=75;
    dat[13].wkts=122;
    dat[13].bavg=23.31;
    dat[13].eco=6.67;
    dat[13].avg=17.52;
    dat[13].sr=168.34;
    strcpy(dat[14].name,"Quinton de Kock");
    dat[14].mat=50;
    dat[14].runs=1456;
    dat[14].hs=108;
    dat[14].wkts=0;
    dat[14].bavg=0;
    dat[14].eco=0;
    dat[14].avg=30.33;
    dat[14].sr=131.28;
    strcpy(dat[15].name,"Ishan Kishan");
    dat[15].mat=37;
    dat[15].runs=695;
    dat[15].hs=62;
    dat[15].wkts=0;
    dat[15].bavg=0;
    dat[15].eco=0;
    dat[15].avg=21.06;
    dat[15].sr=130.88;
    strcpy(dat[16].name,"Mitchell McClenaghan");
    dat[16].mat=56;
    dat[16].runs=85;
    dat[16].hs=20;
    dat[16].wkts=71;
    dat[16].bavg=25.39;
    dat[16].eco=8.49;
    dat[16].avg=6.53;
    dat[16].sr=121.42;
    strcpy(dat[17].name,"Yuvraj Singh");
    dat[17].mat=132;
    dat[17].runs=2750;
    dat[17].hs=83;
    dat[17].wkts=36;
    dat[17].bavg=29.91;
    dat[17].eco=7.43;
    dat[17].avg=24.77;
    dat[17].sr=129.71;
    strcpy(dat[18].name,"Suryakumar Yadav");
    dat[18].mat=85;
    dat[18].runs=1548;
    dat[18].hs=72;
    dat[18].wkts=0;
    dat[18].bavg=0;
    dat[18].eco=0;
    dat[18].avg=28.14;
    dat[18].sr=131.96;
    strcpy(dat[19].name,"Sanju Samson");
    dat[19].mat=93;
    dat[19].runs=2209;
    dat[19].hs=102;
    dat[19].wkts=0;
    dat[19].bavg=0;
    dat[19].eco=0;
    dat[19].avg=27.61;
    dat[19].sr=130.24;
    strcpy(dat[20].name,"Rahul Tripathi");
    dat[20].mat=34;
    dat[20].runs=758;
    dat[20].hs=93;
    dat[20].wkts=0;
    dat[20].bavg=0;
    dat[20].eco=0;
    dat[20].avg=26.13;
    dat[20].sr=137.31;
    strcpy(dat[21].name,"Moeen Ali");
    dat[21].mat=16;
    dat[21].runs=297;
    dat[21].hs=66;
    dat[21].wkts=9;
    dat[21].bavg=29.55;
    dat[21].eco=6.96;
    dat[21].avg=24.75;
    dat[21].sr=165.92;
    strcpy(dat[22].name,"Pawan Negi");
    dat[22].mat=50;
    dat[22].runs=365;
    dat[22].hs=36;
    dat[22].wkts=34;
    dat[22].bavg=27.61;
    dat[22].eco=7.86;
    dat[22].avg=14.03;
    dat[22].sr=126.29;
    strcpy(dat[23].name,"Parthiv Patel");
    dat[23].mat=139;
    dat[23].runs=2848;
    dat[23].hs=81;
    dat[23].wkts=0;
    dat[23].bavg=0;
    dat[23].eco=0;
    dat[23].avg=22.60;
    dat[23].sr=120.78;
    strcpy(dat[24].name,"Tim Southee");
    dat[24].mat=40;
    dat[24].runs=115;
    dat[24].hs=36;
    dat[24].wkts=28;
    dat[24].bavg=46.17;
    dat[24].eco=8.73;
    dat[24].avg=14.37;
    dat[24].sr=127.77;
    strcpy(dat[25].name,"Mohammad Nabi");
    dat[25].mat=13;
    dat[25].runs=135;
    dat[25].hs=31;
    dat[25].wkts=11;
    dat[25].bavg=27.18;
    dat[25].eco=24.63;
    dat[25].avg=15.00;
    dat[25].sr=148.35;
    strcpy(dat[26].name,"Martin Guptill");
    dat[26].mat=13;
    dat[26].runs=220;
    dat[26].hs=50;
    dat[26].wkts=0;
    dat[26].bavg=0;
    dat[26].eco=0;
    dat[26].avg=22.50;
    dat[26].sr=137.75;
    strcpy(dat[27].name,"Vijay Shankar");
    dat[27].mat=33;
    dat[27].runs=557;
    dat[27].hs=63;
    dat[27].wkts=2;
    dat[27].bavg=73.50;
    dat[27].eco=10.50;
    dat[27].avg=30.94;
    dat[27].sr=133.89;
    strcpy(dat[28].name,"Jony Bairstow");
    dat[28].mat=10;
    dat[28].runs=445;
    dat[28].hs=114;
    dat[28].wkts=0;
    dat[28].bavg=0;
    dat[28].eco=0;
    dat[28].avg=55.62;
    dat[28].sr=157.24;
    strcpy(dat[29].name,"Deepak Hooda");
    dat[29].mat=61;
    dat[29].runs=524;
    dat[29].hs=54;
    dat[29].wkts=7;
    dat[29].bavg=44.71;
    dat[29].eco=8.42;
    dat[29].avg=14.55;
    dat[29].sr=127.18;

    for(i=0;i<30;i++)
    {
        p[i].setPlayer(dat[i]);
    }

    delete dat;

    instructions();

    play.open("players.txt",ios::out);
    for(i=0;i<30;i++)
    {
        play.write((char*)&p[i],sizeof(p[i]));
    }
    play.close();

    csk.open("csk.txt",ios::out);
    csk<<"->->CHENNAI SUPER KINGS<-<-";
    csk<<"\nOWNER\t:\tChennai Super Kings Cricket ltd.";
    csk<<"\nHOME GROUND\t:\tM. A. Chidambaram Stadium";
    csk<<"\nCOACH\t:\tStephen Fleming";
    csk<<"\nCAPTAIN\t:M.S.Dhoni";
    csk<<"\nRETAINED PLAYERS\t:";
    csk<<"\n1] M.S.Dhoni";
    csk<<"\n2] Ravindra Jadeja";
    csk<<"\n3] Suresh Raina";
    csk<<"\n4] Dwayne Bravo";
    csk<<"\n5] Faf Du Plessis";
    csk<<"\n\nBOUGHT PLAYERS:";
    csk.close();

    mi.open("mi.txt",ios::out);
    mi<<"->->MUMBAI INDIANS<-<-";
    mi<<"\nOWNER\t:\tIndiawin Sports Pvt. Ltd.";
    mi<<"\nHOME GROUND\t:\tWankhede Stadium";
    mi<<"\nCOACH\t:\tMahela Jayawardene";
    mi<<"\nCAPTAIN\t:\tRohit Sharma";
    mi<<"\nRETAINED PLAYERS\t:";
    mi<<"\n1] Rohit Sharma";
    mi<<"\n2] Jasprit Bumrah";
    mi<<"\n3] Hardik Pandya";
    mi<<"\n5] Kieron Pollard";
    mi<<"\n\nBOUGHT PLAYERS:";
    mi.close();

    dc.open("dc.txt",ios::out);
    dc<<"->->DELHI CAPITALS<-<-";
    dc<<"\nOWNER\t:\tGMR Sports Pvt .Ltd & JSW Sports Pvt Ltd";
    dc<<"\nHOME GROUND\t:\tFeroz Shah Kotla Ground";
    dc<<"\nCOACH\t:\tRicky Ponting";
    dc<<"\nCAPTAIN\t:\tShreyas Iyer";
    dc<<"\nRETAINED PLAYERS\t:";
    dc<<"\n1] Shreyas Iyer";
    dc<<"\n2] Kagiso Rabada";
    dc<<"\n3] Rishabh Pant";
    dc<<"\n4] Shikar Dhawan";
    dc<<"\n5] Chris Morris";
    dc<<"\n\nBOUGHT PLAYERS:";
    dc.close();

    srh.open("srh.txt",ios::out);
    srh<<"->->SUNRISERS HYDERABAD<-<-";
    srh<<"\nOWNER\t:\tSUN TV Network";
    srh<<"\nHOME GROUND\t:\tRajiv Gandhi Intl. Cricket Stadium";
    srh<<"\nCOACH\t:\tTom Moody";
    srh<<"\nCAPTAIN\t:\tKane Williamson";
    srh<<"\nRETAINED PLAYERS\t:";
    srh<<"\n1] Kane Williamson";
    srh<<"\n2] David Warner";
    srh<<"\n3] Rashid Khan";
    srh<<"\n4] Bhuvneshwar Kumar";
    srh<<"\n5] Shakib Al Hasan";
    srh<<"\n\nBOUGHT PLAYERS:";
    srh.close();

    Sleep(500);
    auc.open("players.txt",ios::in);
    for(i=0;i<3;i++)
    {
        p[i].getData(&cp1);
        Sleep(300);
        cout<<"\n\n\n\nThe player who is coming to the auction now and his stats are:\n";
        Sleep(1000);
        auc.read((char*)&temp,sizeof(temp));
        temp.display();
        Sleep(2000);
        cout<<"\n\nThe base money for the player is $140000";
        l:
        Sleep(1000);
        cout<<"\n\nTeams can start bidding now ";
        for(j=0;j<30;j++)
        {
            cout<<j+1<<"\t";
            if(kbhit())
                break;
            Sleep(1000);
        }
        if(j==30)
            goto last;
        cout<<"\n\nEnter your team number:";
        cin>>n;
        if(n==1)
        {
            l1:
            cout<<"\n\nNow enter your bid amount $";
            cin>>cskm;
            cout<<"\n\nChennai Super Kings' remaining purse money if they buy this player for current bid price will be $"<<pmcsk-cskm;
            try
            {
                if(cskm<140000)
                    throw x;
                else
                {
                    if(cp1.mon<cskm)
                    {
                        cp1.mon=cskm;
                        goto l;
                    }
                    else
                    {
                        cout<<"\n\nEnter amount greater than the previous bid";
                        goto l;
                    }
                }
            }
            catch(int x)
            {
                cout<<"\n\nEnter amount greater than the base price";
                goto l1;
            }
        }
        else if(n==2)
        {
            l2:
            cout<<"\n\nNow enter your bid amount $";
            cin>>mim;
            cout<<"\n\nMumbai Indians' remaining purse money if they buy this player for current bid price will be $"<<pmmi-mim;
            try
            {
                if(mim<140000)
                    throw x;
                else
                {
                    if(cp1.mon<mim)
                    {
                        cp1.mon=mim;
                        goto l;
                    }
                    else
                    {
                        cout<<"\n\nEnter amount greater than the previous bid";
                        goto l;
                    }
                }
            }
            catch(int x)
            {
                cout<<"\n\nEnter amount greater than the base price";
                goto l2;
            }
        }
        else if(n==3)
        {
            l3:
            cout<<"\n\nNow enter your bid amount $";
            cin>>dcm;
            cout<<"\n\nDelhi Capitals' remaining purse money if they buy this player for current bid price will be $"<<pmdc-dcm;
            try
            {
                if(dcm<140000)
                    throw x;
                else
                {
                    if(cp1.mon<dcm)
                    {
                        cp1.mon=dcm;
                        goto l;
                    }
                    else
                    {
                        cout<<"\n\nEnter amount greater than the previous bid";
                        goto l;
                    }
                }
            }
            catch(int x)
            {
                cout<<"\n\nEnter amount greater than the base price";
                goto l3;
            }
        }
        else if(n==4)
        {
            l4:
            cout<<"\n\nNow enter your bid amount $";
            cin>>srhm;
            cout<<"\n\nSunrisers Hyderabad's remaining purse money if they buy this player for current bid price will be $"<<pmsrh-srhm;
            try
            {
                if(srhm<140000)
                    throw x;
                else
                {
                    if(cp1.mon<srhm)
                    {
                        cp1.mon=srhm;
                        goto l;
                    }
                    else
                    {
                        cout<<"\n\nEnter amount greater than the previous bid";
                        goto l;
                    }
                }
            }
            catch(int x)
            {
                cout<<"\n\nEnter amount greater than the base price";
                goto l4;
            }
        }
        else
        {
            cout<<"\n\nEnter a valid team number:";
            goto l;
        }
        last:
        csk1.open("csk.txt",ios::app);
        mi1.open("mi.txt",ios::app);
        srh1.open("srh.txt",ios::app);
        dc1.open("dc.txt",ios::app);
        if(cskm==cp1.mon && cskm!=0)
        {
            cout<<"\n\n"<<cp1.name<<" is sold to CHENNAI SUPER KINGS.";
            pmcsk-=cskm;
            c=cp1;
            if(k==0)
            {
                p[i].setData(cp1);
            }
            else
            {
                if(k==a)
                {
                    p[k].setData(cp1);
                }
            }
            csk1<<"\n\n"<<cno<<" "<<c.name1<<" bought for $"<<cskm;
            cno++;
        }
        else if(mim==cp1.mon && mim!=0)
        {
            cout<<"\n\n"<<cp1.name<<" is sold to MUMBAI INDIANS.";
            pmmi-=mim;
            m=cp1;
            if(k==0)
            {
                p[i].setData(cp1);
            }
            else
            {
                if(k==a)
                {
                    p[k].setData(cp1);
                }
            }
            mi1<<"\n\n"<<mno<<" "<<m.name2<<" bought for $"<<mim;
            mno++;
        }
        else if(dcm==cp1.mon && dcm!=0)
        {
            cout<<"\n\n"<<cp1.name<<" is sold to DELHI CAPITALS.";
            pmdc-=dcm;
            d=cp1;
            if(k==0)
            {
                p[i].setData(cp1);
            }
            else
            {
                if(k==a)
                {
                    p[k].setData(cp1);
                }
            }
            dc1<<"\n\n"<<dno<<" "<<d.name3<<" bought for $"<<dcm;
            dno++;
        }
        else if(srhm==cp1.mon && srhm!=0)
        {
            cout<<"\n\n"<<cp1.name<<" is sold to SUNRISERS HYDERABAD.";
            pmsrh-=srhm;
            s=cp1;
            if(k==0)
            {
                p[i].setData(cp1);
            }
            else
            {
                if(k==a)
                {
                    p[k].setData(cp1);
                }
            }
            srh1<<"\n\n"<<sno<<" "<<s.name4<<" bought for $"<<srhm;
            sno++;
        }
        else
        {
            cout<<"\n\n"<<cp1.name<<" remains unsold";
        }
        csk1.close();
        mi1.close();
        dc1.close();
        srh1.close();
        cskm=mim=dcm=srhm=0;
    }
    for(k=0;k<3;k++)
    {
        p[k].getData(&cp1);
        if(cp1.mon==0)
        {
            if(cp1.unsol==0)
            {
                a=k;
                cout<<"\n\n"<<cp1.name<<" is unsold,now he will be listed now interested teams can bid on him";
                cout<<"\nInterested teams can bid on him ";
                cout<<"\nName:"<<cp1.name;
                cout<<"\nMatches:"<<cp1.mat;
                cout<<"\nRuns:"<<cp1.runs;
                cout<<"\nHigh Score:"<<cp1.hs;
                cout<<"\nWickets:"<<cp1.wkts;
                cout<<"\nBowling Average:"<<cp1.bavg;
                cout<<"\nEconomy:"<<cp1.eco;
                cout<<"\nBatting Average:"<<cp1.avg;
                cout<<"\nStrike Rate:"<<cp1.sr;
                cp1.unsol++;
                goto l;
            }
        }
    }
    csk2.open("csk.txt",ios::in);
    mi2.open("mi.txt",ios::in);
    dc2.open("dc.txt",ios::in);
    srh2.open("srh.txt",ios::in);
    cout<<"\nAll teams and their players are:\n";
    Sleep(1000);
    while(!csk2.eof())
    {
        csk2.get(ch);
        cout<<ch;
    }
    cout<<endl<<endl;
    Sleep(1000);
    while(!mi2.eof())
    {
        mi2.get(ch);
        cout<<ch;
    }
    cout<<endl<<endl;
    Sleep(1000);
    while(!dc2.eof())
    {
        dc2.get(ch);
        cout<<ch;
    }
    cout<<endl<<endl;
    Sleep(1000);
    while(!srh2.eof())
    {
        srh2.get(ch);
        cout<<ch;
    }
    Sleep(1000);
    cout<<"\n\n\n\t\t\t\t\t\tThank you everyone for participating in this auction";
    Sleep(500);
    cout<<"\n\t\t\t\t\t\t\tBEST OF LUCK FOR THE TEAMS WHICH ARE PLAYING IN MINI IPL 2020!!!";
    csk2.close();
    mi2.close();
    dc2.close();
    srh2.close();


    return 0;
}
