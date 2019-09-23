// Fill out your copyright notice in the Description page of Project Settings.

#include "CircleMesh.h"
#include <iostream>
#include <vector>


using std::cout;
using std::endl;

// Sets default values
ACircleMesh::ACircleMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	//mesh->bUseAsyncCooking = true;

	std::cout.rdbuf(&Stream);
}

// Called when the game starts or when spawned
void ACircleMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACircleMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void ACircleMesh::PostActorCreated()
{
	Super::PostActorCreated();
	CreateCircle();
}

// This is called when actor is already in level and map is opened
void ACircleMesh::PostLoad()
{
	Super::PostLoad();
	CreateCircle();
}

void ACircleMesh::CreateCircle() {
	
	GenerativeGeometry::Gear2D c( FVector(0.0, 0.0, 0.0), 55.0, 32 );
	c.Draw();

	cout << "c.GetNumVerts() " << c.GetNumVerts() << endl;

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


