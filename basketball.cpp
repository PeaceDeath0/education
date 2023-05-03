#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int team1[4] = {1, 5, 10, 8};
int team2[4] = {12, 8, 9, 1};

vector<pair<int, int>> score = {{0, 0}};

int* current_team = team1;

void print_team() {
    cout << "Team: ";
    for (int i = 0; i < 4; i++) {
        cout << current_team[i] << " ";
    }
    cout << endl;
}

void change_team(bool is_team1_win) {
    if (is_team1_win) {
        current_team = team1;
    } else {
        current_team = team2;
    }
    print_team();
}

void change_score(char action, int player) {
    bool is_player_valid = false;
    for (int i = 0; i < 4; i++) {
        if (current_team[i] == player) {
            is_player_valid = true;
            break;
        }
    }
    if (!is_player_valid) {
        return;
    }

    if (action == 'A') { 
        score.back().first++;
    } else if (action == 'B') { 
        score.back().second++;
    } else if (action == 'P') { 
       
    } else if (action == 'O') { 
        score.back().second++;
    }

    if (score.back().first >= 25 && score.back().first - score.back().second >= 2) {
        score.push_back(make_pair(0, 0));
    }

    cout << "Score: " << score.size() << " (" << score.back().first << ") - " 
    << score.size() - 1 << " (" << score.back().second << ")" << endl;
}

void replace_player(int leaving_player, int entering_player) {

    int leaving_player_index = -1;
    for (int i = 0; i < 4; i++) {
        if (current_team[i] == leaving_player) {
            leaving_player_index = i;
            break;
        }
    }
    if (leaving_player_index == -1) {
        return;
    }

    current_team[leaving_player_index] = entering_player;
    print_team();
}

int main() {
    cout << "Starting match" << endl;
    cout << "Team 1: "; print_team();
    cout << "Team 2: "; print_team();
    cout << "Score: 1 (0) - 0 (0)" << endl;

    ofstream log_file;
    log_file.open("logs.txt");

    while (true) {
        char action;
        int player;
        cout << "Enter action and player number (ex. \"A 10\"): ";
        cin >> action >> player;

        log_file << action << " " << player << endl;


        if (action == 'A' || action == 'B' || action == 'P' || action == 'O') {
            change_score(action, player);
        } else if (action == 'R') { 
            int entering_player;
            cout << "Enter entering player number: ";
            cin >> entering_player;
            replace_player(player, entering_player);
            log_file << "R " << player << " " << entering_player << endl;
        }

        if (score.size() > 3 || (score.size() == 3 && (score.back().first >= 15 || score.back().second >= 15))) {
            cout << "Match is over!" << endl;
            cout << "Final score: " << score.size() - 1 << " - " << score.back().second << endl;
            ofstream db_file("db.txt", i
os_base::app);
            db_file << score.size() - 1 << " - " << score.back().second << endl;
            break;
        } else { 
            bool is_team1_win;
            cout << "Enter winning team (A/B): ";
            cin >> is_team1_win;
            change_team(is_team1_win);
        }
    }

    log_file.close();

    return 0;
}
