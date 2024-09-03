#include <bits/stdc++.h>
using namespace std;
#ifndef BATSMAN_H
#define BATSMAN_H

class Batsman
{
private:
    // Data Members
    int runs_scored[3];
    float strike_rate[3];
    float batting_avg;
    int balls_faced[3];

    // Member Functions
    void setStrikeRate(int m);
    void setBattingAvg(int m);
    void setHighestScore(int m);

protected:
    // Data Member
    int highest_score;

public:
    // Constructors
    Batsman();
    // Data Members
    void setRuns(int m, int runs);
    int getRuns(int m);
    int getTotalRuns(int m);
    int getBallsFaced(int m);
    float getStrikeRate(int m);
    float getBattingAvg();
    int getHighestScore();
    void updateBallsFaced(int m);
    void displayMatchWiseStats(int m);
    void displayBatsmanStats();
};
// Public Member Functions
Batsman::Batsman()
{
    for (int i = 0; i < 3; i++)
    {
        runs_scored[i] = 0;
        strike_rate[i] = 0;
        balls_faced[i] = 0;
    }
    batting_avg = 0.0;
    highest_score = 0;
}
void Batsman::setRuns(int m, int runs)
{
    runs_scored[m - 1] += runs;
    balls_faced[m - 1] += 1;
    setStrikeRate(m);
    setBattingAvg(m);
    setHighestScore(m);
}
void Batsman::updateBallsFaced(int m)
{
    balls_faced[m - 1]++;
}
int Batsman::getRuns(int m)
{
    return runs_scored[m];
}
int Batsman::getTotalRuns(int m)
{
    int total = 0;
    for (int i = 0; i < m; i++)
    {
        total += getRuns(i);
    }
    return total;
}
int Batsman::getBallsFaced(int m)
{
    return balls_faced[m - 1];
}
float Batsman::getStrikeRate(int m)
{
    return strike_rate[m - 1];
}
float Batsman::getBattingAvg()
{
    return batting_avg;
}
int Batsman::getHighestScore()
{
    return highest_score;
}
void Batsman::displayMatchWiseStats(int m)
{
    cout << "Runs Scored in Match " << m << " : " << getRuns(m - 1) << endl;
    cout << "Balls faced in Match " << m << " : " << balls_faced[m - 1] << endl;
    cout << "Strike Rate in Match " << m << " : " << getStrikeRate(m) << endl;
    cout << "Batting Average till Match " << m << " : " << getBattingAvg() << endl;
}
void Batsman::displayBatsmanStats()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Match " << i + 1 << setw(15) << runs_scored[i] << "(" << balls_faced[i] << ")"
             << "\n\n";
    }
    cout << "Batting Average throughout the series : " << batting_avg << endl;
}

// Private Member Functions
void Batsman::setStrikeRate(int m)
{
    strike_rate[m - 1] = ((float)runs_scored[m - 1] / balls_faced[m - 1]) * 100;
}
void Batsman::setBattingAvg(int m)
{
    int runs = 0;
    for (int i = 0; i < m; i++)
    {
        runs += runs_scored[i];
    }
    batting_avg = (float)runs / m;
}
void Batsman::setHighestScore(int m)
{
    highest_score = (highest_score < runs_scored[m - 1]) ? runs_scored[m - 1] : highest_score;
}

#endif