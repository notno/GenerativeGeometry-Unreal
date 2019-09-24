#pragma once

#include <iostream>
#include "GG_Gear3D.h"

#include "ProceduralMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnableMesh.generated.h"

UCLASS()
class GEARBOT_API ASpawnableMesh : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;
	
public:	
	// Sets default values for this actor's properties
	ASpawnableMesh();

	void SpawnMesh(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "nwr")
	static void SpawnThing(FVector Location);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
