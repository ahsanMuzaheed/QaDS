#pragma once

#include "EdGraph/EdGraphNode.h"
#include "DialogNodes.h"
#include "DialogEditorNodes.generated.h"

class UEdGraphPin;

class DIALOGSYSTEMEDITOR_API FNodePropertyObserver
{
public:
	virtual void OnPropertyChanged(class UEdGraphNode* Sender, const FName& PropertyName) = 0;
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDdialogEdGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdGraphPin* InputPin;
	UEdGraphPin* OutputPin;

	UPROPERTY()
	UDialogNode* CompileNode;

	TArray<UDdialogEdGraphNode*> GetChildNodes();
	virtual int GetOrder() const;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

	TSharedPtr<FNodePropertyObserver> PropertyObserver;
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDialogRootEdGraphNode : public UDdialogEdGraphNode
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual bool CanUserDeleteNode() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDialogPhraseEdGraphNode : public UDdialogEdGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDialogPhraseInfo Data;

	UDialogPhraseEdGraphNode();
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDialogPhraseEdGraphNode_Player : public UDialogPhraseEdGraphNode
{
	GENERATED_BODY()

public:
	UDialogPhraseEdGraphNode_Player();
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDialogSubGraphEdGraphNode : public UDdialogEdGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDialogAsset* TargetDialog;

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UDialogElseIfEdGraphNode : public UDdialogEdGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDialogElseIfCondition> Conditions;

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
};