// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "K2Node.h"

#include "Textures/SlateIcon.h"

#include "K2Node_LowEntry_CreateJsonArray.generated.h"


UCLASS(MinimalAPI)
class UK2Node_LowEntry_CreateJsonArray : public UK2Node
{
	GENERATED_UCLASS_BODY()

	/** The number of input pins to generate for this node */
	UPROPERTY()
	int32 NumInputs;

public:
	LOWENTRYJSONEDITOR_API void AddInputPin();
	LOWENTRYJSONEDITOR_API void RemoveInputPin(UEdGraphPin* Pin);

	LOWENTRYJSONEDITOR_API UEdGraphPin* GetArrayOutputPin() const;
	LOWENTRYJSONEDITOR_API UEdGraphPin* GetObjectOutputPin() const;

public:
	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	virtual FText GetTooltipText() const override;

	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override
	{
		static FSlateIcon Icon("EditorStyle", "GraphEditor.MakeArray_16x");
		return Icon;
	}
	// End of UEdGraphNode interface

	// UK2Node interface
	virtual bool IsNodePure() const override;
	virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual int32 GetNodeRefreshPriority() const override { return EBaseNodeRefreshPriority::Normal; }
	// End of UK2Node interface


protected:
	friend class FKismetCompilerContext;
};
