#pragma once

#include "CoreMinimal.h"

#define RERURN_IF(BOOL_VALUE) if(BOOL_VALUE) return;
#define RETURN_NULL_IF(BOOL_VALUE) if(BOOL_VALUE) return nullptr;
#define RETURN_ZERO_IF(BOOL_VALUE) if(BOOL_VALUE) return 0;
#define RETURN_ANY_IF(BOOL_VALUE, ANY) if(BOOL_VALUE) return ANY;

DECLARE_LOG_CATEGORY_EXTERN(MU_LOG, Log, All);

#define MU_LOG_INFO(INFO, ...) UE_LOG(MU_LOG, Log, TEXT(INFO), ##__VA_ARGS__);
#define MU_LOG_ERROR(INFO, ...) UE_LOG(MU_LOG, Error, TEXT(INFO), ##__VA_ARGS__);
#define MU_LOG_WARNING(INFO, ...) UE_LOG(MU_LOG, Warning, TEXT(INFO), ##__VA_ARGS__);
