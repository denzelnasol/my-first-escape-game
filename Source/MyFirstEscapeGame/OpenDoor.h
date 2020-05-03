// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFIRSTESCAPEGAME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();

	// Tracks whether sound has been played
	bool OpenDoorSound = true;
	bool CloseDoorSound = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	float CurrentYaw;
	float InitialYaw;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 100.f;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoors = 50.f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 1.f;
	
	UPROPERTY(EditAnywhere)
	float DoorClosedDelay = 1.f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
