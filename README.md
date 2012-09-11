eduroam-ms
==========

Extension for Microsoft NPS adding attributes for compatibility with eduroam.si.

## Prerequisites

* Microsoft Windows Server 2008 R2 _or_ Microsoft Windows Server 2012
* Microsoft NPS

## Usage

1. Copy DLL into C:\Windows\System32 (or any other folder in your PATH).
2. Add a new entry "AuthorizationDLLs" of type REG_MULTI_SZ into HKLM\SYSTEM\CurrentControlSet\services\AuthSrv\Parameters.
3. Set or update value of "AuthorizationDLLs" to FILENAME.dll (replace filename with the name of your compiled DLL).

## Donations

http://www.pledgie.com/campaigns/18239
