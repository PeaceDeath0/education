#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

int teamA[6];
int teamB[6];

int partScoreA = 0;
int partScoreB = 0;

int scoreA = 0;
int scoreB = 0; 

int lastGoal = 0;

std::ofstream logg;


void logs(std::string message)
{
    logg.open("log.txt", std::ofstream::app);
    logg << message << std::endl;
    logg.close();
}

void reverse(int arra1[6]) 
{
    int buffer1 = arra1[5];
    arra1[5] = arra1[4];
    arra1[4] = arra1[3];
    arra1[3] = arra1[2];
    arra1[2] = arra1[1];
    arra1[1] = arra1[0];
    arra1[0] = buffer1;

}

void graphic(int arra1[6], int arra2[6]) 
{
    std::cout << "\n\nScore A: " << scoreA << "(" << partScoreA << ")" << "  Score A: " << scoreB << "(" << partScoreB << ")\n\n";
    std::cout << "      " << arra1[2] << "  " << arra1[3] << "  |  " << arra2[5] << "  " << arra2[0] << "(P)\n";
    std::cout << "      " << arra1[1] << "  " << arra1[4] << "  |  " << arra2[4] << "  " << arra2[1] << "\n";
    std::cout << "   (P)" << arra1[0] << "  " << arra1[5] << "  |  " << arra2[3] << "  " << arra2[2] << "\n\n";
}

void startGame(int arra1[6], int arra2[6]) 
{
    logs("Game was started!"); 

    std::cout << "Enter command A" << "\n";

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Player " << i + 1 << ": ";
        std::cin >> arra1[i];
    }

    std::cout << "Enter command B" << "\n";

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Player " << i + 1 << ": ";
        std::cin >> arra2[i];
    }
}

void action(int* lastGoal, int* partScoreA, int* partScoreB)
{
    std::string teamAction;
    int playerAction;
    std::string whatAction;

    logg.open("log.txt", std::ofstream::app);

    std::cout << "which team performed the action?(a or b)\n";
    std::cin >> teamAction;

    if (teamAction != "a" && teamAction != "b")
    {
        std::cout << "You choose wrong team, please retry\n";
        return;
    }

    std::cout << "\nwhat action was performed?\n";
    std::cout << "a - Attack; b - Block, p - Supply, o - Error (P.S. Please, don't write anything except a, b, p, or o) \n";
    std::cin >> whatAction;

    if (whatAction != "a" && whatAction != "b" && whatAction != "p" && whatAction != "o")
    {
        std::cout << "You choose wrong action, please retry\n";
        return;
    }

    if (whatAction != "o")
    {
        std::cout << "which player performed the action?(player's position number)\n";
        std::cin >> playerAction;

        if (playerAction <= 0 or playerAction >= 7)
        {
            std::cout << "You choose wrong player place number, please retry\n";
            return;
        }

        if (teamAction == "a")
        {
            logg << "Player from team A got a point!" << std::endl;
        }
        if (teamAction == "b")
        {
            logg << "Player from team B got a point!" << std::endl;
        }


        if (teamAction == "a")
        {
            if (*lastGoal == 2) { reverse(teamA);  logg << "Team A reverse!" << std::endl; }

            *lastGoal = 1;
            *partScoreA += 1;
        }

        if (teamAction == "b")
        {
            if (*lastGoal == 1) { reverse(teamB);  logg << "Team B reverse!" << std::endl; }

            *lastGoal = 2;
            *partScoreB += 1;
        }

    }

    logg.close();
}

void scorePlus(int* partScoreA, int* partScoreB, int* scoreA, int* scoreB)
{
    if (*partScoreA == 25) { *partScoreA = 0; *scoreA += 1; }
    if (*partScoreB == 25) { *partScoreB = 0; *scoreB += 1; }
}

void playerReplace(int arra1[6], int arra2[6]) 
{
    std::string team;
    int playerPlace;
    int playerNum;

    std::cout << "which team?\n";
    std::cin >> team;

    if (team != "a" && team != "b")
    {
        std::cout << "You choose wrong team, please retry\n";
        return;
    }

    std::cout << "which player?(player's position number)\n";
    std::cin >> playerPlace;

    if (playerPlace <= 0 or playerPlace >= 7)
    {
        std::cout << "You choose wrong player place number, please retry\n";
        return;
    }

    std::cout << "which player to replace?(player number\n";
    std::cin >> playerNum;

    if (team == "a") arra1[playerPlace - 1] = playerNum;
    if (team == "b") arra2[playerPlace - 1] = playerNum;

}

int main()
{
    startGame(teamA, teamB);

    logg.open("log.txt", std::ofstream::app);

    while (true)
    {
        graphic(teamA, teamB);
        int choose;
        std::cout << "what do you want to do?\n";
        std::cout << "1 - Replace Player, 2 - Action\n";

        std::cin >> choose;

        if (choose == 1 or choose == 2) {
            switch (choose)
            {
            case(1):
                playerReplace(teamA, teamB);
                break;
            case(2):
                action(&lastGoal, &partScoreA, &partScoreB);
                break;

            }
        } 
        else {
            break;
        }

        scorePlus(&partScoreA, &partScoreB, &scoreA, &scoreB);

        if (scoreA == 3) { std::cout << "Team A win!\n"; logg << "Team A win!" << std::endl; logg.close();  break; }
        if (scoreB == 3) { std::cout << "Team B win!\n"; logg << "Team B win!" << std::endl; logg.close();  break; }
    }
}
