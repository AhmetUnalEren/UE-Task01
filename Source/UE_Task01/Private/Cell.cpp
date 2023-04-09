// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"
#include "Components/SphereComponent.h"
// Sets default values
ACell::ACell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ColliderComp= CreateDefaultSubobject<USphereComponent>("ColliderComp");
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	ColliderComp->SetupAttachment(RootComponent);
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
	
}

// Called every frame
void ACell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

