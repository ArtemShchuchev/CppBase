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
	// ������ ��� ������ ��������� �� �� ���� �����������?
	InitialLocation = FVector(FMath::FRandRange(-100.0f, 100.0f), FMath::FRandRange(0.0f, 350.0f), 0.0f);
}

// ������ ���������� ������
/*
	������ ������, � �� �� �� �������...
	� ������� ���� �������, ����� ������ ����: void SinMovement() - � ��� � ������ �� �� ������� �� ����! ((

	�� �� ������� � ������� ����, ��������� ��� �� ��������, �� 
	�������� �� ����� - ��� ���������. �� ������ � ����������� �� �� �� �������,
	(�� � ��� "�����" �����) ��� ��� ����������. ������� ������ ��� �����, ��� �� � �++,
	��� �� � ����������.
*/
double ACppBaseActor::SinMovement(const float time)
{
	// ��������� ��� ������ 0...1
	// ������ FMath::Sin, � �� ������ sin? �������� �����...
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
	UE_LOG(LogTemp, Warning, TEXT("CppBase ����� ������"));
	UE_LOG(LogTemp, Error, TEXT("CppBase ��-��-��!"));
	
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

