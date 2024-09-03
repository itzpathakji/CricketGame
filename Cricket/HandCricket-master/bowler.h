#include <bits/stdc++.h>
#ifndef BOWLER_H
#define BOWLER_H

using namespace std;

class Bowler{
    private:
    //Data Members
    int wickets[3];
    int runs_conceeded[3];
    float economy[3];

    public:
    //Constructors
    Bowler();
    //Member Functions
    void setWickets(int m, int w);
    int getWickets(int m);
    int getTotalWickets(int m);
    void setRunsConceeded(int m, int runs);
    int getRunsConceeded(int m);
    void setEconomy(int m, float overs);
    float getEconomy(int m);
    void displayBestFigures();
    void displayBowlerStats();
};

//Public Member Functions
Bowler:: Bowler(){
    for(int i=0;i<3;i++){
        wickets[i] = 0;
        runs_conceeded[i] = 0;
        economy[i] = 0;
    }
}
void Bowler:: setWickets(int m, int w){
    wickets[m-1] += w;
}
int Bowler:: getWickets(int m){
    return wickets[m-1];
}
int Bowler:: getTotalWickets(int m){
    int total = 0;
    for(int i=1;i<=m;i++){
        total += getWickets(i);
    }
    return total;
}
void Bowler:: setRunsConceeded(int m, int runs){
    runs_conceeded[m-1] += runs;
}
int Bowler:: getRunsConceeded(int m){
    return runs_conceeded[m-1];
}
void Bowler:: setEconomy(int m, float overs){
    economy[m-1] = runs_conceeded[m-1]/overs;
}
float Bowler:: getEconomy(int m){
    return economy[m-1];
}
void Bowler:: displayBestFigures(){
    int runs = INT_MAX, wicket = INT_MIN;
    for(int i=0;i<3;i++){
        if(wickets[i]>=wicket || (runs_conceeded[i]&&runs_conceeded[i]<runs)){
            runs = runs_conceeded[i];
            wicket = wickets[i];
        }
    }
    cout<<"\nBest Figures: "<<runs<<"-"<<wicket<<endl;
}
void Bowler:: displayBowlerStats(){
    for(int i=0;i<3;i++){
        cout<<"Match "<<i+1<<setw(15)<<runs_conceeded[i]<<"-"<<wickets[i]<<"\n\n";
    }

}

#endif