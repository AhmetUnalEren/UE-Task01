// Fill out your copyright notice in the Description page of Project Settings.


#include "Bacteria.h"


void ABacteria::Division()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hello World!"));
	float Rad =  FMath::Pow(FMath::Pow(GetActorScale().X,3)/4.0f, 1.0f/3.0f);
	if (GetActorScale().X>=0.2f)
	{
		FTransform SpawnTM=FTransform(GetActorRotation(),GetActorLocation(), FVector(Rad,Rad,Rad));
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		for (int i=0;i<4;i++)
		{
			GetWorld()->SpawnActor<AActor>(this->GetClass(),SpawnTM,SpawnParams);
		}
	}
	
	
}

void ABacteria::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle_Division,this,&ABacteria::Division,5.0f);
}
