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

	че то накодил с методом ниже, впринципе как то работает, но 
	хотелось бы знать - как правильно. Из лекций и презентаций ни че не понятно,
	(да и еще "Супер" шрифт) как это собирается. Поэтому сделал как понял, что то в С++,
	что то в Блюпринтах.
*/
double ACppBaseActor::SinMovement(const float time)
{
	// множитель для прыжка 0...1
	// Почему FMath::Sin, а не просто sin? Работает также...
	float multJump = (FMath::Sin(Frequency * time) + 1.0) / 2;

	return (Amplitude * multJump + InitialLocation.Z);
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
	
	
	//int64 tick = FDateTime::Now().GetSecond();
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::SanitizeFloat(wholeSin), true, FVector2D(2.0f, 2.0f));
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::FromInt(tick), true, FVector2D(2.0f, 2.0f));
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, InitialLocation.ToCompactString(), true, FVector2D(2.0f, 2.0f));
}
*/

