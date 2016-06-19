// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#define SLOG(message, textColor, ...) GEngine->AddOnScreenDebugMessage(-1, 5.f, textColor, FString::Printf(TEXT(message), __VA_ARGS__))
#define SLOG(message, ...) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT(message), __VA_ARGS__))

