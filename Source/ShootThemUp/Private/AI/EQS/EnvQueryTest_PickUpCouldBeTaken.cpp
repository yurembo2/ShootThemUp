// ShootThemUpGame, All Rights Reserved


#include "AI/EQS/EnvQueryTest_PickUpCouldBeTaken.h"
#include "Pickups/STUBasePickup.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_ActorBase.h"


 UEnvQueryTest_PickUpCouldBeTaken::UEnvQueryTest_PickUpCouldBeTaken(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
     Cost = EEnvTestCost::Low;
     ValidItemType = UEnvQueryItemType_ActorBase::StaticClass();
     SetWorkOnFloatValues(false);
 }

void UEnvQueryTest_PickUpCouldBeTaken::RunTest(FEnvQueryInstance &QueryInstance) const
{
     UObject *DataOwner = QueryInstance.Owner.Get();
     BoolValue.BindData(DataOwner, QueryInstance.QueryID);
     bool WantsBeTakable = BoolValue.GetValue();

     for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
     {
         AActor *ItemActor = GetItemActor(QueryInstance, It.GetIndex());
         const auto PickupActor = Cast<ASTUBasePickup>(ItemActor);
         if (!PickupActor)
             continue;
         const auto CouldBeTaken = PickupActor->CouldBeTaken();
         It.SetScore(TestPurpose, FilterType, CouldBeTaken, WantsBeTakable);
     }
}
