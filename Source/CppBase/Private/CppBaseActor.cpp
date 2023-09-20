// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

int ACppBaseActor::count = 0;

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

	//ShowInformation();
	ShowActorInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation()
{
	// � ���� ������� ����� �� ���������? (
	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase ����� ������"));
	UE_LOG(LogTemp, Error, TEXT("CppBase ��-��-��!"));

	/*
		������ ��� ����� � ��� �� ����� � VS,
		����� ������� ������� UE, � ����� ���������
		��������� � ��� ����� ������ UE ��� ���� ������
		����������� ��������� ��� �������� UE?
	*/
	
	UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));
	UE_LOG(LogTemp, Display, TEXT("currentHealth: %f"), currentHealth);
}

/*
	�� ���� ��������� ��������� ����� �������,
	��� �������� (Instance name),
	�� ��� ����� �������� ��� ������������)
*/
void ACppBaseActor::ShowActorInformation()
{
	id = count;
	++count;
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s%d"), *PlayerName, id);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), enemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), isAlive);
}

