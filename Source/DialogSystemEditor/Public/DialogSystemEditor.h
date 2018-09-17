// Copyright 2017 Krivosheya Mikhail. All Rights Reserved.
#pragma once


#include "ModuleManager.h"
#include "Developer/AssetTools/Public/AssetTypeCategories.h"

DECLARE_LOG_CATEGORY_EXTERN(DialogModuleLog, All, Warning)

class FDialogSystemEditorModule : public IModuleInterface
{
public:
	EAssetTypeCategories::Type AssetCategory;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedRef<class SDockTab> SpawnStoryKeyTab(const class FSpawnTabArgs&);
};