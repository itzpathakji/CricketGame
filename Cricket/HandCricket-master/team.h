#include <bits/stdc++.h>
using namespace std;
#include "batsman.h"
#include "bowler.h"
#ifndef TEAM_H
#define TEAM_H

class Team
{
private:
    // Data Members
    string name;
    int no_of_Wins;
    int bestBatsman;
    int bestBowler;
    
    // Member Functions
    void setBestBatsman(int m);
    void setBestBowler(int m);

public:
    //Reference to objects of class Batsman and Bowler(Aggregation)
    Batsman *batsmen;
    Bowler *bowlers;
    // Constructors
    Team();
    Team(string name, Batsman *batsmen, Bowler *bowlers);
    

    // Member Functions
    int getNoOfWins();
    string getTeamName();
    int getBestBatsman();
    int getBestBowler();
    void displayTeam();
    void updateNoOfWins(int w);
    void updateBatStats(int m, int runs, int p);
    void updateBowlStats(int m, int runs, int w, int p, float overs);
    void displayMatchStats(int m);
    void displayTeamStats(int m);
    void displayPlayerStats(int p);
};

// Public Member Functions
Team::Team() {}
Team::Team(string name, Batsman *batsmen, Bowler *bowlers)
{
    this->name = name;
    this->no_of_Wins = 0;
    this->bestBatsman = -1;
    this->bestBowler = -1;
    this->batsmen = batsmen;
    this->bowlers = bowlers;
}
int Team::getNoOfWins()
{
    return no_of_Wins;
}
string Team::getTeamName()
{
    return name;
}
int Team::getBestBatsman()
{
    return bestBatsman;
}
int Team::getBestBowler()
{
    return bestBowler;
}
void Team::displayTeam()
{
    cout << "Playing team" << name<<endl;
    cout << "_____________" << endl;
    cout << "Player 1(Batsman)" << endl;
    cout << "Player 2(Batsman)" << endl;
    cout << "Player 3(Batsman)" << endl;
    cout << "Player 4(Bowler)" << endl;
    cout << "Player 5(Bowler)" << endl << endl;
}
void Team::updateNoOfWins(int w)
{
    no_of_Wins = w;
}
void Team::updateBatStats(int m, int runs, int p)
{
    batsmen[p - 1].setRuns(m, runs);
    batsmen[p - 1].updateBallsFaced(m);
    setBestBatsman(m);
}
void Team::updateBowlStats(int m, int runs, int w, int p, float overs)
{
    bowlers[p - 1].setRunsConceeded(m, runs);
    bowlers[p - 1].setWickets(m, w);
    bowlers[p - 1].setEconomy(m, overs);
    setBestBowler(m);
}

void Team::displayMatchStats(int m)
{
    cout << name << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Batsman " << i + 1 << setw(15) << batsmen[i].getRuns(m-1) << "(" << batsmen[i].getBallsFaced(m) << ")" << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < 2; i++)
    {
        cout << "Bowler " << i + 1 << setw(15) << bowlers[i].getRunsConceeded(m) << "-" << bowlers[i].getWickets(m) << endl;
    }
    cout << "\n\n";
}

void Team::displayTeamStats(int m)
{
    cout << "Highest Run Scorer : Player " << bestBatsman << " (" << batsmen[bestBatsman - 1].getTotalRuns(m) << " runs)" << endl;
    cout << "Highest Wicket taker : Player " << bestBowler + 3 << " (" << bowlers[bestBowler - 1].getTotalWickets(m) << " wickets)" << endl;
}

void Team::displayPlayerStats(int p)
{
    cout << "Player " << p << " : " << endl;
    if (p == 1 || p == 2 || p == 3)
    {
        cout << "Role: Batsman" << endl;
        batsmen[p - 1].displayBatsmanStats();
    }
    else if (p == 4 || p == 5)
    {
        cout << "Role: Bowler" << endl;
        bowlers[p - 4].displayBowlerStats();
        bowlers[p - 4].displayBestFigures();
    }
    else
        cout << "Sorry, Player does not exist!" << endl;
}

// Private Member Functions
void Team::setBestBatsman(int m)
{
    int totalByBatsman1 = batsmen[0].getTotalRuns(m);
    int totalByBatsman2 = batsmen[1].getTotalRuns(m);
    int totalByBatsman3 = batsmen[2].getTotalRuns(m);

    if (totalByBatsman1 > totalByBatsman2 && totalByBatsman1 > totalByBatsman3)
        bestBatsman = 1;
    else if (totalByBatsman2 > totalByBatsman1 && totalByBatsman2 > totalByBatsman3)
        bestBatsman = 2;
    else if (totalByBatsman3 > totalByBatsman1 && totalByBatsman3 > totalByBatsman2)
        bestBatsman = 3;
}
void Team::setBestBowler(int m)
{
    int wicketsByBowler1 = bowlers[0].getTotalWickets(m);
    int wicketsByBowler2 = bowlers[1].getTotalWickets(m);

    if (wicketsByBowler1 >= wicketsByBowler2)
        bestBowler = 1;
    else if (wicketsByBowler1 < wicketsByBowler2)
        bestBowler = 2;
}

#endif