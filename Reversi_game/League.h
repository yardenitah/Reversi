#ifndef REVERSI_GAME_LEAGUE_H
#define REVERSI_GAME_LEAGUE_H
#include <ctime>
#include "PlayerList.h"

class League {
public:
    League();
    League(string nameFp_League);
    void randTwoIndexses(int mumOfPlayer, int *index1, int *index2) ;
    void leagMnue(PlayerList &list, Player *player);
    bool CheckIfLeagueExists(string name_LeagueFP);
    bool insertPlayerToLeague(Player *playr, string nameLeague_Fp);
    bool playeralreadyexsist(Player *player, string nameLeague_Fp);




private:
    PlayerList leagueList;
    string nameFp_League;
    string nameLeagueAllFp;
    string nameLeague_MammalFp;
    string nameLeague_FishFp;
    string nameLeague_BugFp;
    string nameLeague_DogFp;
    string nameLeague_CatFp;
    string nameLeague_DolphinFp;
    string nameLeague_GrasshopperFp;
    string nameLeague_SharkFp;
    string nameLeague_WaspFp;
    string nameLeague_BarracudaFp;
    string nameLeague_AntFp;
};


#endif //REVERSI_GAME_LEAGUE_H
