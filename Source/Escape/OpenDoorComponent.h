// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorComponent();


	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "opendoor")
	UStaticMeshComponent* AntaDaAprire;

	UPROPERTY(EditAnyWhere, Category = "opendoor")
	AActor* Attivatore;// memorizzerò il trigger volume

	UPROPERTY(EditAnyWhere, Category = "opendoor")
	AActor* Chiave; // memorizzero l'oggetto che entrato nel volume apre la porta

	bool bClose = true;
	FRotator StartRotation;








protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor(float TD);

	void CloseDoor(float TD);

	UPROPERTY(EditAnywhere)
	float OpenDeg;




public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
