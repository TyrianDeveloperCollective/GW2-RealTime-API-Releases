# GW2 RealTime API - RTAPI
RTAPI provides real-time information about Guild Wars 2.
## Features
- Client Info
- Instance Info
- Group Info
- Character Info
- Camera Info

Anything missing? Please open an issue and it may be added in a future update.

## Using RTAPI
The primary object `struct RealTimeData` can be obtained using Nexus' DataLink API. The name of the data link is defined in the header `RTAPI`.

As Nexus allows for hot-loading and as such RTAPI can be unloaded at runtime, for example to be updated, the addon has to check that the data has not gone stale.
You can do this by checking if `RTAPI->GameBuild == 0`.
If the Game Build is set to 0, RTAPI was unloaded.

It is recommended to also listen to `EV_ADDON_LOADED` and `EV_ADDON_UNLOADED` events, and checking against the signature of RTAPI to automatically switch back to using the realtime data.
The signature of the addon is also defined in the API header `RTAPI_SIG`.

Real-time group data is individually sent to any addon that loaded after RTAPI.

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
