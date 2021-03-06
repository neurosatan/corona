// ----------------------------------------------------------------------------
// 
// ReadOnlyCoronaLuaEventProperties.cpp
// Copyright (c) 2014 Corona Labs Inc. All rights reserved.
// 
// Reviewers:
// 		Joshua Quick
//
// ----------------------------------------------------------------------------

#include "pch.h"
#include "ReadOnlyCoronaLuaEventProperties.h"
#include "CoronaLuaEventProperties.h"
#include "ICoronaBoxedData.h"


namespace CoronaLabs { namespace Corona { namespace WinRT {

#pragma region Consructors/Destructors
ReadOnlyCoronaLuaEventProperties::ReadOnlyCoronaLuaEventProperties(CoronaLuaEventProperties^ properties)
:	fProperties(properties)
{
	if (nullptr == properties)
	{
		throw ref new Platform::NullReferenceException();
	}
}

#pragma endregion


#pragma region Public Methods/Properties
ICoronaBoxedData^ ReadOnlyCoronaLuaEventProperties::Get(Platform::String^ name)
{
	return fProperties->Get(name);
}

bool ReadOnlyCoronaLuaEventProperties::Contains(Platform::String^ name)
{
	return fProperties->Contains(name);
}

int ReadOnlyCoronaLuaEventProperties::Count::get()
{
	return fProperties->Count;
}

Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<Platform::String^, ICoronaBoxedData^>^>^ ReadOnlyCoronaLuaEventProperties::First()
{
	return fProperties->First();
}

#pragma endregion


#pragma region Internal Methods
CoronaLabs::WinRT::IOperationResult^ ReadOnlyCoronaLuaEventProperties::PushTo(lua_State *luaStatePointer)
{
	return fProperties->PushTo(luaStatePointer);
}

#pragma endregion

} } }	// namespace CoronaLabs::Corona::WinRT
