// Copyright by Hungne

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, meta = (BindWidgetOptional))
	UProgressBar* HealthBar;
	
	void SetHealthBarPercent(float NewPercent);
};
