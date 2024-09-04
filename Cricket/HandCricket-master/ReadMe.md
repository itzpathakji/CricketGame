# OOPL Project :

## Assumptions
1. There are only two teams in the series.
2. The series is of 3 matches.
3. There are 5 players in each team.
4. There are 3 batsman and 2 bowlers in each team.
5. The team which wins the toss will bat first.
6. You can decide which team you want to play for.
7. Each inning will have 4 overs and a team will be all out after 3 wickets.


## HOW TO PLAY
1. First you have to choose the team you want to play for.
2. If you are batting, you have to choose a number between 1-6.
3. If the number you choose is same as the number the bowler chooses, you will be out.
4. If the number you choose is different from the number the bowler chooses, the runs will be added to your score.
5. If you are bowling, you have to choose a number between 1-6.
6. If the number you choose is same as the number the batsman chooses, the batsman will be out.
7. If the number you choose is different from the number the batsman chooses, the runs will be added to the batsman's score.
8. The team which scores more runs wins the match.
9. The team which wins more matches wins the series.
10. You can also view the stats of the series, team, match and players.



## Classes defined :

1. Match
2. Team
3. Series
4. Bowler
5. Batsman
6. Match Terminal

### 1. Match class :

**Class variables :**

***Private***
- **_target_**: It is an int variable which holds the target for the match.
- **_currentscore_**: It is an int variable which holds the current score of the team at a particular match.
- **_wickets_**: It is an int containing the total number of wickets lost for the team which is batting.

***Protected***


**Class functions :**

***Private***
- **_Toss()_**: It is a private function for tossing . It returns either 1 or 0.
- **_Bat()_**: It is a private function which contains the logic for batting. 
- **_Bowl()_**: It is a private function which contains the logic for bowling.
- **_setTarget()_**: 
- **_setCurrentScore()_**: 
- **_setWickets()_**: 
- **_getTarget()_**: 
- **_getCurrentScore()_**: 
- **_getWickets()_**: 

***Protected***
- **_ScoreCard()_**: 
- **_Playmatch()_**: 

### 2. Batsman :

**Class variables :**

***Private***
- **_runs_scored_**: Variable that stores the runs scored by batsman in each match.
- **_strike_rate_**: Variable that stores the strike rate of the batsman in each match.
- **_batting_avg_**: Variable that stores the batting avg of the bastman. 
- **_balls_faced_**: Total balls faced in by the batsman in each match.

**Class functions :**

***Private***
- **_setStrikeRate()_**: It displays the intro banner for the program.
- **_setBattingAvg()_**: This function sets the username of the player in the userObj object.
- **_setHighestScore()_**: This function displays the application menu and allows the user to select the mode, view user data or quit.

***Public***
- **_Batsman()_**: A constructor to initialise all the values to 0.
- **_setRuns()_**: Function to store the runs scored by batsman + the number of balls the batsman has played in each match
- **_getRuns()_**: Returns the runs scored by batsman in a match.
- **_getTotalRuns()_**: Returns the total runs scored by the batsman in all three matches.
- **_getStrikeRate()_**: Returns strike rate of the batsman in a match.
- **_getBattingAvg()_**: Returns the batting average of the batsman.
- **_HighestScore()_**: Returns the highest score of the batsman of all the three matches.
- **_displayMatchStats()_** : It displays runs scored , balls faced, strike rate , batting avg in a match.

### 3. Bowler :

**Class variables :**

***Private***
- **_runs_scored_**: Variable that stores the runs scored by batsman in each match.
- **_strike_rate_**: Variable that stores the strike rate of the batsman in each match.
- **_batting_avg_**: Variable that stores the batting avg of the bastman. 
- **_balls_faced_**:

**Class functions :**

***Private***
- **_wickets()_**: It stores the number of wickets taken by the bowler in each match.
- **_runs_conceeded()_**: Returns the total number of runs conceeded by the bowler in a match.
- **_economy()_**: Returns the number of runs bowler has conceeded per over.

***Public***
- **_Bowler()_**: A constructor to initialise all the values of the variables to 0.
- **_setWickets()_**: Function to store the wickets taken by the bowler in a match.
- **_getWickets()_**: Function to get the wickets taken by the bowler in a match.
- **_getTotalWickets()_**: Returns the total wickets taken by the bowler in all the three matches.
- **_setRunsConceeded()_**: Function to store the total runs conceeded by the bowler in a match.
- **_getRunsConceeded()_**:Returns the total runs conceeded by the bowler in a match.
- **_setEconomy()_**: Function to store the value of economy of a match.
- **_getEconomy()_** : Returns the value of economy of a match.
- **_displayBestFigures()_** : It displays the figure where min runs were made in ma balls.

### 4. Series :

**Class variables :**

***Private***
- **_matches_played_**: Static variable that stores the number of matches played .
- **_team1_**: An object for the team to store first team.
- **_team2_**: An object for the team second team.
- **_match_**: An object for Match that stores matches that is to be played in the series.

**Class functions :**

***Public***
- **_Series()_**:
- **_getSeriesStats()_**: Function to display the stats of the series for both the teams. (LOGIC)
- **_displayLeaderboard()_**: 
- **_displayMatchScorecard()_**: Returns the scorecard of the Match.
- **_displayTeamStats()_**:  Function to display the stats of the series for both the teams. (getSeriesStats() function call)
- **_displayPlayerStats()_**:

### 5. Team :

**Class variables :**

***Private***
- **_name_**: Stores the name of the team
- **_no_of_Wins_**: Store the number of wins of the team.
- **_bestBatsman_**: Stores the best batsman of the team.
- **_bestBowler_**: Stores the best bowler of the team.
- **_batsmen_**: A pointer variable of batsman type which points to the current batsman.
- **_bowlers_**: A pointer variable of bowler type which points to the current bowler.

**Class functions :**
***Private***
- **_setBestBatsman_**: A function to store the best batsman according to the runs scored by them.
- **_setBestBowler_**: A function to store the best bowler of the team.

***Public***
- **_Team()_**: 
- **_Team(name , batsman , bowler)_**: A paramterised constructor to initialize the values of the variables.
- **_getNoOfWins()_**: Returns the number of wins.
- **_getTeamName()_**: Returns the name of the team.
- **_getBestBatsman()_**: Returns the best batsman.
- **_getBestBowler()_**:  Returns the best bowler.
- **_displayTeam()_**: Displays all the members of the team.
- **_updateBatStats()_**: Function to update the runs of the batsman and update the best batsman according to it.
- **_updateBowlStats()_**: Function to update the runs conceeded, wickets,economy of the bowler and update the best bowler according to it.
- **_displayMatchStats()_**:Displays the match stats of a particular match of the tea 
- **_displayTeamStats()_**: Displays highest Run Scorer , highest wicket Taker .


                                                                      

## Conclusions:

> The above HandCricket game is easy and user friendly to play .
