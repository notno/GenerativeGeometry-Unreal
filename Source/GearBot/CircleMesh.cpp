// Fill out your copyright notice in the Description page of Project Settings.

#include "CircleMesh.h"
#include <vector>

// Sets default values
ACircleMesh::ACircleMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;
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

	auto c = GenerativeGeometry::Circle(GenerativeGeometry::vec3{ 0.0, 0.0, 0.0 }, 10.0, 16);

	TArray<FVector> vertices;
	for (auto v : c.Vertices) {
		FVector newV;
		newV.X = v.x;
		newV.Y = v.y;
		newV.Z = v.z;
		vertices.Add(newV);
	}

	TArray<FVector> normals;
	for (auto n : c.Normals) {
		FVector newN;
		newN.X = n.x;
		newN.Y = n.y;
		newN.Z = n.z;
		normals.Add(newN);
	}
	
	TArray<int32> triangles;
	for (auto t : c.Triangles) {
		triangles.Add(t);
	}

	TArray<FVector2D> UV0{};
	TArray<FProcMeshTangent> tangents{};
	TArray<FLinearColor> vertexColors{};

	mesh->CreateMeshSection_LinearColor(0, vertices, triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}
