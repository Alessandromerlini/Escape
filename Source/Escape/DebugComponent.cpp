// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugComponent.h"

// Sets default values for this component's properties
UDebugComponent::UDebugComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDebugComponent::BeginPlay()
{
	Super::BeginPlay();

	FString nome=GetOwner()->GetName();
	FString Posizione = GetOwner()->GetActorLocation().ToString();


	UE_LOG(LogTemp, Warning, TEXT("io sono %s in posizione %s"), *nome, *Posizione);








	// ...
	
}


// Called every frame
void UDebugComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	





	// ...
}

