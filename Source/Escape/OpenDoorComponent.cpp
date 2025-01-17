// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoorComponent.h"

// Sets default values for this component's properties
UOpenDoorComponent::UOpenDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorComponent::BeginPlay()
{
	Super::BeginPlay();
	Chiave = GetWorld()->GetFirstPlayerController()->GetPawn();
	StartRotation = AntaDaAprire->GetComponentRotation();

	



  



}

void UOpenDoorComponent::OpenDoor(float TD)
{

	FRotator ActualRot = AntaDaAprire->GetComponentRotation();

	if (ActualRot.Yaw > StartRotation.Yaw - OpenDeg)
	{
		ActualRot.Yaw -= OpenDeg * TD;
		AntaDaAprire->SetWorldRotation(ActualRot);
	}
	else bClose = false;

}


void UOpenDoorComponent::CloseDoor(float TD)
{

	FRotator ActualRot = AntaDaAprire->GetComponentRotation();

	if (ActualRot.Yaw < StartRotation.Yaw)
	{
		ActualRot.Yaw += OpenDeg * TD;
		AntaDaAprire->SetWorldRotation(ActualRot);
	}
	else bClose = true;



	



}


// Called every frame
void UOpenDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	if (!Chiave || !Attivatore) return;

	if (Attivatore->IsOverlappingActor(Chiave))
	{
		if (bClose) OpenDoor(DeltaTime);
	}
	else
	{
		if (!bClose) CloseDoor(DeltaTime);
	}

	






	

	
	


	

	






}

