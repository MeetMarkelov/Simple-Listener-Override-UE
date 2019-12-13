// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SimpleListenerOverrideRuntime.h"

DEFINE_LOG_CATEGORY(LogSimpleListenerOverride)

void FSimpleListenerOverrideRuntime::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSimpleListenerOverrideRuntime::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
	
IMPLEMENT_MODULE(FSimpleListenerOverrideRuntime, SimpleListenerOverrideRuntime)