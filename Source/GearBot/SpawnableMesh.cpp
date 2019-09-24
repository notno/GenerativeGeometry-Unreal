#include <iostream>
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "SpawnableMesh.h"
// Sets default values
ASpawnableMesh::ASpawnableMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;

	SpawnMesh(GetTransform().GetLocation());
}

// Called when the game starts or when spawned
void ASpawnableMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnableMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnableMesh::SpawnThing(FVector Location){
	UE_LOG(LogTemp, Warning, TEXT("UGHGHGH"));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

void ASpawnableMesh::SpawnMesh(FVector Location) {

	GenerativeGeometry::Gear3D c(Location, 55.0, 17);
	c.Draw();

	TArray<FVector2D> UV0{};
	TArray<FProcMeshTangent> tangents{};
	TArray<FLinearColor> vertexColors{};
	for (auto v : c.GetVertices()) {
		UV0.Add(FVector2D(0, 0));
		tangents.Add(FProcMeshTangent());
		vertexColors.Add(FLinearColor(.75, .75, .75, 1.0));
	}

	mesh->CreateMeshSection_LinearColor(0, c.GetVertices(), c.GetTriangleVerts(), c.GetNormals(), UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

