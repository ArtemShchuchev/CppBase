// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = FVector(FMath::FRandRange(-100.0f, 100.0f), FMath::FRandRange(0.0f, 350.0f), 0.0f);
}

// Расчет траектории синуса
void ACppBaseActor::SinMovement()
{
	InitialLocation.Z += Amplitude * FMath::Sin(Frequency * FDateTime::Now().GetTicks());
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



/*
void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase класс ошибся"));
	UE_LOG(LogTemp, Error, TEXT("CppBase Ай-ай-ай!"));
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));
	UE_LOG(LogTemp, Display, TEXT("currentHealth: %f"), currentHealth);
	
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s%d"), *PlayerName, id);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), isAlive);
}
*/

