# GW2 RealTime API - RTAPI
RTAPI provides real-time information about Guild Wars 2.
Additionally, running RTAPI fixes the long standing "bug", that the Mumble API delivers "laggy" player positions.

# Terms of Service Disclaimer
This API provides more information than the game client normally exposes.
Any implementation build on top of it still has to ensure that it is within the official [Third Party Program Policy](https://help.guildwars2.com/hc/en-us/articles/360013625034-Policy-Third-Party-Programs).

## Features
- Client Info
- Instance Info
- Group Info
- Character Info
- Camera Info

Anything missing? Please open an issue and it may be added in a future update.

## Using RTAPI
The primary object `struct RealTimeData` can be obtained using Nexus' DataLink API. The name of the data link is defined in the header `DL_RTAPI`.

As Nexus allows for hot-loading and as such RTAPI can be unloaded at runtime, for example to be updated, the addon has to check that the data has not gone stale.
You can do this by checking if `RTAPI->GameBuild == 0`.
If the Game Build is set to 0, RTAPI was unloaded.

It is recommended to also listen to `EV_ADDON_LOADED` and `EV_ADDON_UNLOADED` events, and checking against the signature of RTAPI to automatically switch back to using the realtime data.
The signature of the addon is also defined in the API header `RTAPI_SIG`.

### Example implementation (Addon load events)
```cpp
void OnAddonLoaded(int* aSignature)
{
  if (!aSignature) { return; }
  
  if (*aSignature == RTAPI_SIG)
  {
    G::RTAPI = (RTAPI::RealTimeData*)G::APIDefs->DataLink.Get(DL_RTAPI);
  }
}
void OnAddonUnloaded(int* aSignature)
{
  if (!aSignature) { return; }

  if (*aSignature == RTAPI_SIG)
  {
    G::RTAPI = nullptr;
  }
}
```

### Group Data
Real-time group data is individually sent to any addon that loaded after RTAPI.

The following events are provided. The payload is `GroupMember*`.
```cpp
#define EV_RTAPI_GROUP_MEMBER_JOINED  "RTAPI_GROUP_MEMBER_JOINED"
#define EV_RTAPI_GROUP_MEMBER_LEFT    "RTAPI_GROUP_MEMBER_LEFT"
#define EV_RTAPI_GROUP_MEMBER_UPDATED "RTAPI_GROUP_MEMBER_UPDATED"
```
