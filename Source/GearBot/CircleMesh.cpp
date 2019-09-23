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
	mesh->bUseAsyncCooking = true;

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

	auto c = GenerativeGeometry::Circle(GenerativeGeometry::vec3{ 0.0, 0.0, 0.0 }, 10.0, 16);
	c.Draw();

	cout << "c.GetVertices().size() " << c.GetVertices().size() << endl;

	TArray<FVector> vertices;
	for (auto v : c.GetVertices()) {
		FVector newV;
		newV.X = v.x;
		newV.Y = v.y;
		newV.Z = v.z;
		vertices.Add(newV);
	}

	std::cout << "vertices.Num(): "  << vertices.Num() << std::endl;

	TArray<FVector> normals;
	for (auto n : c.GetNormals()) {
		FVector newN;
		newN.X = n.x;
		newN.Y = n.y;
		newN.Z = n.z;
		normals.Add(newN);
	}
	
	TArray<int32> triangles;
	for (auto t : c.GetTriangleVerts()) {
		triangles.Add(t);
	}

	TArray<FVector2D> UV0{};
	TArray<FProcMeshTangent> tangents{};
	TArray<FLinearColor> vertexColors{};
	for (auto v : vertices) {
		UV0.Add(FVector2D(0, 0));
		tangents.Add(FProcMeshTangent());
		vertexColors.Add(FLinearColor(.75, .75, .75, 1.0));
	}

	mesh->CreateMeshSection_LinearColor(0, vertices, triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}
