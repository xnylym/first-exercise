// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UObject/ObjectMacros.h"
#include "Drone.generated.h"

UCLASS()
class FIRST_EXERCISE_API ADrone : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADrone();

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* OutCollision;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Paddle1;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Paddle2;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Paddle3;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Paddle4;

	UPROPERTY(VisibleAnywhere)
	class UPhysicsThrusterComponent* UpThruster;

	UPROPERTY(VisibleAnywhere)
	class UPhysicsThrusterComponent* ForwardThruster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Init")
	float LiftAcc = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float LiftThrusterMax = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float ForwardAcc = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float ForwardThrusterMax = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float TurnStrength = 500000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float PaddleRotateSpeed = 500.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void Lift(float val);

	UFUNCTION()
	void Forward(float val);

	UFUNCTION()
	void Turn(float val);

	TArray<UStaticMeshComponent*> Paddles;

	void RotatePaddle(float Delta);
};
