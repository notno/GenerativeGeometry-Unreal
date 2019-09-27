#include "SpawnableMesh.h" // Wants to be first
//#include <iostream>
//#include <EngineGlobals.h>
//#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
ASpawnableMesh::ASpawnableMesh()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;

	ggGear3D = nullptr;

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
	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);
	FQuat QuatRotation = FQuat(NewRotation);
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

}

GenerativeGeometry::Gear3D* ASpawnableMesh::last_ggGear3D = nullptr;

void ASpawnableMesh::SpawnMesh(FVector Location) {

	ggGear3D = new GenerativeGeometry::Gear3D(Location, last_ggGear3D);
	UE_LOG(LogTemp, Warning, TEXT("PreviousRadius: %f"), ggGear3D->GetRadius() );
	last_ggGear3D = ggGear3D;
	ggGear3D->Generate();

	RollValue = ggGear3D->GetRotationFactor();

	TArray<FVector2D> UV0{};
	TArray<FProcMeshTangent> tangents{};
	TArray<FLinearColor> vertexColors{};
	for (auto v : ggGear3D->GetVertices()) {
		UV0.Add(FVector2D(0, 0));
		tangents.Add(FProcMeshTangent());
		vertexColors.Add(FLinearColor(.75, .75, .75, 1.0));
	}

	mesh->CreateMeshSection_LinearColor(0, ggGear3D->GetVertices(), ggGear3D->GetTriangleVertexIndices(), ggGear3D->GetNormals(), UV0, vertexColors, tangents, false);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

