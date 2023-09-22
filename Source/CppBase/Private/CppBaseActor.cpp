// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	// Почему мои акторы спавнятся не по этим координатам?
	InitialLocation = FVector(FMath::FRandRange(-100.0f, 100.0f), FMath::FRandRange(0.0f, 350.0f), 0.0f);
}

// Расчет траектории синуса
/*
	Честно говоря, я ни че не понимаю...
	в задании было сказано, метод должен быть: void SinMovement() - с ним я вообще ни че сделать не смог! ((
*/
float ACppBaseActor::SinMovement(const float z)
{
	UWorld* World = GetWorld();

	// множитель для прыжка 0...1
	// Почему FMath::Sin, а не просто sin? Работает также...
	float multJump = (FMath::Sin(Frequency * World->GetTimeSeconds()) + 1.0) / 2;

	return (Amplitude * multJump + z);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
