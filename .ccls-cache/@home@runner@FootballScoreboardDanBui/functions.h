#include <iostream>
#include <string> 
#include <iomanip>
using namespace std; 

class Team 
{
  private:
    string name;
    string coachName;
    string city;
    bool homeStatus; 
    int score;
    int timeout; 
     
  public:
    Team() //Default constructor
    {
      name = "DefaultName";
      coachName = "DefaultCoach";
      city = "DefaultCity";
      homeStatus = false;
      score = 0;
      timeout = 3;
    }
    void setName(string sN) { name = sN; }
    void setCoachName(string sCN) { coachName = sCN; }
    void setCity (string sC) { city = sC; }
    void setHomeStatus(bool hS) { homeStatus = hS; }
    void setScore(int sS) { score = sS; }
    void setTimeout(int sT) { timeout = sT; }
    string getName() const { return name; }
    string getCoachName() const { return coachName; }
    string getCity() const { return city; }
    bool getHomeStatus() const { return homeStatus; }
    int getScore() const { return score; }
    int getTimeout() const { return timeout; }
};

class Scoreboard
{
  private:
    int min;
    int sec;
    int quarter;
    bool possession;
    int down;
    int yards; 

  public:
    Team tOne;
    Team tTwo;
    Scoreboard()
    {
      min = 15;
      sec = 0;
      quarter = 1;
      possession = true;
      down = 1;
      yards = 10;
    }
    void setMin(int sM) { min = sM; }
    void setSec(int sS) { sec = sS; }
    void setQuarter(int sQ) { quarter = sQ; }
    void setPossession(bool sP) { possession = sP; }
    void setDown(int sD) { down = sD; }
    void setYards(int sY) { yards = sY; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    int getQuarter() const { return quarter; }
    bool getPossession() const { return possession; }
    int getDown() const { return down; }
    int getYards() const { return yards; }
    void showScoreboard()    //A whole bunch of annoying formatting
    {
      string color = "\x1b[33;1m";
      string bold = "\x1b[1m";
      string reset = "\x1b[0m";

      cout << bold << "------------------------------\n";
      cout << left << setw(12) << "| HOME" << reset
           << color << right << setfill('0') << setw(2) << getMin() << reset
           << bold << ":" << reset
           << color << setw(2) << getSec() << setfill(' ') << reset
           << bold << setw(14) << "VISITOR |\n";
      if (tOne.getHomeStatus() == true)
      {
        cout << "| " << left << setw(13) << tOne.getCity()
             << right << setw(13) << tTwo.getCity() << " |\n";
        cout << "| " << left << setw(13) << tOne.getName()
             << right << setw(13) << tTwo.getName() << " |\n";
        cout << "| " << reset << color << left << setw(6) << tOne.getScore() << reset;
        if (getPossession() == true)
          cout << color << "<>" << reset
               << bold << right << setw(6) << "QTR " << reset
               << color << left << setw(4) << getQuarter()
               << right << setw(8) << tTwo.getScore();
        else
          cout << bold << right << setw(8) << "QTR " << reset
               << color << left << setw(4) << getQuarter()
               << "<>"
               << right << setw(6) << tTwo.getScore();
        cout << reset << bold << " |\n" << reset;
      }
      else
      {
        cout << "| " << left << setw(13) << tTwo.getCity()
             << right << setw(13) << tOne.getCity() << " |\n";
        cout << "| " << left << setw(13) << tTwo.getName()
             << right << setw(13) << tOne.getName() << " |\n";
        cout << "| " << color << left << setw(6) << tTwo.getScore() << reset;
        if (getPossession() == true)
          cout << color << "<>" << reset
               << bold << right << setw(6) << "QTR " << reset
               << color << left << setw(4) << getQuarter()
               << right << setw(8) << tOne.getScore();
        else
          cout << bold << right << setw(8) << "QTR " << reset
               << color << left << setw(4) << getQuarter()
               << "<>"
               << right << setw(6) << tOne.getScore();
        cout << reset << bold << " |\n";
      }
      cout << "|" << reset
           << color << setw(4) << getDown() << reset 
           << bold << " DOWN"
           << setw(14) << "TO GO " << reset
           << color << left << setw(5) << getYards() << reset
           << bold << "|" << reset;
      cout << bold << "\n------------------------------" << reset << endl;
    }
};

void showMenu()
{
  cout << "\nA. Update Home and Visitor Team\n";
  cout << "B. Update Minutes\n";
  cout << "C. Update Seconds\n";
  cout << "D. Update Quarter\n";
  cout << "E. Update Possession\n";
  cout << "F. Update Down\n";
  cout << "G. Update Yards\n";
  cout << "H. Update Home Team Info\n"; 
  cout << "I. Update Visitor Team Info\n"; 
  cout << "X. Exit" << endl;
}

void showTeamMenu()
{
  cout << "\nA. Update Score\n";
  cout << "B. Update Team Name\n";
  cout << "C. Update Couch Name\n";
  cout << "D. Update Team Home City\n";
  cout << "E. Update Timeouts\n";
  cout << "X. Return" << endl;
}