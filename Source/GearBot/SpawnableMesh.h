#pragma once

//#include <iostream>
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


	double PitchValue = 0.f;
	double YawValue = 0.f;
	double RollValue = 0.f;

public:
	GenerativeGeometry::Gear3D* ggGear3D;
	static GenerativeGeometry::Gear3D* last_ggGear3D;

	// Sets default values for this actor's properties
	ASpawnableMesh();
	~ASpawnableMesh() {
		// delete(ggGear3D);
		// ggGear3D = nullptr;
	}

	void SpawnMesh(FVector Location);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
