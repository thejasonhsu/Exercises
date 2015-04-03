// Football
// Jason Hsu

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <fstream>  //read file as input
#include <iomanip>  //setw

using namespace std;

struct Team {
    string name;
	double touchDown;
	double fieldGoal;

	int td1;   //for statistic tables
	int td2;
	int td3;

	int fg1;
	int fg2;
	int fg3;
};

void shuffle(Team *teams, int number);

void shuffle(Team *teams, int totalNumberOfTeams) {

    for (int i = 0; i < totalNumberOfTeams; i++) {
        int a = rand()%(totalNumberOfTeams);
        Team temp=teams[a];
        teams[a]=teams[i];   //store in temp array and swap elements to shuffle
        teams[i]=temp;
    }
}


int main() {
	srand(time(NULL));
	cout << "Welcome to the football bracket game!" << endl;
	char filename[100];
	ifstream fin;
	cout << "Enter the input file: ";
	cin >> filename;   //no longer limits the input to be input.txt only
	fin.open(filename);
		if (fin.fail()) {
			cout << "Failed to open file. " << endl;
			return 0;
	    }
		if(fin.is_open()) {
			int totalNumberOfTeams = 8;
			int currentArrayPosition = 0;

			Team teams[14];   //include advancements
            for (int i = 0; i < 14; i++) {
                teams[i].name="";
                teams[i].touchDown = 0.0;
                teams[i].fieldGoal = 0.0;

                teams[i].td1 = 0;   //for statistic tables
                teams[i].td2 = 0;
                teams[i].td3 = 0;

                teams[i].fg1 = 0;
                teams[i].fg2 = 0;
                teams[i].fg3 = 0;
            }


            string source;
            string line;

            while (getline(fin, line)) {
                for (int i = 0; i < line.size(); ++i) {
                    if (line[i] == ',')
                        line.erase(i, 1);
                }

                source += line + "\n";
            }

            istringstream sin(source);   //excludes comma


			//displays error message when input is not in correct format
            for (int i = 0; i < totalNumberOfTeams; ++i) {
                if (!(sin >> teams[i].name) || !(sin >> teams[i].touchDown) || !(sin >> teams[i].fieldGoal)) {
                    cout << "File is not in correct format. " << endl;
                    return 0;
                }
            }

			//shuffle the teams and assign them to brackets
            shuffle(teams, totalNumberOfTeams);



			//first bracket
			cout << "Here are the brackets: " << endl;
			cout << "-------------" << endl;
			cout << "|" << setw(11) << teams[0].name << "|" << endl;
			cout << "|" << setw(11) << "GAME 1" << "|----|" << endl;
			cout << "|" << setw(11) << teams[1].name << "|    |    -------------" << endl;
			cout << "-------------    |    |" << setw(11) << "Game 1 W" << "|" << endl;
			cout << "                 |----|" << setw(11) << "GAME 5" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << "Game 2 W" << "|    |" << endl;
			cout << "|" << setw(11) << teams[2].name << "|    |    -------------    |" << endl;
			cout << "|" << setw(11) << "GAME 2" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[3].name << "|                          |    -------------" << endl;
			cout << "-------------                          |    |" << setw(11) << "Game 5 W" << "|" << endl;
			cout << "                                       |----|" << setw(11) << "GAME 7" << "|" << endl;
			cout << "-------------                          |    |" << setw(11) << "Game 6 W" << "|" << endl;
			cout << "|" << setw(11) << teams[4].name << "|                          |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 3" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[5].name << "|    |    -------------    |" << endl;
			cout << "-------------    |    |" << setw(11) << "Game 3 W" << "|    |" << endl;
			cout << "                 |----|" << setw(11) << "GAME 6" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << "Game 4 W" << "|" << endl;
			cout << "|" << setw(11) << teams[6].name << "|    |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 4" << "|----|" << endl;
			cout << "|" << setw(11) << teams[7].name << "|" << endl;
			cout << "-------------" << endl;

			//display round 1 plays or not
			//checks input repeatedly until valid
			string ans;
			while(true) {
				cout << "Would you like to watch the games in Round 1? ";
				cin >> ans;
				if (ans == "yes" || ans == "Yes" || ans == "no" || ans == "No") {
					break;
				}
				else {
					continue;
				}
			}

			//if answer is yes
			if (ans == "yes" || ans == "Yes") {
				cout << "Game 1 - " << teams[0].name << " vs " << teams[1].name << endl;
				cout << "------" << endl;
				int score0=0;
				int score1=0;
				for (int q=1; q < 5; q++) {
						int n=rand()%100;
						if (n > 0 && n < (100*teams[0].touchDown)) {
							score0 = score0 + 7;   //update score if there's a touchdown
							teams[0].td1++;
						}
						else if (n > (100*teams[0].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[0].fieldGoal)) {
								score0 = score0 + 3;   //update score if there's a field goal
								teams[0].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[0].fieldGoal)) {
								score0 = score0;   //no score
							}
					}
					cout << "QUARTER " << q << endl;
					cout << teams[0].name << " ball " << endl;
					cout << score0 << "-" << score1 << endl;
					//do the same for the other team
						if (n > 0 && n < (100*teams[1].touchDown)) {
							score1 = score1 + 7;   //update score if there's a touchdown
							teams[1].td1++;
						}
						else if (n > (100*teams[1].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[1].fieldGoal)) {
								score1 = score1 + 3;   //update score if there's a field goal
								teams[1].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[1].fieldGoal)) {
								score1 = score1;   //no score
							}
						}
					cout << teams[1].name << " ball " << endl;
					cout << score0 << "-" << score1 << endl;
				}

				while (score0 == score1) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[0].touchDown)) {
						score0 = score0 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[0].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[0].fieldGoal)) {
							score0 = score0 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[0].fieldGoal)) {
							score0 = score0;   //no score
						}
				}
				cout << teams[0].name << " ball " << endl;
				cout << score0 << "-" << score1 << endl;
				//do the same for the other team
					if (n > 0 && n < (100*teams[1].touchDown)) {
						score1 = score1 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[1].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[1].fieldGoal)) {
							score1 = score1 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[1].fieldGoal)) {
							score1 = score1;   //no score
						}
					}
				cout << teams[1].name << " ball " << endl;
				cout << score0 << "-" << score1 << endl;
				}

					//game 1 results
					if (score0 > score1) {
						cout << endl;
						cout << teams[0].name << " beat the " << teams[1].name << " " << score0 << "-" << score1 << " in game 1." << endl;
						cout << endl;
						teams[8]=teams[0];
					}
					if (score1 > score0) {
						cout << endl;
						cout << teams[1].name << " beat the " << teams[0].name << " " << score1 << "-" << score0 << " in game 1." << endl;
						cout << endl;
						teams[8]=teams[1];   //swap for later brackets
					}


				cout << "Game 2 - " << teams[2].name << " vs " << teams[3].name << endl;
				cout << "------" << endl;
				int score2=0;
				int score3=0;
				for (int q=1; q < 5; q++) {
						int n=rand()%100;
						if (n > 0 && n < (100*teams[2].touchDown)) {
							score2 = score2 + 7;   //update score if there's a touchdown
							teams[2].td1++;
						}
						else if (n > (100*teams[2].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[2].fieldGoal)) {
								score2 = score2 + 3;   //update score if there's a field goal
								teams[2].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[2].fieldGoal)) {
								score2 = score2;   //no score
							}
					}
					cout << "QUARTER " << q << endl;
					cout << teams[2].name << " ball " << endl;
					cout << score2 << "-" << score3 << endl;
					//do the same for the other team
						if (n > 0 && n < (100*teams[3].touchDown)) {
							score3 = score3 + 7;   //update score if there's a touchdown
							teams[3].td1++;
						}
						else if (n > (100*teams[3].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[3].fieldGoal)) {
								score3 = score3 + 3;   //update score if there's a field goal
								teams[3].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[3].fieldGoal)) {
								score3 = score3;   //no score
							}
						}
					cout << teams[3].name << " ball " << endl;
					cout << score2 << "-" << score3 << endl;
				}

				while (score2 == score3) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[2].touchDown)) {
						score2 = score2 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[2].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[2].fieldGoal)) {
							score2 = score2 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[2].fieldGoal)) {
							score2 = score2;   //no score
						}
				}
				cout << teams[2].name << " ball " << endl;
				cout << score2 << "-" << score3 << endl;
				//do the same for the other team
					if (n > 0 && n < (100*teams[3].touchDown)) {
						score3 = score3 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[3].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[3].fieldGoal)) {
							score3 = score3 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[3].fieldGoal)) {
							score3 = score3;   //no score
						}
					}
					cout << teams[3].name << " ball " << endl;
					cout << score2 << "-" << score3 << endl;
				}

					//game 2 results
					if (score2 > score3) {
						cout << endl;
						cout << teams[2].name << " beat the " << teams[3].name << " " << score2 << "-" << score3 << " in game 2." << endl;
						cout << endl;
						teams[9]=teams[2];   //swap for later brackets
					}
					if (score3 > score2) {
						cout << endl;
						cout << teams[3].name << " beat the " << teams[2].name << " " << score3 << "-" << score2 << " in game 2." << endl;
						cout << endl;
						teams[9]=teams[3];   //swap for later brackets
					}

					cout << "Game 3 - " << teams[4].name << " vs " << teams[5].name << endl;
					cout << "------" << endl;
					int score4=0;
					int score5=0;
					for (int q=1; q < 5; q++) {
							int n=rand()%100;
							if (n > 0 && n < (100*teams[4].touchDown)) {
								score4 = score4 + 7;   //update score if there's a touchdown
								teams[4].td1++;
							}
							else if (n > (100*teams[2].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[4].fieldGoal)) {
									score4 = score4 + 3;   //update score if there's a field goal
									teams[4].fg1++;
								}
								else if (n2 < 1 && n2 > (100*teams[4].fieldGoal)) {
									score4 = score4;   //no score
								}
						}
						cout << "QUARTER " << q << endl;
						cout << teams[4].name << " ball " << endl;
						cout << score2 << "-" << score3 << endl;
						//do the same for the other team
							if (n > 0 && n < (100*teams[5].touchDown)) {
								score5 = score5 + 7;   //update score if there's a touchdown
								teams[5].td1++;
							}
							else if (n > (100*teams[5].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[5].fieldGoal)) {
									score5 = score5 + 3;   //update score if there's a field goal
									teams[5].fg1++;
								}
								else if (n2 < 1 && n2 > (100*teams[5].fieldGoal)) {
									score5 = score5;   //no score
								}
							}
						cout << teams[5].name << " ball " << endl;
						cout << score4 << "-" << score5 << endl;
					}

					while (score4 == score5) {   //overtime until winner is determined
						cout << "OVERTIME" << endl;
						int n=rand()%100;
						if (n > 0 && n < (100*teams[4].touchDown)) {
							score4 = score4 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[2].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[4].fieldGoal)) {
								score4 = score4 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[4].fieldGoal)) {
								score4 = score4;   //no score
							}
					}
					cout << teams[4].name << " ball " << endl;
					cout << score2 << "-" << score3 << endl;
					//do the same for the other team
						if (n > 0 && n < (100*teams[5].touchDown)) {
							score5 = score5 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[5].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[5].fieldGoal)) {
								score5 = score5 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[5].fieldGoal)) {
								score5 = score5;   //no score
							}
						}
					cout << teams[5].name << " ball " << endl;
					cout << score4 << "-" << score5 << endl;
				}

						//game 3 results
						if (score4 > score5) {
							cout << endl;
							cout << teams[4].name << " beat the " << teams[5].name << " " << score4 << "-" << score5 << " in game 3." << endl;
							cout << endl;
							teams[10]=teams[4];   //swap for later brackets
						}
						if (score5 > score4) {
							cout << endl;
							cout << teams[5].name << " beat the " << teams[4].name << " " << score5 << "-" << score4 << " in game 3." << endl;
							cout << endl;
							teams[10]=teams[5];   //swap for later brackets
						}

						cout << "Game 4 - " << teams[6].name << " vs " << teams[7].name << endl;
						cout << "------" << endl;
						int score6=0;
						int score7=0;
						for (int q=1; q < 5; q++) {
								int n=rand()%100;
								if (n > 0 && n < (100*teams[6].touchDown)) {
									score6 = score6 + 7;   //update score if there's a touchdown
									teams[6].td1++;
								}
								else if (n > (100*teams[6].touchDown)) {
									int n2=rand()%100;
									if (n2 > 0 && n2 < (100*teams[6].fieldGoal)) {
										score6 = score6 + 3;   //update score if there's a field goal
										teams[6].fg1++;
									}
									else if (n2 < 1 && n2 > (100*teams[6].fieldGoal)) {
										score6 = score6;   //no score
									}
							}
							cout << "QUARTER " << q << endl;
							cout << teams[6].name << " ball " << endl;
							cout << score6 << "-" << score7 << endl;
							//do the same for the other team
								if (n > 0 && n < (100*teams[7].touchDown)) {
									score7 = score7 + 7;   //update score if there's a touchdown
									teams[7].td1++;
								}
								else if (n > (100*teams[7].touchDown)) {
									int n2=rand()%100;
									if (n2 > 0 && n2 < (100*teams[7].fieldGoal)) {
										score7 = score7 + 3;   //update score if there's a field goal
										teams[7].fg1++;
									}
									else if (n2 < 1 && n2 > (100*teams[7].fieldGoal)) {
										score7 = score7;   //no score
									}
								}
							cout << teams[7].name << " ball " << endl;
							cout << score6 << "-" << score7 << endl;
						}

						while (score6 == score7) {   //overtime until winner is determined
							cout << "OVERTIME" << endl;
							int n=rand()%100;
							if (n > 0 && n < (100*teams[6].touchDown)) {
								score6 = score6 + 7;   //update score if there's a touchdown
							}
							else if (n > (100*teams[6].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[6].fieldGoal)) {
									score6 = score6 + 3;   //update score if there's a field goal
								}
								else if (n2 < 1 && n2 > (100*teams[6].fieldGoal)) {
									score6 = score6;   //no score
								}
						}
						cout << teams[6].name << " ball " << endl;
						cout << score6 << "-" << score7 << endl;
						//do the same for the other team
							if (n > 0 && n < (100*teams[7].touchDown)) {
								score7 = score7 + 7;   //update score if there's a touchdown
							}
							else if (n > (100*teams[7].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[7].fieldGoal)) {
									score7 = score7 + 3;   //update score if there's a field goal
								}
								else if (n2 < 1 && n2 > (100*teams[7].fieldGoal)) {
									score7 = score7;   //no score
								}
							}
							cout << teams[7].name << " ball " << endl;
							cout << score6 << "-" << score7 << endl;
						}

							//game 4 results
							if (score6 > score7) {
								cout << endl;
								cout << teams[6].name << " beat the " << teams[7].name << " " << score6 << "-" << score7 << " in game 4." << endl;
								cout << endl;
								teams[11]=teams[6];   //swap for later brackets
							}
							if (score7 > score6) {
								cout << endl;
								cout << teams[7].name << " beat the " << teams[6].name << " " << score7 << "-" << score6 << " in game 4." << endl;
								cout << endl;
								teams[11]=teams[7];   //swap for later brackets
							}

			}

			//if answer is no
			else if (ans == "no" || ans == "No") {
				cout << "Game 1 - " << teams[0].name << " vs " << teams[1].name << endl;
				cout << "------" << endl;
				int score0=0;
				int score1=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[0].touchDown)) {
							score0 = score0 + 7;   //update score if there's a touchdown
							teams[0].td1++;
						}
						else if (n > (100*teams[0].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[0].fieldGoal)) {
								score0 = score0 + 3;   //update score if there's a field goal
								teams[0].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[0].fieldGoal)) {
								score0 = score0;   //no score
							}
					}
					//do the same for the other team

						if (n > 0 && n < (100*teams[1].touchDown)) {
							score1 = score1 + 7;   //update score if there's a touchdown
							teams[1].td1++;
						}
						else if (n > (100*teams[1].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[1].fieldGoal)) {
								score1 = score1 + 3;   //update score if there's a field goal
								teams[1].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[1].fieldGoal)) {
								score1 = score1;   //no score
							}
						}
				}
				while (score0 == score1) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[0].touchDown)) {
						score0 = score0 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[0].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[0].fieldGoal)) {
							score0 = score0 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[0].fieldGoal)) {
							score0 = score0;   //no score
						}
				}
				//do the same for the other team
					if (n > 0 && n < (100*teams[1].touchDown)) {
						score1 = score1 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[1].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[1].fieldGoal)) {
							score1 = score1 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[1].fieldGoal)) {
							score1 = score1;   //no score
						}
					}
				}
					//game 1 results
					if (score0 > score1) {
						cout << teams[0].name << " beat the " << teams[1].name << " " << score0 << "-" << score1 << " in game 1." << endl;
						cout << endl;
						teams[8]=teams[0];
					}
					if (score1 > score0) {
						cout << teams[1].name << " beat the " << teams[0].name << " " << score1 << "-" << score0 << " in game 1." << endl;
						cout << endl;
						teams[8]=teams[1];   //swap for later brackets
					}


				cout << "Game 2 - " << teams[2].name << " vs " << teams[3].name << endl;
				cout << "------" << endl;
				int score2=0;
				int score3=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[2].touchDown)) {
							score2 = score2 + 7;   //update score if there's a touchdown
							teams[2].td1++;
						}
						else if (n > (100*teams[2].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[2].fieldGoal)) {
								score2 = score2 + 3;   //update score if there's a field goal
								teams[2].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[2].fieldGoal)) {
								score2 = score2;   //no score
							}
					}
					//do the same for the other team

						if (n > 0 && n < (100*teams[3].touchDown)) {
							score3 = score3 + 7;   //update score if there's a touchdown
							teams[3].td1++;
						}
						else if (n > (100*teams[3].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[3].fieldGoal)) {
								score3 = score3 + 3;   //update score if there's a field goal
								teams[3].fg1++;
							}
							else if (n2 < 1 && n2 > (100*teams[3].fieldGoal)) {
								score3 = score3;   //no score
							}
						}
				}

				while (score2 == score3) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[2].touchDown)) {
						score2 = score2 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[2].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[2].fieldGoal)) {
							score2 = score2 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[2].fieldGoal)) {
							score2 = score2;   //no score
						}
				}
				//do the same for the other team
					if (n > 0 && n < (100*teams[3].touchDown)) {
						score3 = score3 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[3].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[3].fieldGoal)) {
							score3 = score3 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[3].fieldGoal)) {
							score3 = score3;   //no score
						}
					}
				}
					//game 2 results
					if (score2 > score3) {
						cout << teams[2].name << " beat the " << teams[3].name << " " << score2 << "-" << score3 << " in game 2." << endl;
						cout << endl;
						teams[9]=teams[2];   //swap for later brackets
					}
					if (score3 > score2) {
						cout << teams[3].name << " beat the " << teams[2].name << " " << score3 << "-" << score2 << " in game 2." << endl;
						cout << endl;
						teams[9]=teams[3];   //swap for later brackets
					}

					cout << "Game 3 - " << teams[4].name << " vs " << teams[5].name << endl;
					cout << "------" << endl;
					int score4=0;
					int score5=0;
					for (int q=1; q < 5; q++) {

							int n=rand()%100;
							if (n > 0 && n < (100*teams[4].touchDown)) {
								score4 = score4 + 7;   //update score if there's a touchdown
								teams[4].td1++;
							}
							else if (n > (100*teams[2].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[4].fieldGoal)) {
									score4 = score4 + 3;   //update score if there's a field goal
									teams[4].fg1++;
								}
								else if (n2 < 1 && n2 > (100*teams[4].fieldGoal)) {
									score4 = score4;   //no score
								}
						}
						//do the same for the other team

							if (n > 0 && n < (100*teams[5].touchDown)) {
								score5 = score5 + 7;   //update score if there's a touchdown
								teams[5].td1++;
							}
							else if (n > (100*teams[5].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[5].fieldGoal)) {
									score5 = score5 + 3;   //update score if there's a field goal
									teams[5].fg1++;
								}
								else if (n2 < 1 && n2 > (100*teams[5].fieldGoal)) {
									score5 = score5;   //no score
								}
							}
					}

					while (score4 == score5) {   //overtime until winner is determined
						cout << "OVERTIME" << endl;
						int n=rand()%100;
						if (n > 0 && n < (100*teams[4].touchDown)) {
							score4 = score4 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[4].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[4].fieldGoal)) {
								score4 = score4 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[4].fieldGoal)) {
								score4 = score4;   //no score
							}
					}
					//do the same for the other team
						if (n > 0 && n < (100*teams[5].touchDown)) {
							score5 = score5 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[5].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[5].fieldGoal)) {
								score5 = score5 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[5].fieldGoal)) {
								score5 = score5;   //no score
							}
						}
					}

						//game 3 results
						if (score4 > score5) {
							cout << teams[4].name << " beat the " << teams[5].name << " " << score4 << "-" << score5 << " in game 3." << endl;
							cout << endl;
							teams[10]=teams[4];   //swap for later brackets
						}
						if (score5 > score4) {
							cout << teams[5].name << " beat the " << teams[4].name << " " << score5 << "-" << score4 << " in game 3." << endl;
							cout << endl;
							teams[10]=teams[5];   //swap for later brackets
						}

						cout << "Game 4 - " << teams[6].name << " vs " << teams[7].name << endl;
						cout << "------" << endl;
						int score6=0;
						int score7=0;
						for (int q=1; q < 5; q++) {

								int n=rand()%100;
								if (n > 0 && n < (100*teams[6].touchDown)) {
									score6 = score6 + 7;   //update score if there's a touchdown
									teams[6].td1++;
								}
								else if (n > (100*teams[6].touchDown)) {
									int n2=rand()%100;
									if (n2 > 0 && n2 < (100*teams[6].fieldGoal)) {
										score6 = score6 + 3;   //update score if there's a field goal
										teams[6].fg1++;
									}
									else if (n2 < 1 && n2 > (100*teams[6].fieldGoal)) {
										score6 = score6;   //no score
									}
							}
							//do the same for the other team

								if (n > 0 && n < (100*teams[7].touchDown)) {
									score7 = score7 + 7;   //update score if there's a touchdown
									teams[7].td1++;
								}
								else if (n > (100*teams[7].touchDown)) {
									int n2=rand()%100;
									if (n2 > 0 && n2 < (100*teams[7].fieldGoal)) {
										score7 = score7 + 3;   //update score if there's a field goal
										teams[7].fg1++;
									}
									else if (n2 < 1 && n2 > (100*teams[7].fieldGoal)) {
										score7 = score7;   //no score
									}
								}
						}

						while (score6 == score7) {   //overtime until winner is determined
							cout << "OVERTIME" << endl;
							int n=rand()%100;
							if (n > 0 && n < (100*teams[6].touchDown)) {
								score6 = score6 + 7;   //update score if there's a touchdown
							}
							else if (n > (100*teams[6].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[6].fieldGoal)) {
									score6 = score6 + 3;   //update score if there's a field goal
								}
								else if (n2 < 1 && n2 > (100*teams[6].fieldGoal)) {
									score6 = score6;   //no score
								}
						}
						//do the same for the other team
							if (n > 0 && n < (100*teams[7].touchDown)) {
								score7 = score7 + 7;   //update score if there's a touchdown
							}
							else if (n > (100*teams[7].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[7].fieldGoal)) {
									score7 = score7 + 3;   //update score if there's a field goal
								}
								else if (n2 < 1 && n2 > (100*teams[7].fieldGoal)) {
									score7 = score7;   //no score
								}
							}
						}

							//game 4 results
							if (score6 > score7) {
								cout << teams[6].name << " beat the " << teams[7].name << " " << score6 << "-" << score7 << " in game 4." << endl;
								cout << endl;
								teams[11]=teams[6];   //swap for later brackets
							}
							if (score7 > score6) {
								cout << teams[7].name << " beat the " << teams[6].name << " " << score7 << "-" << score6 << " in game 4." << endl;
								cout << endl;
								teams[11]=teams[7];   //swap for later brackets
							}

			}


			//display updated brackets after round 1
			cout << "Here are the brackets: " << endl;
			cout << "-------------" << endl;
			cout << "|" << setw(11) << teams[0].name << "|" << endl;
			cout << "|" << setw(11) << "GAME 1" << "|----|" << endl;
			cout << "|" << setw(11) << teams[1].name << "|    |    -------------" << endl;
			cout << "-------------    |    |" << setw(11) << teams[8].name << "|" << endl;
			cout << "                 |----|" << setw(11) << "GAME 5" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << teams[9].name << "|    |" << endl;
			cout << "|" << setw(11) << teams[2].name << "|    |    -------------    |" << endl;
			cout << "|" << setw(11) << "GAME 2" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[3].name << "|                          |    -------------" << endl;
			cout << "-------------                          |    |" << setw(11) << "Game 5 W" << "|" << endl;
			cout << "                                       |----|" << setw(11) << "GAME 7" << "|" << endl;
			cout << "-------------                          |    |" << setw(11) << "Game 6 W" << "|" << endl;
			cout << "|" << setw(11) << teams[4].name << "|                          |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 3" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[5].name << "|    |    -------------    |" << endl;
			cout << "-------------    |    |" << setw(11) << teams[10].name << "|    |" << endl;
			cout << "                 |----|" << setw(11) << "GAME 6" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << teams[11].name << "|" << endl;
			cout << "|" << setw(11) << teams[6].name << "|    |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 4" << "|----|" << endl;
			cout << "|" << setw(11) << teams[7].name << "|" << endl;
			cout << "-------------" << endl;

			//display round 2 plays or not
			//checks input repeatedly until valid
			string ans1;
			while(true) {
				cout << "Would you like to watch the games in Round 2? ";
				cin >> ans1;
				if (ans1 == "yes" || ans1 == "Yes" || ans1 == "no" || ans1 == "No") {
					break;
				}
				else {
					continue;
				}
			}

			//if answer is yes
			if (ans1 == "yes" || ans1 == "Yes") {
				cout << "Game 5 - " << teams[8].name << " vs " << teams[9].name << endl;
				cout << "------" << endl;
				int score8=0;
				int score9=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[8].touchDown)) {
							score8 = score8 + 7;   //update score if there's a touchdown
							if (teams[8].name==teams[0].name) {   //statistics due to different possible winners
								teams[0].td2++;
							}
							if (teams[8].name==teams[1].name) {
								teams[1].td2++;
							}
						}
						else if (n > (100*teams[8].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[8].fieldGoal)) {
								score8 = score8 + 3;   //update score if there's a field goal
								if (teams[8].name==teams[0].name) {   //statistics due to different possible winners
									teams[0].fg2++;
								}
								if (teams[8].name==teams[1].name) {
									teams[1].fg2++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[8].fieldGoal)) {
								score8 = score8;   //no score
							}
					}
					cout << "QUARTER " << q << endl;
					cout << teams[8].name << " ball " << endl;
					cout << score8 << "-" << score9 << endl;
					//do the same for the other team

						if (n > 0 && n < (100*teams[9].touchDown)) {
							score9 = score9 + 7;   //update score if there's a touchdown
							if (teams[9].name==teams[2].name) {   //statistics due to different possible winners
								teams[2].td2++;
							}
							if (teams[9].name==teams[3].name) {
								teams[3].td2++;
							}
						}
						else if (n > (100*teams[9].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[9].fieldGoal)) {
								score9 = score9 + 3;   //update score if there's a field goal
								if (teams[9].name==teams[2].name) {   //statistics due to different possible winners
									teams[2].fg2++;
								}
								if (teams[9].name==teams[3].name) {
									teams[3].fg2++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[9].fieldGoal)) {
								score9 = score9;   //no score
							}
						}
					cout << teams[9].name << " ball " << endl;
					cout << score8 << "-" << score9 << endl;
				}

				while (score8 == score9) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[8].touchDown)) {
						score8 = score8 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[8].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[8].fieldGoal)) {
							score8 = score8 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[8].fieldGoal)) {
							score8 = score8;   //no score
						}
					}
					cout << teams[8].name << " ball " << endl;
					cout << score8 << "-" << score9 << endl;
				//do the same for the other team
					if (n > 0 && n < (100*teams[9].touchDown)) {
						score9 = score9 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[9].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[9].fieldGoal)) {
							score9 = score9 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[9].fieldGoal)) {
							score9 = score9;   //no score
						}
					}
					cout << teams[9].name << " ball " << endl;
					cout << score8 << "-" << score9 << endl;
				}

					//game 5 results
					if (score8 > score9) {
						cout << endl;
						cout << teams[8].name << " beat the " << teams[9].name << " " << score8 << "-" << score9 << " in game 5." << endl;
						cout << endl;
						teams[12]=teams[8];
					}
					if (score9 > score8) {
						cout << endl;
						cout << teams[9].name << " beat the " << teams[8].name << " " << score9 << "-" << score8 << " in game 5." << endl;
						cout << endl;
						teams[12]=teams[9];   //swap for later brackets
					}

					cout << "Game 6 - " << teams[10].name << " vs " << teams[11].name << endl;
					cout << "------" << endl;
					int score10=0;
					int score11=0;
					for (int q=1; q < 5; q++) {

							int n=rand()%100;
							if (n > 0 && n < (100*teams[10].touchDown)) {
								score10 = score10 + 7;   //update score if there's a touchdown
								if (teams[10].name==teams[4].name) {   //statistics due to different possible winners
									teams[4].td2++;
								}
								if (teams[10].name==teams[5].name) {
									teams[5].td2++;
								}
							}
							else if (n > (100*teams[10].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[10].fieldGoal)) {
									score10 = score10 + 3;   //update score if there's a field goal
									if (teams[10].name==teams[4].name) {   //statistics due to different possible winners
										teams[4].fg2++;
									}
									if (teams[10].name==teams[5].name) {
										teams[5].fg2++;
									}
								}
								else if (n2 < 1 && n2 > (100*teams[10].fieldGoal)) {
									score10 = score10;   //no score
								}
						}
						cout << "QUARTER " << q << endl;
						cout << teams[10].name << " ball " << endl;
						cout << score10 << "-" << score11 << endl;
						//do the same for the other team

							if (n > 0 && n < (100*teams[11].touchDown)) {
								score11 = score11 + 7;   //update score if there's a touchdown
								if (teams[11].name==teams[6].name) {   //statistics due to different possible winners
									teams[6].td2++;
								}
								if (teams[11].name==teams[7].name) {
									teams[7].td2++;
								}
							}
							else if (n > (100*teams[11].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[11].fieldGoal)) {
									score11 = score11 + 3;   //update score if there's a field goal
									if (teams[11].name==teams[6].name) {   //statistics due to different possible winners
										teams[6].fg2++;
									}
									if (teams[11].name==teams[7].name) {
										teams[7].fg2++;
									}
								}
								else if (n2 < 1 && n2 > (100*teams[11].fieldGoal)) {
									score11 = score11;   //no score
								}
							}
						cout << teams[11].name << " ball " << endl;
						cout << score10 << "-" << score11 << endl;
					}

					while (score10 == score11) {   //overtime until winner is determined
						cout << "OVERTIME" << endl;
						int n=rand()%100;
						if (n > 0 && n < (100*teams[10].touchDown)) {
							score10 = score10 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[10].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[10].fieldGoal)) {
								score10 = score10 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[10].fieldGoal)) {
								score10 = score10;   //no score
							}
							cout << teams[10].name << " ball " << endl;
							cout << score10 << "-" << score11 << endl;
						}
						//do the same for the other team
						if (n > 0 && n < (100*teams[11].touchDown)) {
							score11 = score11 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[11].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[11].fieldGoal)) {
								score11 = score11 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[11].fieldGoal)) {
								score11 = score11;   //no score
							}
						}
						cout << teams[11].name << " ball " << endl;
						cout << score10 << "-" << score11 << endl;
					}

						//game 6 results
						if (score10 > score11) {
							cout << endl;
							cout << teams[10].name << " beat the " << teams[11].name << " " << score10 << "-" << score11 << " in game 6." << endl;
							cout << endl;
							teams[13]=teams[10];
						}
						if (score11 > score10) {
							cout << endl;
							cout << teams[11].name << " beat the " << teams[10].name << " " << score11 << "-" << score10 << " in game 6." << endl;
							cout << endl;
							teams[13]=teams[11];   //swap for later brackets
						}
			}

			//if answer is no
			else if (ans1 == "no" || ans1 == "No") {
				cout << "Game 5 - " << teams[8].name << " vs " << teams[9].name << endl;
				cout << "------" << endl;
				int score8=0;
				int score9=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[8].touchDown)) {
							score8 = score8 + 7;   //update score if there's a touchdown
							if (teams[8].name==teams[0].name) {   //statistics due to different possible winners
								teams[0].td2++;
							}
							if (teams[8].name==teams[1].name) {
								teams[1].td2++;
							}
						}
						else if (n > (100*teams[8].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[8].fieldGoal)) {
								score8 = score8 + 3;   //update score if there's a field goal
								if (teams[8].name==teams[0].name) {   //statistics due to different possible winners
									teams[0].fg2++;
								}
								if (teams[8].name==teams[1].name) {
									teams[1].fg2++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[8].fieldGoal)) {
								score8 = score8;   //no score
							}
					}
					//do the same for the other team

						if (n > 0 && n < (100*teams[9].touchDown)) {
							score9 = score9 + 7;   //update score if there's a touchdown
							if (teams[9].name==teams[2].name) {   //statistics due to different possible winners
								teams[2].td2++;
							}
							if (teams[9].name==teams[3].name) {
								teams[3].td2++;
							}
						}
						else if (n > (100*teams[9].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[9].fieldGoal)) {
								score9 = score9 + 3;   //update score if there's a field goal
								if (teams[9].name==teams[2].name) {   //statistics due to different possible winners
									teams[2].fg2++;
								}
								if (teams[9].name==teams[3].name) {
									teams[3].fg2++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[9].fieldGoal)) {
								score9 = score9;   //no score
							}
						}
				}
				while (score8 == score9) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[8].touchDown)) {
						score8 = score8 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[8].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[8].fieldGoal)) {
							score8 = score8 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[8].fieldGoal)) {
							score8 = score8;   //no score
						}
				}
				//do the same for the other team
					if (n > 0 && n < (100*teams[9].touchDown)) {
						score9 = score9 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[9].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[9].fieldGoal)) {
							score9 = score9 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[9].fieldGoal)) {
							score9 = score9;   //no score
						}
					}
				}
					//game 5 results
					if (score8 > score9) {
						cout << teams[8].name << " beat the " << teams[9].name << " " << score8 << "-" << score9 << " in game 5." << endl;
						cout << endl;
						teams[2]=teams[8];
					}
					if (score9 > score8) {
						cout << teams[9].name << " beat the " << teams[8].name << " " << score9 << "-" << score8 << " in game 5." << endl;
						cout << endl;
						teams[12]=teams[9];   //swap for later brackets
					}

					cout << "Game 6 - " << teams[10].name << " vs " << teams[11].name << endl;
					cout << "------" << endl;
					int score10=0;
					int score11=0;
					for (int q=1; q < 5; q++) {

							int n=rand()%100;
							if (n > 0 && n < (100*teams[10].touchDown)) {
								score10 = score10 + 7;   //update score if there's a touchdown
								if (teams[10].name==teams[4].name) {   //statistics due to different possible winners
									teams[4].td2++;
								}
								if (teams[10].name==teams[5].name) {
									teams[5].td2++;
								}
							}
							else if (n > (100*teams[10].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[10].fieldGoal)) {
									score10 = score10 + 3;   //update score if there's a field goal
									if (teams[10].name==teams[4].name) {   //statistics due to different possible winners
										teams[4].fg2++;
									}
									if (teams[10].name==teams[5].name) {
										teams[5].fg2++;
									}
								}
								else if (n2 < 1 && n2 > (100*teams[10].fieldGoal)) {
									score10 = score10;   //no score
								}
						}
						//do the same for the other team

							if (n > 0 && n < (100*teams[11].touchDown)) {
								score11 = score11 + 7;   //update score if there's a touchdown
								if (teams[11].name==teams[6].name) {   //statistics due to different possible winners
									teams[6].td2++;
								}
								if (teams[10].name==teams[7].name) {
									teams[7].td2++;
								}
							}
							else if (n > (100*teams[11].touchDown)) {
								int n2=rand()%100;
								if (n2 > 0 && n2 < (100*teams[11].fieldGoal)) {
									score11 = score11 + 3;   //update score if there's a field goal
									if (teams[11].name==teams[6].name) {   //statistics due to different possible winners
										teams[6].fg2++;
									}
									if (teams[10].name==teams[7].name) {
										teams[7].fg2++;
									}
								}
								else if (n2 < 1 && n2 > (100*teams[11].fieldGoal)) {
									score11 = score11;   //no score
								}
							}
					}

					while (score10 == score11) {   //overtime until winner is determined
						cout << "OVERTIME" << endl;
						int n=rand()%100;
						if (n > 0 && n < (100*teams[10].touchDown)) {
							score10 = score10 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[10].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[10].fieldGoal)) {
								score10 = score10 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[10].fieldGoal)) {
								score10 = score10;   //no score
							}
					}
					//do the same for the other team
						if (n > 0 && n < (100*teams[11].touchDown)) {
							score11 = score11 + 7;   //update score if there's a touchdown
						}
						else if (n > (100*teams[11].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[11].fieldGoal)) {
								score11 = score11 + 3;   //update score if there's a field goal
							}
							else if (n2 < 1 && n2 > (100*teams[11].fieldGoal)) {
								score11 = score11;   //no score
							}
						}
					}
						//game 6 results
						if (score10 > score11) {
							cout << teams[10].name << " beat the " << teams[11].name << " " << score10 << "-" << score11 << " in game 6." << endl;
							cout << endl;
							teams[13]=teams[10];
						}
						if (score11 > score10) {
							cout << teams[11].name << " beat the " << teams[10].name << " " << score11 << "-" << score10 << " in game 6." << endl;
							cout << endl;
							teams[13]=teams[11];   //swap for later brackets
						}
			}

			//display updated brackets after round 2
			cout << "Here are the brackets: " << endl;
			cout << "-------------" << endl;
			cout << "|" << setw(11) << teams[0].name << "|" << endl;
			cout << "|" << setw(11) << "GAME 1" << "|----|" << endl;
			cout << "|" << setw(11) << teams[1].name << "|    |    -------------" << endl;
			cout << "-------------    |    |" << setw(11) << teams[8].name << "|" << endl;
			cout << "                 |----|" << setw(11) << "GAME 5" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << teams[9].name << "|    |" << endl;
			cout << "|" << setw(11) << teams[2].name << "|    |    -------------    |" << endl;
			cout << "|" << setw(11) << "GAME 2" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[3].name << "|                          |    -------------" << endl;
			cout << "-------------                          |    |" << setw(11) << teams[12].name << "|" << endl;
			cout << "                                       |----|" << setw(11) << "GAME 7" << "|" << endl;
			cout << "-------------                          |    |" << setw(11) << teams[13].name << "|" << endl;
			cout << "|" << setw(11) << teams[4].name << "|                          |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 3" << "|----|" << setw(22) << "|" << endl;
			cout << "|" << setw(11) << teams[5].name << "|    |    -------------    |" << endl;
			cout << "-------------    |    |" << setw(11) << teams[10].name << "|    |" << endl;
			cout << "                 |----|" << setw(11) << "GAME 6" << "|----|" << endl;
			cout << "-------------    |    |" << setw(11) << teams[11].name << "|" << endl;
			cout << "|" << setw(11) << teams[6].name << "|    |    -------------" << endl;
			cout << "|" << setw(11) << "GAME 4" << "|----|" << endl;
			cout << "|" << setw(11) << teams[7].name << "|" << endl;
			cout << "-------------" << endl;

			//display round 3 plays or not
			//checks input repeatedly until valid
			string ans2;
			while(true) {
				cout << "Would you like to watch the games in Round 3? ";
				cin >> ans2;
				if (ans2 == "yes" || ans2 == "Yes" || ans2 == "no" || ans2 == "No") {
					break;
				}
				else {
					continue;
				}
			}

			//if answer is yes
			if (ans2 == "yes" || ans2 == "Yes") {
				cout << "Game 7 - " << teams[12].name << " vs " << teams[13].name << endl;
				cout << "------" << endl;
				int score12=0;
				int score13=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[12].touchDown)) {
							score12 = score12 + 7;   //update score if there's a touchdown
							if (teams[12].name==teams[0].name) {   //statistics due to different possible winners
								teams[0].td3++;
							}
							if (teams[12].name==teams[1].name) {
								teams[1].td3++;
							}
							if (teams[12].name==teams[2].name) {
								teams[2].td3++;
							}
							if (teams[12].name==teams[3].name) {
								teams[3].td3++;
							}
						}
						else if (n > (100*teams[12].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[12].fieldGoal)) {
								score12 = score12 + 3;   //update score if there's a field goal
								if (teams[12].name==teams[0].name) {   //statistics due to different possible winners
									teams[0].fg3++;
								}
								if (teams[12].name==teams[1].name) {
									teams[1].fg3++;
								}
								if (teams[12].name==teams[2].name) {
									teams[2].fg3++;
								}
								if (teams[12].name==teams[3].name) {
									teams[3].fg3++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[12].fieldGoal)) {
								score12 = score12;   //no score
							}
					}
					cout << "QUARTER " << q << endl;
					cout << teams[12].name << " ball " << endl;
					cout << score12 << "-" << score13 << endl;
					//do the same for the other team

						if (n > 0 && n < (100*teams[13].touchDown)) {
							score13 = score13 + 7;   //update score if there's a touchdown
							if (teams[13].name==teams[4].name) {   //statistics due to different possible winners
								teams[4].td3++;
							}
							if (teams[13].name==teams[5].name) {
								teams[5].td3++;
							}
							if (teams[13].name==teams[6].name) {
								teams[6].td3++;
							}
							if (teams[13].name==teams[7].name) {
								teams[7].td3++;
							}
						}
						else if (n > (100*teams[13].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[13].fieldGoal)) {
								score13 = score13 + 3;   //update score if there's a field goal
								if (teams[13].name==teams[4].name) {   //statistics due to different possible winners
									teams[4].fg3++;
								}
								if (teams[13].name==teams[5].name) {
									teams[5].fg3++;
								}
								if (teams[13].name==teams[6].name) {
									teams[6].fg3++;
								}
								if (teams[13].name==teams[7].name) {
									teams[7].fg3++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[13].fieldGoal)) {
								score13 = score13;   //no score
							}
						}
					cout << teams[13].name << " ball " << endl;
					cout << score12 << "-" << score13 << endl;
				}

				while (score12 == score13) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[12].touchDown)) {
						score12 = score12 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[12].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[12].fieldGoal)) {
							score12 = score12 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[12].fieldGoal)) {
							score12 = score12;   //no score
						}
					}
					cout << teams[12].name << " ball " << endl;
					cout << score12 << "-" << score13 << endl;
					//do the same for the other team
					if (n > 0 && n < (100*teams[13].touchDown)) {
						score13 = score13 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[13].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[13].fieldGoal)) {
							score13 = score13 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[13].fieldGoal)) {
							score13 = score13;   //no score
						}
					}
					cout << teams[13].name << " ball " << endl;
					cout << score12 << "-" << score13 << endl;
				}

					//game 7 results and ultimate winner
					if (score12 > score13) {
						cout << endl;
						cout << teams[12].name << " beat the " << teams[13].name << " " << score12 << "-" << score13 << " in game 7." << endl;
						cout << endl;
						cout << teams[12].name << " win the conference!" << endl;
					}
					if (score13 > score12) {
						cout << endl;
						cout << teams[13].name << " beat the " << teams[12].name << " " << score13 << "-" << score12 << " in game 7." << endl;
						cout << endl;
						cout << teams[13].name << " win the conference!" << endl;
					}
			}

			//if answer is no
			else if (ans2 == "no" || ans2 == "No") {
				cout << "Game 7 - " << teams[12].name << " vs " << teams[13].name << endl;
				cout << "------" << endl;
				int score12=0;
				int score13=0;
				for (int q=1; q < 5; q++) {

						int n=rand()%100;
						if (n > 0 && n < (100*teams[12].touchDown)) {
							score12 = score12 + 7;   //update score if there's a touchdown
							if (teams[12].name==teams[0].name) {   //statistics due to different possible winners
								teams[0].td3++;
							}
							if (teams[12].name==teams[1].name) {
								teams[1].td3++;
							}
							if (teams[12].name==teams[2].name) {
								teams[2].td3++;
							}
							if (teams[12].name==teams[3].name) {
								teams[3].td3++;
							}
						}
						else if (n > (100*teams[12].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[12].fieldGoal)) {
								score12 = score12 + 3;   //update score if there's a field goal
								if (teams[12].name==teams[0].name) {   //statistics due to different possible winners
									teams[0].fg3++;
								}
								if (teams[12].name==teams[1].name) {
									teams[1].fg3++;
								}
								if (teams[12].name==teams[2].name) {
									teams[2].fg3++;
								}
								if (teams[12].name==teams[3].name) {
									teams[3].fg3++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[12].fieldGoal)) {
								score12 = score12;   //no score
							}
					}
					//do the same for the other team

						if (n > 0 && n < (100*teams[13].touchDown)) {
							score13 = score13 + 7;   //update score if there's a touchdown
							if (teams[13].name==teams[4].name) {   //statistics due to different possible winners
								teams[4].td3++;
							}
							if (teams[13].name==teams[5].name) {
								teams[5].td3++;
							}
							if (teams[13].name==teams[6].name) {
								teams[6].td3++;
							}
							if (teams[13].name==teams[7].name) {
								teams[7].td3++;
							}
						}
						else if (n > (100*teams[13].touchDown)) {
							int n2=rand()%100;
							if (n2 > 0 && n2 < (100*teams[13].fieldGoal)) {
								score13 = score13 + 3;   //update score if there's a field goal
								if (teams[13].name==teams[4].name) {   //statistics due to different possible winners
									teams[4].fg3++;
								}
								if (teams[13].name==teams[5].name) {
									teams[5].fg3++;
								}
								if (teams[13].name==teams[6].name) {
									teams[6].fg3++;
								}
								if (teams[13].name==teams[7].name) {
									teams[7].fg3++;
								}
							}
							else if (n2 < 1 && n2 > (100*teams[13].fieldGoal)) {
								score13 = score13;   //no score
							}
						}
				}

				while (score12 == score13) {   //overtime until winner is determined
					cout << "OVERTIME" << endl;
					int n=rand()%100;
					if (n > 0 && n < (100*teams[12].touchDown)) {
						score12 = score12 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[12].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[12].fieldGoal)) {
							score12 = score12 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[12].fieldGoal)) {
							score12 = score12;   //no score
						}
				}
				//do the same for the other team
					if (n > 0 && n < (100*teams[13].touchDown)) {
						score13 = score13 + 7;   //update score if there's a touchdown
					}
					else if (n > (100*teams[13].touchDown)) {
						int n2=rand()%100;
						if (n2 > 0 && n2 < (100*teams[13].fieldGoal)) {
							score13 = score13 + 3;   //update score if there's a field goal
						}
						else if (n2 < 1 && n2 > (100*teams[13].fieldGoal)) {
							score13 = score13;   //no score
						}
					}
				}
					//game 7 results and ultimate winner
					if (score12 > score13) {
						cout << teams[12].name << " beat the " << teams[13].name << " " << score12 << "-" << score13 << " in game 7." << endl;
						cout << endl;
						cout << teams[12].name << " win the conference!" << endl;
					}
					if (score13 > score12) {
						cout << teams[13].name << " beat the " << teams[12].name << " " << score13 << "-" << score12 << " in game 7." << endl;
						cout << endl;
						cout << teams[13].name << " win the conference!" << endl;
					}
			}


			//touchdown table
			cout << endl;
			cout << "TOUCHDOWN TABLE" << endl;
			cout << setw(21) << "ROUND #" << endl;
			cout << "Team      1     2     3   Total   %   Prob  Diff" << endl;
			cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
			for (int i=0; i < 8; ++i) {
			cout << teams[i].name << setw(4)
                 << teams[i].td1 << "/4   " 
                 << teams[i].td2 << "/4   " 
                 << teams[i].td3 << "/4   " 
                 << teams[i].td1+teams[i].td2+teams[i].td3 << "/12  ";
            printf("%.2f",(teams[i].td1+teams[i].td2+teams[i].td3)/12.0);
            cout << "   " << teams[i].touchDown << "   ";
            printf("%.2f",(teams[i].touchDown-(teams[i].td1+teams[i].td2+teams[i].td3)/12.0));
            cout << endl;
			}


			//field goal table
			cout << endl;
			cout << "FIELD GOAL TABLE" << endl;
			cout << setw(21) << "ROUND #" << endl;
			cout << "Team      1     2     3   Total   %   Prob  Diff" << endl;
			cout << "----    ----- ----- ----- ----- ----- ----- -----" << endl;
			for (int i=0; i < 8; ++i) {
			cout << teams[i].name << setw(4)
                 << teams[i].fg1 << "/4   " 
                 << teams[i].fg2 << "/4   " 
                 << teams[i].fg3 << "/4   " 
                 << teams[i].fg1+teams[i].fg2+teams[i].fg3 << "/12  ";
            printf("%.2f",(teams[i].fg1+teams[i].fg2+teams[i].fg3)/12.0);
            cout << "   " << teams[i].touchDown << "   ";
            printf("%.2f",(teams[i].touchDown-(teams[i].fg1+teams[i].fg2+teams[i].fg3)/12.0));
            cout << endl;
			}



		}
}

