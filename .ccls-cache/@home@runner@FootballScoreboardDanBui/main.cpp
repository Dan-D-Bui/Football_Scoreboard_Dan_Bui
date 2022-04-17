/*
Dan Bui
COSC 1437
4/15/22
Dr. Tyson McMillan
*/

#include <iostream>
#include "functions.h"
#include "Input_Validation_Extended.h"
using namespace std; 
        
int main() 
{
  Scoreboard s;
  string userString = ""; 
  int userInt = 0;
  char userChoice;
  bool validInput = false;

  //Set the home and visitor team 
  s.tOne.setHomeStatus(true);
  s.tTwo.setHomeStatus(false);

  //Loop this to make it an interactive menu

  do
  {
    system("clear");    //Clear screen
    s.showScoreboard();    //Show scoreboard
    showMenu();    //Main menu options
    userChoice = validateChar(userChoice);
    userChoice = toupper(userChoice);

    switch(userChoice)
    {
      case 'A':
        cout << "Enter who is the home team (1 = Team 1 or 2 = Team 2): ";
        do
        {
          userInt = validateInt(userInt);
          if (userInt == 1)
          {
            s.tOne.setHomeStatus(true);
            s.tTwo.setHomeStatus(false);
          }
          else if (userInt == 2)
          {
            s.tOne.setHomeStatus(false);
            s.tTwo.setHomeStatus(true);
          }
          else
            cout << "Please enter a valid choice: ";
        } while (userInt != 1 && userInt != 2);
        validInput = true;
        break;
      
      case 'B':
        cout << "Enter number of minutes remaining: ";
        userInt = validateInt(userInt);
        s.setMin(userInt);
        break;
      
      case 'C':
        cout << "Enter number of seconds remaining: ";
        userInt = validateInt(userInt);
        s.setSec(userInt);
        break;

      case 'D':
        cout << "Enter current quarter: ";
        userInt = validateInt(userInt);
        s.setQuarter(userInt);
        break;

      case 'E':
        cout << "Enter who has possession of ball (1 = home or 2 = visitor): ";
        do
        {
          userInt = validateInt(userInt);
          if (userInt == 1)
            s.setPossession(true);
          else if (userInt == 2)
            s.setPossession(false);
          else
            cout << "Please enter a valid choice: ";
        } while (userInt != 1 && userInt != 2);
        break;
      
      case 'F':
        cout << "Enter current down: ";
        userInt = validateInt(userInt);
        s.setDown(userInt);
        break;

      case 'G':
        cout << "Enter yards until first down: ";
        userInt = validateInt(userInt);
        s.setYards(userInt);
        break;

      case 'H':
        validInput = false;    //Inner loop check until user chooses a correct option
        system("clear"); 
        s.showScoreboard();
        showTeamMenu();    //Submenu for team info

        do
        {
          userChoice = validateChar(userChoice);
          userChoice = toupper(userChoice);
          
          switch(userChoice)
          {
            case 'A':
              cout << "Enter the team's score: ";
              userInt = validateInt(userInt);
              if (s.tOne.getHomeStatus() == true)
                s.tOne.setScore(userInt);
              else
                s.tTwo.setScore(userInt);
              validInput = true;
              break;
  
            case 'B':
              cout << "Enter the team's name: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == true)
                s.tOne.setName(userString);
              else
                s.tTwo.setName(userString);
              validInput = true;
              break;

            case 'C':
              cout << "Enter the team's couch name: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == true)
                s.tOne.setCoachName(userString);
              else
                s.tTwo.setCoachName(userString);
              validInput = true;
              break;
  
            case 'D':
              cout << "Enter the team's home city: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == true)
                s.tOne.setCity(userString);
              else
                s.tTwo.setCity(userString);
              validInput = true;
              break;
  
            case 'E':
              cout << "Enter the team's timeout count: ";
              userInt = validateInt(userInt);
              if (s.tOne.getHomeStatus() == true)
                s.tOne.setTimeout(userInt);
              else
                s.tTwo.setTimeout(userInt);
              validInput = true;
              break;
            
            case 'X':
              validInput = true;
              break;
  
            default:
              cout << "Please enter a valid choice: ";
              break;
          }
        } while (validInput != true);
        userChoice = '\0';
        break;
      
      case 'I':
        validInput = false;
        system("clear"); 
        s.showScoreboard();
        showTeamMenu();

        do
        {
          userChoice = validateChar(userChoice);
          userChoice = toupper(userChoice);
          
          switch(userChoice)
          {
            case 'A':
              cout << "Enter the team's score: ";
              userInt = validateInt(userInt);
              if (s.tOne.getHomeStatus() == false)
                s.tOne.setScore(userInt);
              else
                s.tTwo.setScore(userInt);
              validInput = true;
              break;
  
            case 'B':
              cout << "Enter the team's name: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == false)
                s.tOne.setName(userString);
              else
                s.tTwo.setName(userString);
              validInput = true;
              break;

            case 'C':
              cout << "Enter the team's couch name: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == false)
                s.tOne.setCoachName(userString);
              else
                s.tTwo.setCoachName(userString);
              validInput = true;
              break;
  
            case 'D':
              cout << "Enter the team's home city: ";
              userString = validateString(userString);
              if (s.tOne.getHomeStatus() == false)
                s.tOne.setCity(userString);
              else
                s.tTwo.setCity(userString);
              validInput = true;
              break;
  
            case 'E':
              cout << "Enter the team's timeout count: ";
              userInt = validateInt(userInt);
              if (s.tOne.getHomeStatus() == false)
                s.tOne.setTimeout(userInt);
              else
                s.tTwo.setTimeout(userInt);
              validInput = true;
              break;
  
            case 'X':
              validInput = true;
              break;
  
            default:
              cout << "Please enter a valid choice: ";
              break;
          }
        } while (validInput != true);
        userChoice = '\0';
        break;

      case 'X':
        cout << "\nExiting...";
        break;

      default:
        cout << "Please enter a valid choice..." << endl;
        break;
    }
  } while (userChoice != 'X');

  return 0; 
}