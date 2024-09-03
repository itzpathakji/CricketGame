#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include "team.h"
#ifndef MATCH_H
#define MATCH_H

using namespace std;
class Match
{
    int target;
    int currentscore[2];
    int wickets[2];
    int inningsnum;
    int matchnum;
    int Toss();
    void Bat(int, Team &, Team &);
    void Bowl(int, Team &, Team &);
    void setTarget(int);
    void setCurrentScore(int i, int score);
    void setWickets(int i, int wick);
    int getTarget();
    int getCurrentScore();
    int getWickets();

protected:
    int match;

public:
    Match()
    {
        target = -1;
        matchnum = 0;
        inningsnum = 1;
    }
    void ScoreCard(int);
    void Playmatch(Team &, Team &);
};
void Match::setTarget(int t)
{
    target = t;
}
void Match::setCurrentScore(int i, int s)
{
    currentscore[i] = s;
}
void Match::setWickets(int i, int w)
{
    wickets[i] = w;
}
int Match::getTarget()
{
    return target;
}
int Match::Toss()
{

    return rand() % 2;
}
void Match::Playmatch(Team &t1, Team &t2)
{
    srand(time(NULL));
    matchnum = t1.getNoOfWins() + t2.getNoOfWins() + 1;
    cout << "Match " << matchnum << " out of 3 in the Series\n";
    cout << "Match about to begin .....\n";
    int teambat, teambowl;
    teambat = Toss();
    teambowl = !teambat;
    if(teambat + 1 == 1) cout<<t1.getTeamName()<<"(Team 1) has won the Toss and decided to bat first!\n";
    else cout<<t2.getTeamName()<<"(Team 2) has won the Toss and decided to bat first!\n";
    
    cout << "Which team would you like to play as!? ";
    int choice;
    int b=1;
    while(b)
    {cin >> choice;
    if(choice>2||choice<1)
    cout<<"Please choose correct team!\n";
    else
    b=0;}
    cout << "You are playing as team " << choice << " !\n";
    cout << "Starting in 3... ";
    _sleep(1000);
    cout << "2... ";
    _sleep(1000);
    cout << "1... ";
    _sleep(1000);
    cout << endl;
    if (choice == teambat + 1)
    {
        if (teambat)
        {
            Bat(teambat, t2, t1);
            Bowl(teambat, t2, t1);
        }
        else
        {
            Bat(teambat, t1, t2);
            Bowl(teambat, t1, t2);
        }
    }
    else
    {
        if (!teambowl)
        {
            Bowl(teambowl, t1, t2);
            Bat(teambowl, t1, t2);
        }
        else
        {
            Bowl(teambowl, t2, t1);
            Bat(teambowl, t2, t1);
        }
    }
}
void Match::Bat(int t, Team &t1, Team &t2)
{
    system("cls");
    int bat, ball, overs = 0, numballs = 0;
    setCurrentScore(inningsnum - 1, 0);
    setWickets(inningsnum - 1, 0);
    cout << "Innings " << inningsnum << endl;
    cout << "Batting : Team " <<t+1<< "("<<t1.getTeamName()<<")" << endl;
    cout << "Bowling : Team " <<!t+1<< "("<<t2.getTeamName()<<")" << endl;
    while (overs < 4)
    {
        cout << "enter a number between 1 and 6: ";
        cin >> bat;
        if (bat < 1 || bat > 6)
        {
            cout << "Invalid entry. Try again....\n\n";
            continue;
        }
        ball = rand() % 6 + 1;
        numballs++;
        cout << "The CPU picked : " << ball << endl;
        if (ball == bat)
        {
            wickets[inningsnum - 1]++;
            t2.updateBowlStats(matchnum, 0, 1, 1 + overs % 2, 1 + overs % 2);
            t1.updateBatStats(matchnum, 0, wickets[inningsnum - 1]);
            cout << "Oh No! You've lost a wicket....!!\n";
            if (wickets[inningsnum - 1] == 3)
            {
                cout << currentscore[inningsnum - 1] << " - " << wickets[inningsnum - 1] << " \n\n";
                break;
            }
            cout << "On strike: Player " << wickets[inningsnum - 1] + 1 << endl;
        }
        else
        {
            switch (bat)
            {
            case 1:
                cout << "A quick single\n";
                currentscore[inningsnum - 1] += 1;
                break;
            case 2:
                cout << "Two runs\n";
                currentscore[inningsnum - 1] += 2;
                break;
            case 3:
                cout << "Pacy 3 runs\n";
                currentscore[inningsnum - 1] += 3;
                break;
            case 4:
                cout << "Cruising out for a four!\n";
                currentscore[inningsnum - 1] += 4;
                break;
            case 5:
                cout << "Five runs!\n";
                currentscore[inningsnum - 1] += 5;
                break;
            case 6:
                cout << "Smashed out for 6 runs!!\n";
                currentscore[inningsnum - 1] += 6;
                break;
            }
            t1.updateBatStats(matchnum, bat, wickets[inningsnum - 1] + 1);
            t2.updateBowlStats(matchnum, bat, 0, 1 + overs % 2, 1 + overs % 2);
        }
        // BOX print
        cout << currentscore[inningsnum - 1] << " - " << wickets[inningsnum - 1] << " \n\n";
        if (target != -1)
        {
            if (currentscore[inningsnum - 1] >= target)
                break;
            cout << " Team " << t + 1 << " needs " << target - currentscore[inningsnum - 1] << " runs in " << 24 - numballs << " balls.\n";
        }
        if (numballs % 6 == 0)
        {
            cout << "End of over " << overs + 1 << "\n\n";
            overs++;
            cout << "On strike: Player " << wickets[inningsnum - 1] + 1 << endl;
            cout << "With the Ball: Player " << 4 + overs % 2 << "\n\n";
        }
    }
    if (wickets[inningsnum - 1] == 3)
        cout << "All OUT!!\n\n";
    cout << "\nEnd of Innings " << inningsnum << "\n";
    if (target > -1)
    {
        if (currentscore[inningsnum - 1] >= target)
        {
            cout << "Hurray! Team " << t + 1 << " has completed the chase and won the match by " << 3 - wickets[inningsnum - 1] << " wickets\n";
            t1.updateNoOfWins(t1.getNoOfWins() + 1);
        }
        else
        {
            cout << "Alas! You could not achieve the target :( \nTeam " << t + 1 << " has lost the match!\n";
            cout << "Team " << !t + 1 << " won by " << target - currentscore[inningsnum - 1] << " runs.\n";
            t2.updateNoOfWins(t2.getNoOfWins() + 1);
        }
    }
    else
    {
        cout << "Team " << t + 1 << " has scored " << currentscore[inningsnum - 1] << " runs.\n";
        setTarget(currentscore[inningsnum - 1] + 1);
        inningsnum++;
        cout << "Target for Team " << !t + 1 << " : " << getTarget() << " runs.\n";
        cout << "You need to defend " << getTarget() << " runs in 4 overs.\n";
    }
    cout << "\nEnter any number to continue......";
    cin >> t;
}
void Match::Bowl(int t, Team &t1, Team &t2)
{
    system("cls");
    int bat, ball, overs = 0, numballs = 0;
    setCurrentScore(inningsnum - 1, 0);
    setWickets(inningsnum - 1, 0);
    cout << "Innings " << inningsnum << endl;
    cout << "Batting : Team " <<!t+1<< "("<<t2.getTeamName()<<")" << endl;
    cout << "Bowling : Team " <<t+1<< "("<<t1.getTeamName()<<")" << endl;
    while (overs < 4)
    {
        cout << "Enter a number between 1 and 6: ";
        cin >> ball;
        if (ball < 1 || ball > 6)
        {
            cout << "Invalid entry. Try again\n\n";
            continue;
        }
        bat = rand() % 6 + 1;
        numballs++;
        cout << "The cpu picked : " << bat << endl;
        if (ball == bat)
        {
            wickets[inningsnum - 1]++;
            t1.updateBowlStats(matchnum, 0, 1, 1 + overs % 2, 1 + overs % 2);
            t2.updateBatStats(matchnum, 0, wickets[inningsnum - 1]);
            cout << "Beautiful delivery! The CPU lost a wicket....!!\n";
            if (wickets[inningsnum - 1] == 3)
            {
                cout << currentscore[inningsnum - 1] << " - " << wickets[inningsnum - 1] << " \n\n";
                break;
            }
        }
        else
        {
            currentscore[inningsnum - 1] += bat;
            t2.updateBatStats(matchnum, bat, wickets[inningsnum - 1] + 1);
            t1.updateBowlStats(matchnum, bat, 0, 1 + overs % 2, 1 + overs % 2);
        }
        // BOX print
        cout << currentscore[inningsnum - 1] << " - " << wickets[inningsnum - 1] << " \n";
        if (target != -1)
        {
            if (currentscore[inningsnum - 1] >= target)
                break;
            cout << " Team " << !t + 1 << " needs " << target - currentscore[inningsnum - 1] << " runs in " << 24 - numballs << " balls.\n";
        }
        if (numballs % 6 == 0)
        {
            cout << "End of over " << overs + 1 << endl;
            overs++;
            cout << "On strike: Player " << wickets[inningsnum - 1] + 1 << endl;
            cout << "With the Ball: Player " << 4 + overs % 2 << endl;
        }
    }
    if (wickets[inningsnum - 1] == 3)
        cout << "All OUT!!\n";
    cout << "\nEnd of Innings " << inningsnum << "\n";
    if (target > -1)
    {
        if (currentscore[inningsnum - 1] >= target)
        {
            cout << "Tough Luck! Team " << !t + 1 << " has completed the chase and won the match by " << 3 - wickets[inningsnum - 1] << " wickets!\n";
            t2.updateNoOfWins(t2.getNoOfWins() + 1);
        }
        else
        {
            cout << "Good work done! Team " << t + 1 << " has successfully defended " << target << " runs!\n";
            cout << "Team " << t + 1 << " won by " << target - currentscore[inningsnum - 1] << " runs.\n";
            t1.updateNoOfWins(t1.getNoOfWins() + 1);
        }
    }
    else
    {
        cout << "Team " << !t + 1 << " has amassed a score of " << currentscore[inningsnum - 1] << " runs.\n";
        setTarget(currentscore[inningsnum - 1] + 1);
        inningsnum++;
        cout << "Target for Team " << !t + 1 << " : " << getTarget() << " runs.\n";
        cout << "You need to score " << getTarget() << " run in 4 overs.\n";
    }
    cout << "\nEnter any number to continue......";
    cin >> t;
}
void Match::ScoreCard(int m)
{
    cout << "Match Number: - " << m << endl;
    cout << "Innings number 1\n";
    cout << "- - - - - - - - - -\n\n";
    cout << "      " << currentscore[0] << " - " << wickets[0] << "\n";
    cout << "\n- - - - - - - - - -\n\n";

    cout << "Innings number 2\n";
    cout << "- - - - - - - - - -\n\n";
    cout << "      " << currentscore[1] << " - " << wickets[1] << "\n";
    cout << "\n- - - - - - - - - -\n\n";

}
#endif