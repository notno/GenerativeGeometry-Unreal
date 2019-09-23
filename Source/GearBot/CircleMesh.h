#pragma once

#include "LStream.h"
#include "GG_Geometry.h"
#include "GG_Circle.h"
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "CircleMesh.generated.h"

UCLASS()
class GEARBOT_API ACircleMesh : public AActor
{
	GENERATED_BODY()


private:
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* mesh;

public:
	// Sets default values for this actor's properties
	ACircleMesh();

	LStream Stream;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
	void PostActorCreated() override;

	// This is called when actor is already in level and map is opened
	void PostLoad() override;

	void CreateCircle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};