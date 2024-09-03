#include <bits/stdc++.h>
using namespace std;
#include "team.h"
#include "Match.h"
#ifndef SERIES_H
#define SERIES_H


class Series{
    private:
    //Data Members
    static int matches_played;
    
    protected:
    
    Team team1;
    Team team2;
    Match match[3];
    

    public:
    //Constructors
    Series(Team cteam1, Team cteam2):team1(cteam1),team2(cteam2),match{Match(), Match(), Match()}{
}
    //Member Functions    
    void getSeriesStats();
    int getMatchesPlayed();
    void updateMatchesPlayed();
    void displayLeaderboard();
    void displayMatchScorecard(int m);
    void displayTeamStats(int t);
    void displayPlayerStats(int t, int p);
};

int Series::matches_played = 0;

//Public Member Functions
void Series:: getSeriesStats(){
    if(team1.getNoOfWins() > team2.getNoOfWins()){
        cout<<team1.getTeamName()<<" is leading the series by "<<team1.getNoOfWins()<<" - "<<team2.getNoOfWins()<<endl;
    } else if(team1.getNoOfWins() < team2.getNoOfWins()){
        cout<<team2.getTeamName()<<" is leading the series by "<<team2.getNoOfWins()<<" - "<<team1.getNoOfWins()<<endl;
    } else{
        cout<<"Series is levelled up at "<<team1.getNoOfWins()<<" - "<<team2.getNoOfWins()<<endl;
    }
}
int Series:: getMatchesPlayed(){
    return matches_played;
}
void Series:: updateMatchesPlayed(){
    matches_played++;
}
void Series:: displayLeaderboard(){
    int bats1 = team1.getBestBatsman();
    int bats2 = team2.getBestBatsman();
    int bowl1 = team1.getBestBowler();
    int bowl2 = team2.getBestBowler();
    if(team1.batsmen[bats1-1].getTotalRuns(3) > team2.batsmen[bats2-1].getTotalRuns(3)){
        cout<<"Best Batsman of the series : Player "<<bats1<<" (Team 1)"<<" ["<<team1.batsmen[bats1-1].getTotalRuns(3)<<" runs in the series]"<<endl;
    } else{
        cout<<"Best Batsman of the series : Player "<<bats2<<" (Team 2)"<<" ["<<team2.batsmen[bats2-1].getTotalRuns(3)<<" runs in the series]"<<endl;
    }
    cout<<endl;
    if(team1.bowlers[bowl1-1].getTotalWickets(3) > team2.bowlers[bowl2-1].getTotalWickets(3)){
        cout<<"Best Bowler of the series : Player "<<bowl1+3<<" (Team 1)"<<" ["<<team1.bowlers[bowl1-1].getTotalWickets(3)<<" wickets in the series]"<<endl;
    } else{
        cout<<"Best Bowler of the series : Player "<<bowl2+3<<" (Team 2)"<<" ["<<team2.bowlers[bowl2-1].getTotalWickets(3)<<" wickets in the series]"<<endl;
    }
    cout<<endl;
}
void Series:: displayMatchScorecard(int m){
    match[m-1].ScoreCard(m);
}
void Series:: displayTeamStats(int m){
    cout<<team1.getTeamName()<<" Stats"<<endl;
    team1.displayTeamStats(m);
    cout<<team2.getTeamName()<<" Stats"<<endl;
    team2.displayTeamStats(m);
}
void Series:: displayPlayerStats(int t, int p){
    if(t==1 && p>=1 && p<=5) team1.displayPlayerStats(p);
    else if(t==2 && p>=1 && p<=5) team2.displayPlayerStats(p);
    else cout<<"Inappropiate team or player selection"<<endl;
}


#endif