// Fill out your copyright notice in the Description page of Project Settings.

#include "Cell.h"
#include "Components/SphereComponent.h"
// Sets default values
ACell::ACell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SphereComponent=CreateDefaultSubobject<USphereComponent>("SphereComponent");
	MeshComponent->SetEnableGravity(false);
	MeshComponent->SetLinearDamping(0.0f);
	MeshComponent->SetAngularDamping(0.0f);
	MeshComponent->SetSimulatePhysics(true);
	RootComponent = MeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere"));
	if (SphereMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(SphereMesh.Object);
	}
}

// Called when the game starts or when spawned
void ACell::BeginPlay()
{
	Super::BeginPlay();
	// Calculate the direction and magnitude of the impulse
	FVector ImpulseDirection =FVector3d(-800.0f,-500.0f,0.0f) ; // Set the impulse direction
	float ImpulseMagnitude = 1.0f;  // Set the impulse magnitude

	// Apply the impulse to the object
	MeshComponent->AddImpulse(ImpulseMagnitude * ImpulseDirection, NAME_None, true);
}

// Called every frame
void ACell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


