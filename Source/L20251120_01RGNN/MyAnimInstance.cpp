// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyTPC.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "KismetAnimationLibrary.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	ACharacter* Character = Cast<AMyTPC>(TryGetPawnOwner());
	if (Character)
	{
		GroundSpeed = Character->GetCharacterMovement()->Velocity.Size2D();

		Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetCharacterMovement()->Velocity, Character->GetActorRotation());
	}
	
}

void UMyAnimInstance::AnimNotify_SkeletonNotify()
{
}
