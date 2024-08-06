// ShootThemUpGame, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "STUPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
    void SetTeamID(int32 ID)
    {
        TeamID = ID;
    }
    int32 GetTeamID() const
    {
        return TeamID;
    }

    void SetTeamColor(const FLinearColor &Color)
    {
        TeamColor = Color;
    }
    FLinearColor GetTeamColor() const
    {
        return TeamColor;
    }
    void SetKillsNum(const int32 num)
    {
        KillsNum = num;
    }
    int32 GetKillsNum()
    {
        return KillsNum;
    }
    void SetDeathsNum(const int32 num)
    {
        DeathsNum = num;
    }
    int32 GetDeathNum()
    {
        return DeathsNum;
    }

    void AddKill()
    {
        ++KillsNum;
    }
    void AddDeath()
    {
        ++DeathsNum;
    }

    void LogInfo();
	
private:
    int32 TeamID;
	FLinearColor TeamColor;

    int32 KillsNum = 0;
    int32 DeathsNum = 0;
};
