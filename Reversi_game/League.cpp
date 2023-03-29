#include "League.h"


League::League(string nameFp_League) {
    this->nameFp_League = nameFp_League;
}
League::League() {}

void League::randTwoIndexses(int mumOfPlayer, int *index1, int *index2) {

    srand(time(nullptr));
    *index1 = (rand() % mumOfPlayer);

    while(true){
        *index2 = (rand() % mumOfPlayer);
        if (*index2 != *index1) break;
    }
}

void League::leagMnue(PlayerList &list, Player *player) {
    string option;
    string stat;
    nameLeagueAllFp = "big_League.txt";
    nameLeague_MammalFp = "Mammal_League.txt";
    nameLeague_FishFp = "Fish_League.txt";
    nameLeague_BugFp = "Bug_League.txt";
    nameLeague_DogFp = "Dog_League.txt";
    nameLeague_CatFp = "Cat_League.txt";
    nameLeague_DolphinFp = "Dolphin_League.txt";
    nameLeague_GrasshopperFp = "Grasshopper_League.txt";
    nameLeague_SharkFp = "Shark_League.txt";
    nameLeague_WaspFp = "Wasp_League.txt";
    nameLeague_BarracudaFp = "Barracuda_League.txt";
    nameLeague_AntFp = "Ant_League.txt";
    cout << "1. enter for existing league " << endl << "2. create for new league" << endl;
    do {
        cin >> option;
        if (option == "1") {
            cout << "1. big league" << endl << "2. Mammal only" << endl << "3. Fish only" << endl << "4. Bug only"
                 << endl << "5. A limited leagues" << endl;
            cin >> stat;
            if (stat == "1") {
                if (CheckIfLeagueExists(nameLeagueAllFp)) {
                    if (!playeralreadyexsist(player, nameLeagueAllFp)) {
                        insertPlayerToLeague(player, nameLeagueAllFp);
                    }
                }
            }
            if (stat == "2") {
                if (CheckIfLeagueExists(nameLeague_MammalFp)) {
                    if (!playeralreadyexsist(player, nameLeague_MammalFp)) {
                        insertPlayerToLeague(player, nameLeague_MammalFp);
                    }
                }
            }
            if (stat == "3") {
                if (CheckIfLeagueExists(nameLeague_FishFp)) {
                    if (!playeralreadyexsist(player, nameLeague_FishFp)) {
                        insertPlayerToLeague(player, nameLeague_FishFp);
                    }
                }
            }
            if (stat == "4") {
                if (CheckIfLeagueExists(nameLeague_BugFp)) {
                    if (!playeralreadyexsist(player, nameLeague_BugFp)) {
                        insertPlayerToLeague(player, nameLeague_BugFp);
                    }
                }
            }

            if (stat == "5") {
                cout << "1. Dog only" << endl << "2. Cat only" << endl << "3. Dolphin only" << endl << "4. Ant only"
                     << endl << "5. A Wasp only" << endl << "6. Shark only" << "7. barracuda only" << endl;
                cin >> stat;
                if (stat == "1") {
                    if (CheckIfLeagueExists(nameLeague_DogFp)) {
                        if (!playeralreadyexsist(player, nameLeague_DogFp)) {
                            insertPlayerToLeague(player, nameLeague_DogFp);
                        }
                    }
                }
                if (stat == "2") {
                    if (CheckIfLeagueExists(nameLeague_CatFp)) {
                        if (!playeralreadyexsist(player, nameLeague_CatFp)) {
                            insertPlayerToLeague(player, nameLeague_CatFp);
                        }
                    }
                }
                if (stat == "3") {
                    if (CheckIfLeagueExists(nameLeague_DolphinFp)) {
                        if (!playeralreadyexsist(player, nameLeague_DolphinFp)) {
                            insertPlayerToLeague(player, nameLeague_DolphinFp);
                        }
                    }
                }
                if (stat == "4") {
                    if (CheckIfLeagueExists(nameLeague_AntFp)) {
                        if (!playeralreadyexsist(player, nameLeague_AntFp)) {
                            insertPlayerToLeague(player, nameLeague_AntFp);
                        }
                    }
                }
                if (stat == "5") {
                    if (CheckIfLeagueExists(nameLeague_WaspFp)) {
                        if (!playeralreadyexsist(player, nameLeague_WaspFp)) {
                            insertPlayerToLeague(player, nameLeague_WaspFp);
                        }
                    }
                }
                if (stat == "6") {
                    if (CheckIfLeagueExists(nameLeague_SharkFp)) {
                        if (!playeralreadyexsist(player, nameLeague_SharkFp)) {
                            insertPlayerToLeague(player, nameLeague_SharkFp);
                        }
                    }
                }
                if (stat == "7") {
                    if (CheckIfLeagueExists(nameLeague_BarracudaFp)) {
                        if (!playeralreadyexsist(player, nameLeague_BarracudaFp)) {
                            insertPlayerToLeague(player, nameLeague_BarracudaFp);
                        }
                    }
                }
            }
        }
        if (option == "2") {
            cout << "1. big league" << endl << "2. Mammal only" << endl << "3. Fish only" << endl << "4. Bug only"
                 << endl << "5. A limited leagues" << endl;
            cin >> option;
            if (option == "1") {
                League(nameLeagueAllFp);
            }
            if (option == "2") {
                League( nameLeague_MammalFp );
            }
            if (option == "3") {
                League(nameLeague_FishFp);
            }
            if (option == "4") {
                League(nameLeague_BugFp);
            }
            if (option == "5") {
                cout << "1. Dog only" << endl << "2. Cat only" << endl << "3. Dolphin only" << endl << "4. Ant only"
                     << endl << "5. A Wasp only" << endl << "6. Shark only" << "7. barracuda only" << endl;
                cin >> stat;
                if (option == "1") {
                    League(nameLeague_DogFp);
                }
                if (option == "2") {
                    League(nameLeague_CatFp);
                }
                if (option == "3") {
                    League(nameLeague_DolphinFp);
                }
                if (option == "4") {
                    League(nameLeague_AntFp);
                }
                if (option == "4") {
                    League(nameLeague_WaspFpFp);
                }
                if (option == "5") {
                    League(nameLeague_BugFp);
                }
                if (option == "6") {
                    League(nameLeague_SharkFp);
                }
                if (option == "7") {
                    League(nameLeague_BarracudaFpFp);
                }
            }
        }

        if (option != "1" && option != "2") cout << "invalid input try again" << endl;

    } while (option != "1" && option != "2");

}

bool League::CheckIfLeagueExists(string name_LeaguFP) {
    std::ifstream Fp(name_LeaguFP);
    if (Fp.peek() == std::ifstream::traits_type::eof()) {
        return false;
    }
    return true;
}

bool League::insertPlayerToLeague(Player *player, string nameLeague_Fp){
    fstream Fp;
    Fp.open(nameLeague_Fp, ios::app);
    if (Fp.is_open()){
        Fp <<"UserName: "<<player->getUserName()<<" password: "<<player->getPasword()<<" name: " <<player->getUserName()<<" points: "<<player->getPonts()<<endl<<endl;
        Fp.close();
    }
    leagueList.insertPlayer(player->getName(), player->getPasword(), player->getUserName(), leagueList);
}

bool League::playeralreadyexsist(Player *player, string nameLeague_Fp) {
    fstream FP;
    string temp;
    FP.open(nameLeague_Fp, ios::in);
    if (FP.is_open()) {
        while (getline(FP, temp)) {
            if (temp.find(player->getUserName()) != std::string::npos) {
                FP.close();
                return true;
            }
        }
    }
    FP.close();
    return false;
}

