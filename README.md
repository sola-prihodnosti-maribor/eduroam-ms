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

It is not required to donate, but it certainly doesn't hurt to do so. Please, keep the spirit up and running and donate. Thanks.

<a href='http://www.pledgie.com/campaigns/18239'><img alt='Click here to lend your support to: eduroam-ms and make a donation at www.pledgie.com !' src='http://www.pledgie.com/campaigns/18239.png?skin_name=chrome' border='0' /></a>