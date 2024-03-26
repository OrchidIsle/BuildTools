#include "BuildInfo.h"
#include "Misc/ConfigCacheIni.h"

FString UBuildInfo::GetBuildID()
{
    static FString BuildID;
    // Only read once
    if (BuildID.IsEmpty())
    {
        GConfig->GetString(
            TEXT("BuildInfo"),
            TEXT("BuildID"),
            BuildID,
            FPaths::ProjectConfigDir() / "BuildInfo.ini"
        );
    }

    if (BuildID.IsEmpty())
    {
        BuildID = "NoBuildID";
    }
    return BuildID;
}
