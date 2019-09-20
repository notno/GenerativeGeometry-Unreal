// Fill out your copyright notice in the Description page of Project Settings.
#include "CircleMesh.h"
#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SpawnCircle();
	// ...
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnCircle();
	// ...
	
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UFUNCTION(BlueprintCallable)
void UMyActorComponent::SpawnCircle()
{
	if (ToSpawn)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			FRotator rotator(0.0f, 0.0f, 0.0f);
			FVector Location(0, 0, 0);
			for (int i = 0; i < 5; i++) {
				//FVector Location(1500,0,400);
				Location.Y += 100 * i;
				world->SpawnActor<ACircleMesh>(Location, rotator, spawnParams);
			}
		}
	}
}
